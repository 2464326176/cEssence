//**************************
// Author:  yh
// Time:    2022/3/1
//**************************

#include "inherit.h"


/*
���ݹ�������ָ������������������
	���������Ե����������ʹ��
	����������ֱ�Ӹ�ֵ���������
	����������ֱ�ӳ�ʼ���������
	����ָ�����ֱ��ָ���������
	�������ÿ���ֱ�������������
	*/


void printByPoint(Parent *base) {
    base->printP();

}

void printByReference(Parent &base) {
    base.printP();
}

void virtualPrintByPoint(Parent *base) {
    base->print();

}

void virtualPrintByReference(Parent &base) {
    base.print();
}

void inherit() {
    Parent p1;
    p1.printP();

    Child c1;
    c1.printC();
    c1.printP();

    //��ֵ������ԭ��
    //1-1 ����ָ�� (����) ָ�� �������
    Parent *p = NULL;
    p = &c1;
    p->printP();

    //1-2 ָ������������
    printByPoint(&p1);
    printByPoint(&c1);

    //1-3��������������
    printByReference(p1);
    printByReference(c1);

    //�ڶ��㺬��
    //�������������   ��ʼ��   �������
    //�������һ������ĸ���
    Parent p3 = c1;
}

void virtualInherit() {
    Parent p1;
    Child c1;

    //��ֵ������ԭ��
    //1-1 ����ָ�� (����) ָ�� �������
    Parent *p = NULL;
    p = & p1;
    p->print();
    p = &c1;
    p->print();

    //1-2 ָ������������
    virtualPrintByPoint(&p1); // parent
    virtualPrintByPoint(&c1); // child

    //1-3��������������
    virtualPrintByReference(p1); // parent
    virtualPrintByReference(c1); // child

}

int main() {
    //Derive d(10);
    //std::cout << d.val << d.Base::val << std::endl;
    //inherit();
    virtualInherit();

    return 0;
}
