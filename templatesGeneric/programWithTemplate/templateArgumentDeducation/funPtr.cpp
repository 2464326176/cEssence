/*
 * @Author: yh
 * @Date: 2022/6/1 0:08
 * @Description: 
 * @FilePath: funPtr.cpp
 */

#include <iostream>
#include <string>
using namespace std;

template<typename T>
int compare(const T &a, const T &b) {
    cout << "a " << a << " b: " << b << endl;
}

int (*pf1)(const int &, const int &) = compare;
int (*pf2)(const string &, const string &);

void func(int(*)(const int &a, const int &b));
void func(int(*)(const string &a, const string &b));

int main() {
    //func(compare); // 无法获知使用那个实例
    pf1(1, 2);
    pf2 = &compare;
    pf2("hello", "world!!!");
    int a = 2, b = 3;
    func(compare<int>);
    
    return 0;
}