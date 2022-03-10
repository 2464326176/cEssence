//**************************
// Author:  yh
// Time:    2022/2/27
//**************************

#include "pointStruct.h"
#include <iostream>
#include <cstring>

typedef struct Student {
    char name[10];
    int age;
    Student(char *name, int age) {
        strncpy(this->name, name, 10 * sizeof(char));
        this->age = age;
    }
};


int main() {
    Student student("hello world!!"), *studentPtr;
    Student *ptr;
    student.age = 10;
    studentPtr = &student;

    printf("%s %s %s", student.name, (*studentPtr).name, studentPtr->name); // (*studentPtr).age �� studentPtr->age�ȼ�
    //ptr = student.name; // error ptr��ָ��ṹ�����͵�ָ�룬 ����ת����ptr�ĵ�ַ���Ͳ�ƥ��
    ptr = (struct student *)student.name;

    return 0;
}