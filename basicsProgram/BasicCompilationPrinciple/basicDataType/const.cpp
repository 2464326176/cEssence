//**************************
// Author:  yh
// Time:    2022/3/11
//**************************
#include <iostream>

int get_size() {

    return 1024;
}

int main() {
    // const �޶���
    {
        const int bufSize = 512; // �������Ĵ�С���ܱ��޸�
        //bufSize = 64; // error �����ʱ������

        const int i = get_size(); // ����ʱ��ʼ��
        const int j = 42; // ����ʱ��ʼ��
        //const int k; // ���� k��һ��δ����ʼ���ĳ���
    }

    //��ʼ��
    {
        int i = 42;
        const int ci = i; // ��ȷ i��ֵ��copy��ci
        int j = ci; // ci��ֵ��copy��j
        // ci�ĳ������� ������ִ���޸�ci�Ĳ���ʱ�Żᷢ�����ã�
        // ��ciȥ��ʼ��j ����������ci�������� ��Ϊֻ��copy��ֵ
        // copyһ�������ֵ������ȥ�ı�����һ��������� �µĶ����ԭ���Ķ����û��ɶ��ϵ
    }

    //Ĭ��const�����ڵ�ǰ�ļ���Ч��
    {
        const int bufSize = 512; // �������Ĵ�С���ܱ��޸�
        //�������ڱ�������а��õ������ĵط�ȫ���滻��Ϊ��Ӧ��ֵ��Ҳ����˵
        //���������ҵ������������õ�bufSize�ĵط�Ȼ��512�滻��
        // Ĭ��const�����ڵ�ǰ�ļ���Ч��������ļ�������ͬ����const����ʱ
        // ��ʵ�����ڲ�ͬ�ļ������˶����ı���������빫��һ��const��������Ҫ��extern����
        // file.h
        //extern const int bufSize1 = get_size();
        {
            // file1.h
            extern const int bufSize1; //�����ļ���bufSize��ͬһ��
        }
    }

    {
        // const ������
        //���԰�c���ð󶨵�const�����ϣ�����󶨵������Ķ�����һ�������ǳ�֮Ϊ�Գ��������ã�
        // ����ͨ�����ò�ͬ���� �Գ��������ò��ܱ������޸����󶨵Ķ���
        const int ci = 1024;
        const int &r1 = ci;
        // r1 = 42; //���� r1�ǶԳ���������
        // int &r2 = ci; // ���� ��ͼ��һ���ǳ�������ָ��һ����������
    }

    {
        // ��ʼ���Ͷ�const������

        //һ����˵ ���õ����ͱ������������ö��������һ�£�
        // ���� ���������⣺
        //�ڳ�ʼ����������ʱ������������ʽ��Ϊ��ʼֵ��ֻҪ�ñ��ʽ�Ľ����ת�������õ����ͼ��ɣ�
        //����һ���������ð󶨷ǳ����Ķ�������ֵ�������Ǹ�һ����ʽ
        int i = 42;
        const int &r1 = i; // �����const int &�󶨵�һ����ͨ��int������
        const int &r2 = 42; // ��ȷ r1��һ����������
        const int &r3 = r1 * 2; // ��ȷ r3��һ����������
        //int &r4 = r1 * 2; // error r4��һ����ͨ�ķǳ�������
    }


    {
        //��const�����ÿ�������һ������const�Ķ���
        // ������ʶ�� �������ö����ÿɲ���Ĳ����������޶�
        // �������õĶ������ǲ���һ������δ�����޶�����˶���Ҳ�����Ǹ��ǳ�������������ͨ��������;��ȥ�ı�����ֵ

        int i = 42;
        int &r1 = i; // ����ri�󶨶���i
        const int &r2 = i; // r2Ҳ�󶨶���i�����ǲ�����ͨ��r2ȥ�޸�i��ֵ
        r1 = 0; // r1���ǳ���
        //r2 = 0; //error r2��һ����������
    }

    {
        // ����const ��top-level const����ʾָ�뱾����һ��������
        // �ײ�const ��low-level const����ʾ��ָ��Ķ�����һ��������
        int i = 0;
        int *const p1 = &i; // ���ܸ�p1��ֵ ����һ������const
        const int ci = 42; // ���ܸ�ci��ֵ ����һ������const
        const int *p2 = &ci; // ����ı�p2��ֵ ����һ���ײ��const
        const int *const p3 = p2; // ���ұߵ�const ����const�� ����ߵ�const �ǵײ�const
        const int &r = ci; // �����������õ�const���ǵײ�const

        //��ִ�ж����copy�����������Ƕ���const���ǵײ��const�������� �����const����ʲôӰ��
        i = ci; // ��ȷ ����ci��ֵ ci��һ�������const
        p2 = p3; // ��ȷ p2 p3 ָ������������ͬ p3�����const�Ĳ��ֲ���Ӱ��
        // ִ�п����Ĳ���������ı俽�������ֵ ��˿���ǰ��Ķ����Ƿ��ǳ�������ʲôӰ��

        // ��һ���� �ײ��const���Ʋ����Ժ��ԣ���ִ�ж���Ŀ�������ʱ������ǰ��Ķ�����������ͬ�ĵײ�const
        // ����˵����������������ͱ����ܹ�ת����һ����˵ �ǳ������Ի��ɳ��� ��֮����
        int *p = p3; // error p3�ɵײ��const pû��
        p2 = p3; // ��ȷ p2��p3���ǵײ��const
        p2 = &i; // ��ȷ int* ����ת��Ϊconst int*
        //int &r = ci; // ���� ��ͨ��int & �����԰󶨵�int������
        const int &r2 = i; // ��ȷ const int& ���԰󶨵�һ����ͨ��int��
    }


    {
        // constָ��
        // ָ���Ƕ��󣬶����ò��ǣ���˾��������Ķ�������һ���������ָ�뱾��λ����
        // ����ָ������ʼ��������һ����ʼ����ɣ�����ֵҲ����hi�����ָ���е��Ǹ���ַ�Ͳ��ܸı�
        // ��*����const�ؼ���֮ǰ����˵��ָ����һ���������������ָ�뱾���ֵ������ָ����Ǹ�ֵ��
        int errNumb = 0;
        int *const curErr = &errNumb; // curErr��һֱָ��errNumb �����ڱ���
        const double pi = 3.141596; //
        const double *const pip = &pi; // pip ��һ��ָ��������ĳ���ָ��
        //*pip = 2.72; // error pip��һ��ָ������ָ��
        if(*curErr) {
            // errorHandler();
            *curErr = 0;
        }
    }

    {
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
    }

    return 0;
}
