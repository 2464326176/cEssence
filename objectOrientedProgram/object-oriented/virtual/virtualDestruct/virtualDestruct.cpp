//**************************
// Author:  yh
// Time:    2022/4/7
//**************************

#include "virtualDestruct.h"

//ִֻ���� �������������
//��ͨ������ָ��  �� ���е����������������� ��ִ��һ��
//��ͨ������ָ�� �ͷ����е�������Դ
void howtodelete(A *base) {
    delete base;  //��仰������ֳɶ�̬ ��������
}

void howtodelete(B *base) {
    delete base;  //��仰������ֳɶ�̬ ��������
}

int A::a = 0;

int main() {
//    A *a = new A; //A() ~A()
//    B *b = new B; //A() B() ~B() ~A()
//    delete a;
//    delete b;
    
    C *myC = new C; //new deleteƥ��
    //delete myC; //ֱ��ͨ����������ͷ���Դ ����Ҫдvirtual
    howtodelete(myC);
    
    return 0;
}

