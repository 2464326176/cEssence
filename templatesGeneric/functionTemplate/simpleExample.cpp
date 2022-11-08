//**************************
// Author:  yh
// Time:    2022/4/26
//**************************
#include <iostream>

using namespace std;


void swapVariable(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    cout << "swapVariable(int &a, int &b)" << endl;
}

void swapVariable(char &a, char &b) {
    char t = a;
    a = b;
    b = t;
    cout << "swapVariable(int &a, int &b)" << endl;
}

template<typename T>
// ����
void swapVariable(T &a, T &b) {
    T t;
    t = a;
    a = b;
    b = t;
    cout << "swapVariable(T &a, T &b)" << endl;
}

int Max(int a, int b) {
    cout << "int Max(int a, int b)" << endl;
    return a > b ? a : b;
}

template<typename T>
T Max(T a, T b) {
    cout << "T Max(T a, T b)" << endl;
    return a > b ? a : b;
}

template<typename T>
T Max(T a, T b, T c) {
    cout << "T Max(T a, T b, T c)" << endl;
    return Max(Max(a, b), c);
}

int main() {
    int x = 1, y = 2;
    float a = 2.0, b = 3.0;
    double a1 = 2.01, b1 = 3.01;
    size_t a2 = 7, b2 = 8;
    swapVariable(x, y); //�Զ��������� �Ƶ��ķ�ʽ ��ʽ���� swapVariable(int &a, int &b)
    swapVariable(a, b); //�Զ��������� �Ƶ��ķ�ʽ ��ʽ����
    swapVariable(a2, b2); //�Զ��������� �Ƶ��ķ�ʽ ��ʽ����

    swapVariable<float>(a, b); //��ʾ���͵���
    swapVariable<double>(a1, b1); //��ʾ���͵��� swapVariable(T &a, T &b)


    cout << Max(a, b) << endl; //������ģ�����ͨ���������ϵ���ʱ,����ѡ����ͨ����
    cout << Max<>(a, b) << endl; //����ʾʹ�ú���ģ��,��ʹ��<> �����б�
    cout << Max(3.0, 4.0) << endl; //��� ����ģ��������õ�ƥ�� ʹ�ú���ģ��
    cout << Max(5.0, 6.0, 7.0) << endl; //����
    cout << Max('a', 100) << endl;  //������ͨ���� ������ʽ����ת��
    return 0;
}



