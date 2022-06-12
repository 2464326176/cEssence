/*
 * @Author: yh
 * @Date: 2022/5/22 23:43
 * @Description: 
 * @FilePath: delegateConstruct.cpp
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class demo {
public:
    demo() = default;
    demo(int a, string str, vector<int> v) : x(a), s(str), v(v) {}
    demo(int a) : demo(a, "null", {}) {}
    demo(string s) : demo(0, s, {}) {}
    demo(vector<int> v) : demo(0, "null", v) {}
    void print() {
        printf("%d %s \n", x, s.c_str());
        for (auto &vv: v) {
            printf("%d ", vv);
        }
        printf("\n");
    }
private:
    // 成员初始化
    int x = 0;              // 赋值方式
    string s = "hello";     // 赋值方式
    vector<int> v{1, 2, 3}; // 花括号方式
};

int main() {
    demo d0;
    demo d1(1);
    demo d2("c++");
    demo d3(vector<int>{6, 9, 7, 8});
    demo d4(3, "java", vector<int>{8, 5, 2, 7});
    d0.print(); // 0 hello 1 2 3
    d1.print(); // 1 null
    d2.print(); // 0 c++
    d3.print(); // 0 null 6 9 7 8
    d4.print(); // 3 java 8 5 27
    return 0;
}
