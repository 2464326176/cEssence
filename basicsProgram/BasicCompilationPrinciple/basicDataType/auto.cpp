//**************************
// Author:  yh
// Time:    2022/5/14
//**************************

#include <iostream>


int main() {
    {
        int m = 6;
        double n = 3.15;
        auto item1 = m + n; //����
        auto item2 = n + m;
        printf("%d %f ", item1, item2);
        auto i = 0, *p = &i; // i������ p������ָ��
        // auto sz = 0, pi = 3.145; // ���� sz��pi ���Ͳ�һ��
    }

    {
        int i = 0, &r = i;
        auto a = r; // a��һ������ r��i�ı��� ��i��һ������

        // auto����Զ���const �ײ�const�ᱣ������
        const int ci = i, &cr = ci;
        auto b = ci; // b��һ������ ��ci�Ķ���const���Ա������ˣ�
        auto c = cr; // c��һ��������cr��ci�ı��� ci�������һ������const��
        auto d = &i; // d��һ������ָ�� �������ĵ�ַ����ָ��������ָ�룩
        auto e = &ci; // e��һ��ָ������������ָ�루�Գ�������ȡ��ַ��һ�ֵײ��const��

        //���ϣ���ƶϳ�����auto������һ�������const
        const auto f = ci; // ci��int f��const int

        //������������δauto
        auto &g = ci; // g��һ�����ͳ������� �󶨵�ci
        //auto &h = 42; // error ����Ϊ�ǳ������ð�����ֵ
        const auto &j = 42; // ����Ϊ�������ð�����ֵ


        auto k = ci, &l = i; // k������ l����������
        auto &m = ci, *p = &ci; // m�Ƕ����ͳ��������� p��ָ�����ͳ�����ָ��
        //auto &n = i, *p2 = &ci; // error i��������int ci��������const int
    }


    return 0;
}