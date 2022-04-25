//**************************
// Author:  yh
// Time:    2022/3/11
//**************************
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// 1.先声明结构体类型，在定义该类型的变量
/*struct 结构体名
{
    成员列表
};*/
struct Student1 {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
}; // 最后一个分号

struct Student1 stu1, stu2;

// 2. 在声明的同时定义变量
/*struct 结构体名
{
    成员列表
} 变量名表列;*/
struct Student2 {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
} stu3, stu4;

// 3.不指定类型名直接定义结构体变量
/*struct
{
    成员列表
} 变量名表列;*/
struct {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
} stu5, stu6;

//定义了一个数据类型 。固定大小内存块的别名 还没有分配内存
typedef struct Teacher {
    char name[64];
    int age;
} Teacher1;

//初始化变量的三种方法
Teacher1 t1 = {"aaaa", 31, 01};

struct Teacher2 {
    char name[64];
    int aga;
} t2 = {"names", 21};

struct {
    char name[64];
    int aga;
} t3 = {"names", 21};


void main01() {
    //struct Teacher  t1; //告诉C编译器给我分配内存

    Teacher t1; //告诉C编译器给我分配内存//1
    Teacher t2 = {"aaaa", 32, 02};

    t1.age = 31;  //t1. 操作符  是 干什么  有没有操作内存
    //是寻址操作 计算age 相对于 t1大变量的 偏移量 ===》计算 cup中进行。。
    //没有操作内存

    //通过指针的方式 操作 内存空间
    {
        Teacher *p = NULL;
        p = &t2;
        printf("p->age:%d \n", p->age); //->  是寻址操作 算age 相对于 t2大变量的  偏移量  计算 cup中进行。
        printf("p->name:%s \n", p->name);
    }
    strcpy(t1.name, "t1name");

    printf("t1.name:%s \n", t1.name);


    printf("hello...\n");
    system("pause");
    return;
}

void copyTeacher(Teacher to, Teacher from) {
    to = from;
}

void copyTeacher02(Teacher *to, Teacher *from) {
    //(*to) = (*from);
    *to = *from;
}

void main111() {

    Teacher t1 = {"aaaa", 32, 02};
    Teacher t2;
    Teacher t3;
    memset(&t3, 0, sizeof(t3));

    t2 = t1; //=号操作下 编译器的行为

    //编译器给我们提供 简单 =号 赋值操作 。。。我们要顺从
    printf("t2.name:%s \n", t2.name);
    printf("t2.age:%d \n", t2.age);

    copyTeacher(t3, t1);
    printf("copyTeacher() after \n");
    printf("t3.name:%s \n", t3.name);
    printf("t3.age:%d \n", t3.age);
    printf("hello...\n");


    copyTeacher02(&t3, &t1);
    printf("copyTeacher02() after \n");
    printf("t3.name:%s \n", t3.name);
    printf("t3.age:%d \n", t3.age);
    printf("hello...\n");


    system("pause");
    return;

}