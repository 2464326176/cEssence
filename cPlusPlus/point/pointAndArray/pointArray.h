//**************************
// Author:  yh
// Time:    2022/2/25
//**************************

#ifndef CESSENCE_POINTARRAY_H
#define CESSENCE_POINTARRAY_H
#include <cstring>
#include <iostream>

struct Score {
    char name[12];
    int score[4];
    Score(char *name, int score[]) {
        //printf("sizeof(name): %d  sizeof(score): %d", sizeof(name), sizeof(score));
        strncpy(this->name, (char *)name, sizeof(this->name));
        memcpy(this->score, score, sizeof(this->score));
    }
};

struct Student {
    char *classes;
    int **dataSet;
    Student(int num) {
        classes = nullptr;
        printf("sizeof(int*): %d", sizeof(int*));
        dataSet = (int **) malloc(sizeof(int*) * num);
    }


};

int printfArray(int array[][2]);
int printfArray(int **p);
int printfArray1(int (*p)[2]);
int printfArray(int *p);



#endif //CESSENCE_POINTARRAY_H
