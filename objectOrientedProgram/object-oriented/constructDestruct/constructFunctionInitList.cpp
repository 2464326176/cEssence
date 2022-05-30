//**************************
// Author:  yh
// Time:    2022/4/28
//**************************

#include <iostream>

class object {
public:
    // ����Ĭ�ϵĹ��캯��
    object(int a = 0, float b = 0, int r = 0) : a(a), b(b), r(r) {

    }
    /*object(int a, float b, int r) {
        this->a = a;
        this->b = b; // error ���ܸ�const ��ֵ
        this->r = r; // ���� rû����ʼ��
    }*/
    // �б��ʼ��
    object(int a) : a(a), b(a), r(a) {

    }

    void print() {
        printf("%d %d %d", a, b, r);
    }

private:
    int a;
    const float b;
    int &r;
};





int main() {
    object obj(1, 2.2, 5);
    obj.print();

    return 0;
}