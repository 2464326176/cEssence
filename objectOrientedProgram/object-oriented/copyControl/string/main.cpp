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
    
    String s0; // Ĭ�Ϲ��캯��
    String s1("hello"); // �������Ĺ��캯�� c���
    String s2(s0); // �������캯��
    String s3 = s1; // �������캯��
    String s4(text); // �������Ĺ��캯�� c���
    s2 = s1; // ������ֵ����
    
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