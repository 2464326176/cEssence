//**************************
// Author:  yh
// Time:    2022/5/13
//**************************
#include <iostream>

using namespace std;





int main() {
    // c ���Դ�ͳ����
    typedef double wages; // wages ��double�ı��� ͬ���
    typedef wages base, *p; // base�� double�ı��� *p��double *����

    // c++�µķ���
    using db = double; // db ��double�ı���

    {
    //ָ�� ���� ���ͱ���
        typedef char *pString; // pString ��char *����
        const pString cstr = 0; // cstrr��ָ��char *�ĳ���ָ��
        const pString *ps; // ps��һ������ָ�� ���Ķ�����ָ��char�ĳ���ָ��
    }

    return 0;
}
