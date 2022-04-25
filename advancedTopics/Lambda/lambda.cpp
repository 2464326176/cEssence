//**************************
// Author:  yh
// Time:    2021/12/16
//**************************

#include "lambda.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>



/*
 1   2   3       4         5
[=] () mutable throw() -> int
{
    int n = x + y;
    x = y;
    y = n;
    return n;
}6

1.捕获子句
    []  空方括号不导入任何外部变量。
    [=] =以值传递的方式导入所有外部变量；
    [&] &以引用传递的方式导入所有外部变量；
    [val1,val2,...] 值传递导入val1、val2，多个变量之间没有先后次序；
    [&val1,&val2,...] 引用传递导入 val1、val2等指定的外部变量，多个变量之间没有前后次序；
    [val,&val2,...]	以上2种方式还可以混合使用，变量之间没有前后次序。
    [=,&val1,...]	表示除val1以引用传递的方式导入外，其它外部变量都以值传递的方式导入。
    [this] 表示以值传递的方式导入当前的this指针。
2.参数列表 可有可无.
3.可变规范 可有可无.
4.异常规范 可有可无.
5.尾随-返回类型 可有可无.
6.lambda体
*/
/*
struct S { void f(int i); };
void S::f(int i) {
    [&, i]{};      // OK
    //[&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    //[i, i]{};      // ERROR: i repeated
}

template<class... Args>
void f(Args... args) {
    auto x = [args...] { return g(args...); };
    x();
}
*/
using namespace std;

void absSort(float* x, unsigned n) {
    std::sort(x, x + n,
              [](float a, float b) {
                  return (std::abs(a) < std::abs(b));
              });
}

template <typename C> void print(const string& s, const C& c) {
    cout << s;
    for (const auto& e : c) {
        cout << e << " ";
    }
    cout << endl;
}

void fillVector(vector<int>& v)
{
    // A local static variable.
    static int nextValue = 1;

    // The lambda expression that appears in the following call to
    // the generate function modifies and uses the local static
    // variable nextValue.
    generate(v.begin(), v.end(), [] { return nextValue++; });
    //WARNING: this isn't thread-safe and is shown for illustration only
}

int main1()
{
    // The number of elements in the vector.
    const int elementCount = 9;

    // Create a vector object with each element set to 1.
    vector<int> v(elementCount, 1);

    // These variables hold the previous two elements of the vector.
    int x = 1;
    int y = 1;

    // Sets each element in the vector to the sum of the
    // previous two elements.
    generate_n(v.begin() + 2,
               elementCount - 2,
               [=]() mutable throw() -> int { // lambda is the 3rd parameter
                   // Generate current value.
                   int n = x + y;
                   // Update previous two values.
                   x = y;
                   y = n;
                   return n;
               });
    print("vector v after call to generate_n() with lambda: ", v);

    // Print the local variables x and y.
    // The values of x and y hold their initial values because
    // they are captured by value.
    cout << "x: " << x << " y: " << y << endl;

    // Fill the vector with a sequence of numbers
    fillVector(v);
    print("vector v after 1st call to fillVector(): ", v);
    // Fill the vector with the next sequence of numbers
    fillVector(v);
    print("vector v after 2nd call to fillVector(): ", v);
}

class FuncorClass {
public:
    explicit FuncorClass(int& evenCount) : m_evecCount(evenCount){}

    void operator()(int n) const {
        cout << n << (((n % 2) == 0) ? " is even" : " is odd") << endl;
    }
private:
    FuncorClass& operator=(const FuncorClass&);
    int& m_evecCount;
};
int main() {
    vector<int> v{4, 5, 6, 7};
    int evenCount = 0;
    /*
    for_each(v.begin(), v.end(),
             [&evenCount] (int n) {
         cout << n << (((n % 2) == 0) ? " is even" : " is odd") << endl;
    });
     */
    for_each(v.begin(), v.end(), FuncorClass(evenCount));
    return 0;
}








