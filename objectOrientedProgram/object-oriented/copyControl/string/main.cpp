/*
 * @Author: yh
 * @Date: 2022/9/12 4:46
 * @Description: 
 * @FilePath: main.cpp
 */
#include "String.h"
#include <iostream>
#include <vector>

void foo(String x) {
    std::cout << x.c_str() << std::endl;
}

void bar(const String &x) {
    std::cout << x.c_str() << std::endl;
}

String baz() {
    String ret("world");
    return ret;
}

int test() {
    char text[] = "world";
    
    String s0; // 默认构造函数
    String s1("hello"); // 带参数的构造函数 c风格
    String s2(s0); // 拷贝构造函数
    String s3 = s1; // 拷贝构造函数
    String s4(text); // 带参数的构造函数 c风格
    s2 = s1; // 拷贝赋值函数
    
    foo(s1);
    bar(s1);
    foo("tem");
    bar("tem");
    String s5 = baz();
    
    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");
    
    for (const auto &s: svec) {
        std::cout << s.c_str() << std::endl;
    }
}

int main() {
    String str;
    String str1("hello");
    String str2("world");
    String str3(str1);
    String str4(std::move(str2));
    String str5 = str1;
    
    String str6, str7;
    str6 = str1; // copy construct
    str7 = std::move(str1); // move assign
    return 0;
}