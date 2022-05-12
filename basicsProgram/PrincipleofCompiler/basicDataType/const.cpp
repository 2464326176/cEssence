//**************************
// Author:  yh
// Time:    2022/3/11
//**************************
#include <iostream>


int main() {
    const int a = 0; // a���ܱ��޸�
    int const b = 0; // b���ܱ��޸�

    //ָ��ָ��Ķ�������Ϊconst��volatile
    const char *cpch; // ���η����ε�ָ��ָ��Ķ��� ���ܱ��޸�
    volatile char *vpch;
    // ָ���ֵ����ָ���д洢��ʵ�ʵ�ַ������Ϊconst��volatile
    char *const pchc = nullptr; // ���η����ε�ָ���ֵ ���ܱ��޸�
    char *volatile pchv;

    // ��c������const���εı���������ͨ����Ӹ�ֵ��ʽ���޸�
    const int value = 10;
    int *p = const_cast<int *>(&value);
    *p = 6;

    const char cch = 'A'; // cch��ֵ���ܱ��޸�
    char ch = 'B';

    const char *pch1 = &cch;
    //char *pch2 = &cch;   // Error
    //char *const pch3 = &cch;   // Error
    const char *const pch4 = &cch;

    //*pch1 = 'A';  // Error: object declared const
    pch1 = &ch;   // OK: pointer not declared const
    char *pch2 = "aaa";  // OK: normal pointer
    pch2 = &ch;   // OK: normal pointer
    char *const pch3 = "bbb";  // OK: object not declared const
    //pch3 = &ch;   // Error: pointer declared const
    //*pch4 = "cccc";  // Error: object declared const
    //pch4 = &ch;   // Error: pointer declared const

    const char *pch5 = &ch;
    char *pch6 = &ch;
    char *const pch7 = &ch;
    const char *const pch8 = &ch;
    return 0;
}
