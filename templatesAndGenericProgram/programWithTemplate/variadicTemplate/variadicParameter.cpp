/*
 * @Author: yh
 * @Date: 2022/6/1 23:31
 * @Description: 
 * @FilePath: variadicParameter.cpp
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

template<typename T, typename... Args>
void foo(const T &t, const Args &... rest) {
    printf("type parameter size: %d\n", sizeof...(Args));
    printf("function parameter size: %d\n", sizeof...(rest));
};

int main() {
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow?";
    
    foo(i, s, 42, d); // void foo(const int &, const string &, const int &, const double&)
    foo(s, 42, "hi"); // void foo(const string &, const int &, const char[3] &)
    foo(d, s); // void foo(const int &, const string &)
    foo("hi"); //void foo(const char[3] &)
    
    return 0;
}