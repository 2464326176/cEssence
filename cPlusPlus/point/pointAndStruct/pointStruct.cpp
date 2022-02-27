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
    (*studentPtr).age, student.age;  // (*studentPtr).age 和 studentPtr->age等价

    //ptr = student.name; // error ptr是指向结构体类型的指针， 不加转化，ptr的地址类型不匹配
    ptr = (struct student *)student.name;

    return 0;
}