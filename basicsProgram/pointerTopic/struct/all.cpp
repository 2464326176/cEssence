//**************************
// Author:  yh
// Time:    2022/3/12
//**************************

#include <stdio.h>
#include <stdlib.h>

#define NUM 3

struct Student {
    int num;
    char name[20];
    float score[3];
    float aver;
};

void input(struct Student *stu) {
    struct Student *p = stu;
    for(; p < stu + NUM; ++p) {
        scanf("%d %s %f %f %f", &p->num, &p->name, &p->score[0], &p->score[1], &p->score[2]);
        p->aver = (p->score[0] + p->score[1] + p->score[2]) / 3.0;
    }

    /*for(int i = 0; i < NUM; ++i) {
        scanf("%d %s %f %f %f", &stu[i].num, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
    }*/
}

struct Student * max(struct Student *stu) {
    struct Student *p = stu + 1, *q = stu;

    for(; p < stu + NUM; ++p) {
        if(p->aver > q->aver) {
            q = p;
        }
    }
    return q;
    /*int m = 0;
    for(int i = 1; i < NUM; ++i) {
        if(stu[i].aver > stu[i - 1].aver) {
            m = i;
        }
    }
    return stu[m];*/
}

void printfStruct(struct Student *stu) {
    printf("%d %s %f %f %f %f", stu->num, stu->name, stu->score[0], stu->score[1], stu->score[2], stu->aver);
}

int main() {
    struct Student stu[NUM];
    input(stu);
    printfStruct(max(stu));
    return 0;
}

