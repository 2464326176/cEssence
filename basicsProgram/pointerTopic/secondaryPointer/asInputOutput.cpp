//**************************
// Author:  yh
// Time:    2022/3/8
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//指针做输出：被调用函数分配内存
//指针做输入：主调用函数 分配内存

// 二级指针 一级指针作为输出
int getMem(char **myp1, int *mylen1, char **myp2, int *mylen2) {
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    tmp1 = (char *) malloc(100);
    if (tmp1 == NULL) {
        return -1;
    }
    strcpy(tmp1, "abcdefg");
    *mylen1 = strlen(tmp1);
    *myp1 = tmp1; //间接修改实参p1的值

    tmp2 = (char *) malloc(100);
    if (tmp2 == NULL) {
        return -2;
    }
    strcpy(tmp2, "12345678");
    *mylen2 = strlen(tmp2);
    *myp2 = tmp2; //间接修改实参p1的值
    return 0;
}

// 二级指针 作为输入
int getMem_Free(char **myp1) {
    /*
    if (myp1 == NULL)
    {
        return ;
    }
    free(*myp1);  //释放完指针变量 所致的内存空间
    *myp1 = NULL;  //把实参修改成nULL
    */
    char *tmp = NULL;
    if (myp1 == NULL) {
        return -1;
    }
    tmp = *myp1;
    free(tmp);      //释放完指针变量 所致的内存空间
    *myp1 = NULL;   //把实参修改成nULL
    return 0;
}

// 一级指针作为输入
int getMem_Free0(char *p) {
    if (p == NULL) {
        return -1;
    }
    free(p);  //释放完指针变量 所致的内存空间
    p = NULL;
    return 0;
}

int main() {
   /*
    char *p1 = NULL, *p2 = NULL;
    int len1 = 0, len2 = 0, ret = 0;
    // 一级指针作为实参输入
    ret = getMem(&p1, &len1, &p2, &len2);
    printf("p1: %s, p2: %s \n", p1, p2);
    getMem_Free(&p1); // 在被调用函数中  把p1所指向的内存给释放掉 ，实参p1也被修改为NULL;
    getMem_Free(&p2);*/

    char *p1 = NULL, *p2 = NULL;
    int len1 = 0, len2 = 0, ret = 0;
    // 一级指针作为实参输入
    ret = getMem(&p1, &len1, &p2, &len2);
    printf("p1: %s, p2: %s \n", p1, p2);
    getMem_Free0(p1);  //在被调用函数中  把p1所指向的内存给释放掉 ，但是 实参p1不能被修改成NULLL 有野指针现象
    getMem_Free0(p2);


    if (p2 != NULL) {
        printf("p2 != NULL\n");
        p2 = NULL;
    }

    if (p1 != NULL) {
        printf("p1 != NULL\n");
        p1 = NULL;
    }

    return 0;
}


