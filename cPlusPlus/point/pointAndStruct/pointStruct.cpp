//**************************
// Author:  yh
// Time:    2022/2/27
//**************************

#include "pointStruct.h"
#include <iostream>
#include <cstring>

struct student {
    char name[10];
    int age;
} student, *studentPtr;


int main() {
    struct student *ptr;
    strncpy(student.name, "hello world!", 10 * sizeof(char));
    student.age = 10;
    studentPtr = &student;

    studentPtr->name, student.name;
    (*studentPtr).age, student.age;  // (*studentPtr).age �� studentPtr->age�ȼ�

    //ptr = student.name; // error ptr��ָ��ṹ�����͵�ָ�룬 ����ת����ptr�ĵ�ַ���Ͳ�ƥ��
    ptr = (struct student *)student.name;

    return 0;
}