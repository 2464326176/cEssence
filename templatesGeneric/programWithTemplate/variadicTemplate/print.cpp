/*
 * @Author: yh
 * @Date: 2022/6/1 23:57
 * @Description: 
 * @FilePath: print.cpp
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &... rest) {
    os << t << " "; // 打印第一个参数
    return print(os, rest...); // 递归打印
}

int main() {
    print(cout, 1, 2, 3, 4, 8);
    print(cout, 1, "hello world!!!");
    print(cout, "hi ", "hello world!!!");
    
    return 0;
}