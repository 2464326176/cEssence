//**************************
// Author:  yh
// Time:    2022/4/7
//**************************

#include "virtualDestruct.h"

//ִֻ���� �������������
//��ͨ������ָ��  �� ���е����������������� ��ִ��һ��
//��ͨ������ָ�� �ͷ����е�������Դ
//void howtodelete(A *base) {
//    delete base;  //��仰������ֳɶ�̬ ��������
//}

void howtodelete(B *base)
{
	delete base;  //��仰������ֳɶ�̬ ��������
}

int main() {
    C *myC = new C; //new deleteƥ��
    //delete myC; //ֱ��ͨ����������ͷ���Դ ����Ҫдvirtual

    howtodelete(myC);

    return 0;
}

