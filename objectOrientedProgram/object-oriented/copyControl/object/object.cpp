/*
 * @Author: yh
 * @Date: 2022/9/11 20:39
 * @Description: 
 * @FilePath: object.cpp
 */

#include "object.h"

int main() {
    object obj0; // Ĭ�ϵĹ��캯��
    // object obj1(); �൱�ڶ�����һ������  object obj1(void);
    object obj2(1, "c++"); // �������Ĺ��캯��
    object obj3(obj2); //copy construct function
    object obj4 = obj2; // copy construct function
    object obj5 = {3, "java"}; // �������Ĺ��캯��
    object obj6 = object(4, "php"); // �������Ĺ��캯��
    
    object obj7;
    obj7 = obj6; // copy assign function ������ֵ����
    
    object obj8(std::move(obj7)); // move construct function �ƶ����캯��
    
    
    return 0;
}