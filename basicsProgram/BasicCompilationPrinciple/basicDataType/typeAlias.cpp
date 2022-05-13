//**************************
// Author:  yh
// Time:    2022/5/13
//**************************
#include <iostream>

using namespace std;





int main() {
    // c 语言传统方法
    typedef double wages; // wages 是double的别名 同义词
    typedef wages base, *p; // base是 double的别名 *p是double *别名

    // c++新的方法
    using db = double; // db 是double的别名

    {
    //指针 常量 类型别名
        typedef char *pString; // pString 是char *别名
        const pString cstr = 0; // cstrr是指向char *的常量指针
        const pString *ps; // ps是一个常量指针 它的对象是指向char的常量指针
    }

    return 0;
}
