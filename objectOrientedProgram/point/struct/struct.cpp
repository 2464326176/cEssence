//**************************
// Author:  yh
// Time:    2022/3/11
//**************************
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// 1.�������ṹ�����ͣ��ڶ�������͵ı���
/*struct �ṹ����
{
    ��Ա�б�
};*/
struct Student1 {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
}; // ���һ���ֺ�

struct Student1 stu1, stu2;

// 2. ��������ͬʱ�������
/*struct �ṹ����
{
    ��Ա�б�
} ����������;*/
struct Student2 {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
} stu3, stu4;

// 3.��ָ��������ֱ�Ӷ���ṹ�����
/*struct
{
    ��Ա�б�
} ����������;*/
struct {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
} stu5, stu6;

//������һ���������� ���̶���С�ڴ��ı��� ��û�з����ڴ�
typedef struct Teacher {
    char name[64];
    int age;
} Teacher1;

//��ʼ�����������ַ���
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
    //struct Teacher  t1; //����C���������ҷ����ڴ�

    Teacher t1; //����C���������ҷ����ڴ�//1
    Teacher t2 = {"aaaa", 32, 02};

    t1.age = 31;  //t1. ������  �� ��ʲô  ��û�в����ڴ�
    //��Ѱַ���� ����age ����� t1������� ƫ���� ===������ cup�н��С���
    //û�в����ڴ�

    //ͨ��ָ��ķ�ʽ ���� �ڴ�ռ�
    {
        Teacher *p = NULL;
        p = &t2;
        printf("p->age:%d \n", p->age); //->  ��Ѱַ���� ��age ����� t2�������  ƫ����  ���� cup�н��С�
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

    t2 = t1; //=�Ų����� ����������Ϊ

    //�������������ṩ �� =�� ��ֵ���� ����������Ҫ˳��
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