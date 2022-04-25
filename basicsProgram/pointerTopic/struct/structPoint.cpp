//**************************
// Author:  yh
// Time:    2022/2/27
//**************************
#include <iostream>
#include <cstring>
struct Student {
    char name[10];
    int age;
};

int main() {


    {
        struct Student student = {"lyh", 18}, *studentPtr;
        student.age = 10;
        printf("name: %s, age: %d\n", student.name, student.age);
        studentPtr = &student;
        printf("%s %s %s\n", student.name, (*studentPtr).name, studentPtr->name); // (*studentPtr).age 和 studentPtr->age等价
    }

    struct Student std[4] = {
            {"wang", 58},
            {"liu", 45},
            {"li", 32},
            {"wen", 78},
    }, *p;
    p = std;

    for(; p < std + 4; ++p) {
        printf("name: %s, age: %d\n", p->name, p->age);
    }

    //ptr = student.name; // error ptr是指向结构体类型的指针， 不加转化，ptr的地址类型不匹配
    //ptr = (struct student *)std[1].name;
    //printf("name: %s\n", ptr);
    return 0;
}