//**************************
// Author:  yh
// Time:    2022/1/3
//**************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4
struct Student_type {
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[SIZE];



//fgets fputs

int _fgets_fputs() {
    FILE *fp;
    char ch, filename[10], str[100];
    printf("please input file name:\n");
    scanf("%s", filename);
    if((fp = fopen(filename, "w+"))  == NULL) {
        printf("open file %s error", filename);
        exit(0);
    }

    printf("# exit:\n");
    gets(str);
    while(str[strlen(str) - 1] != '#') {
        fputs(str, fp);
        puts(str);
        gets(str);
    }
    char _str[100];
    strncpy(_str, str, strlen(str) - 1);
    fputs(_str,fp);
    puts(_str);
    fclose(fp);
    return 0;
}

void _fread_write() {
    FILE *fp;
    if((fp = fopen("../c/data/student.txt", "wb")) == NULL) {
        printf("fopen error");
        return ;
    }

    for(int i = 0; i < SIZE; ++i) {
        printf("%-5s%4d%4d %-15s\n", stud[i].name, stud[i].num, stud[i].age, stud[i].addr);
        if(1 != fwrite(&stud[i], sizeof(Student_type), 1, fp)) {
            printf("fwrite error");
        }
    }
    fclose(fp);

/*
    Student_type std[SIZE];
    if((fp = fopen("../c/data/student.txt", "rb")) == NULL) {
        printf("fopen error");
        return ;
    }

    for(int i = 0; i < SIZE; ++i) {
        if(1 != fread(&std[i], sizeof(struct Student_type), 1, fp)) {
            printf("fwrite error");
            continue;
        }
        printf("%-10s%4d%4d%-15s\n", std[i].name, std[i].num, std[i].age, std[i].addr);
    }
    fclose(fp);
*/
}

void _rewind() {
    FILE *fp1 = fopen("../c/data/file.txt", "r");
    FILE *fp2 = fopen("../c/data/file_new.txt", "w+");

    while(!feof(fp1)) {
        putchar(getc(fp1));
    }
    putchar(10);
    rewind(fp1);
    while(!feof(fp1)) {
        putc(getc(fp1), fp2);
    }
    fclose(fp2);
    fclose(fp1);
    return;
}

void _fseek() {
    FILE *fp = fopen("../c/data/student.txt", "rb");
    Student_type stu[SIZE];
    for(int i = 0; i < SIZE; i+=2) {
        fseek(fp, i * sizeof (struct Student_type), 0);
        fread(&stu[i], sizeof (struct Student_type), 1, fp);
        printf("%s %d %d %s\n", stu[i].name, stu[i].num, stu[i].age, stu[i].addr);
    }
}

void _ftell ()
{
    FILE *fp;
    int len;

    fp = fopen("../c/data/file.txt", "r");
    if( fp == NULL )
    {
        perror ("open file error");
        return;
    }
    fseek(fp, 0, SEEK_END);
    printf("ftell(p): size %d", ftell(fp));
    len = ftell(fp);
    fclose(fp);

    printf("file.txt total = %d byte\n", len);
}

int main() {
    //_fgets_fputs();
    /*printf("please enter data of students:\n");
    for(int i = 0; i < SIZE; ++i) {
        scanf("%s%d%d%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
    }*/
    //_fread_write();
    //_rewind();
    //_fseek();
    _ftell();
    return 0;
}