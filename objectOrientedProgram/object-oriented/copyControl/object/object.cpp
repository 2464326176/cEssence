/*
 * @Author: yh
 * @Date: 2022/9/11 20:39
 * @Description: 
 * @FilePath: object.cpp
 */

#include "object.h"

int main() {
    object obj0; // 默认的构造函数
    // object obj1(); 相当于定义了一个函数  object obj1(void);
    object obj2(1, "c++"); // 带参数的构造函数
    object obj3(obj2); //copy construct function
    object obj4 = obj2; // copy construct function
    object obj5 = {3, "java"}; // 带参数的构造函数
    object obj6 = object(4, "php"); // 带参数的构造函数
    
    object obj7;
    obj7 = obj6; // copy assign function 拷贝赋值函数
    
    object obj8(std::move(obj7)); // move construct function 移动构造函数
    
    
    return 0;
}