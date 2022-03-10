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

    printf("%s %s %s", student.name, (*studentPtr).name, studentPtr->name); // (*studentPtr).age 和 studentPtr->age等价
    //ptr = student.name; // error ptr是指向结构体类型的指针， 不加转化，ptr的地址类型不匹配
    ptr = (struct student *)student.name;

    return 0;
}