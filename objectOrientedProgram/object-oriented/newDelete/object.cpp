//**************************
// Author:  yh
// Time:    2022/4/17
//**************************

#include "object.h"

// 1
//		mallocFree	free				c���Եĺ���
//		new		delete ������	c++���﷨
//2		new �������ͱ���  �����������  ���������
//3

//assignment base type
void main01() {
    //
    int *p = (int *) malloc(sizeof(int));
    *p = 10;
    //free(p);
    delete p;
    
    int *p2 = new int; //�����������
    *p2 = 20;
    free(p2);
    //
    int *p3 = new int(30);
    printf("*p3:%d \n", *p3);
    //delete p3;
    free(p3);
    
    return;
}

//assignment array type
void main02() {
    //c���Է�������
    int *p = (int *) malloc(sizeof(int) * 10);  //int array[10];
    p[0] = 1;
    //free(p);
    delete[] p;
    
    //c++��������
    int *pArray = new int[10];
    pArray[1] = 2;
    //delete [] pArray; //���鲻Ҫ��[] ����
    free(pArray);
    
    char *pArray2 = new char[25]; //char buf[25]
    delete[] pArray2;
    return;
}

//�������new delete
//��ͬ �� ��ͬ�ĵط� new��ִ�����͹��캯��   delete������ ��ִ�������������

//	mallocFree 	free���� C
//1 new 	delete �������� c++�Ĺؼ���
//����
int main() {
    //c
    Object *pT1 = (Object *) malloc(sizeof(Object));
    //free(pT1);
    delete pT1;
    
    //c++
    Object *pT2 = new Object(10);
    //delete pT2;
    free(pT2);
    
    return 0;
}