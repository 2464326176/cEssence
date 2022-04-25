//**************************
// Author:  yh
// Time:    2022/3/8
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ָ��������������ú��������ڴ�
//ָ�������룺�����ú��� �����ڴ�

// ����ָ�� һ��ָ����Ϊ���
int getMem(char **myp1, int *mylen1, char **myp2, int *mylen2) {
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    tmp1 = (char *) malloc(100);
    if (tmp1 == NULL) {
        return -1;
    }
    strcpy(tmp1, "abcdefg");
    *mylen1 = strlen(tmp1);
    *myp1 = tmp1; //����޸�ʵ��p1��ֵ

    tmp2 = (char *) malloc(100);
    if (tmp2 == NULL) {
        return -2;
    }
    strcpy(tmp2, "12345678");
    *mylen2 = strlen(tmp2);
    *myp2 = tmp2; //����޸�ʵ��p1��ֵ
    return 0;
}

// ����ָ�� ��Ϊ����
int getMem_Free(char **myp1) {
    /*
    if (myp1 == NULL)
    {
        return ;
    }
    free(*myp1);  //�ͷ���ָ����� ���µ��ڴ�ռ�
    *myp1 = NULL;  //��ʵ���޸ĳ�nULL
    */
    char *tmp = NULL;
    if (myp1 == NULL) {
        return -1;
    }
    tmp = *myp1;
    free(tmp);      //�ͷ���ָ����� ���µ��ڴ�ռ�
    *myp1 = NULL;   //��ʵ���޸ĳ�nULL
    return 0;
}

// һ��ָ����Ϊ����
int getMem_Free0(char *p) {
    if (p == NULL) {
        return -1;
    }
    free(p);  //�ͷ���ָ����� ���µ��ڴ�ռ�
    p = NULL;
    return 0;
}

int main() {
   /*
    char *p1 = NULL, *p2 = NULL;
    int len1 = 0, len2 = 0, ret = 0;
    // һ��ָ����Ϊʵ������
    ret = getMem(&p1, &len1, &p2, &len2);
    printf("p1: %s, p2: %s \n", p1, p2);
    getMem_Free(&p1); // �ڱ����ú�����  ��p1��ָ����ڴ���ͷŵ� ��ʵ��p1Ҳ���޸�ΪNULL;
    getMem_Free(&p2);*/

    char *p1 = NULL, *p2 = NULL;
    int len1 = 0, len2 = 0, ret = 0;
    // һ��ָ����Ϊʵ������
    ret = getMem(&p1, &len1, &p2, &len2);
    printf("p1: %s, p2: %s \n", p1, p2);
    getMem_Free0(p1);  //�ڱ����ú�����  ��p1��ָ����ڴ���ͷŵ� ������ ʵ��p1���ܱ��޸ĳ�NULLL ��Ұָ������
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


