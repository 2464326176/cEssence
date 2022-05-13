//**************************
// Author:  yh
// Time:    2022/3/11
//**************************
#include <iostream>

int get_size() {

    return 1024;
}

int main() {
    // const 限定符
    {
        const int bufSize = 512; // 缓冲区的大小不能被修改
        //bufSize = 64; // error 编译的时候会出错

        const int i = get_size(); // 运行时初始化
        const int j = 42; // 编译时初始化
        //const int k; // 错误 k是一个未经初始化的常量
    }

    //初始化
    {
        int i = 42;
        const int ci = i; // 正确 i的值被copy给ci
        int j = ci; // ci的值被copy给j
        // ci的常量特性 仅仅在执行修改ci的操作时才会发挥作用，
        // 当ci去初始化j 根本无需在ci常量特性 因为只是copy的值
        // copy一个对象的值并不会去改变它，一旦拷贝完成 新的对象和原来的对象就没有啥关系
    }

    //默认const对象尽在当前文件有效，
    {
        const int bufSize = 512; // 缓冲区的大小不能被修改
        //编译器在编译过程中把用到变量的地方全部替换成为对应的值，也就是说
        //编译器会找到代码中所有用到bufSize的地方然后512替换，
        // 默认const对象尽在当前文件有效，当多个文件出现了同名的const对象时
        // 其实等于在不同文件定义了独立的变量，如果想公用一个const变量，需要用extern修饰
        // file.h
        //extern const int bufSize1 = get_size();
        {
            // file1.h
            extern const int bufSize1; //两个文件的bufSize是同一个
        }
    }

    {
        // const 的引用
        //可以把c引用绑定到const对象上，就像绑定到其他的对象上一样，我们称之为对常量的引用；
        // 与普通的引用不同的是 对常量的引用不能被用作修改它绑定的对象
        const int ci = 1024;
        const int &r1 = ci;
        // r1 = 42; //错误 r1是对常量的引用
        // int &r2 = ci; // 错误 试图让一个非常量引用指向一个常量对象
    }

    {
        // 初始化和对const的引用

        //一般来说 引用的类型必须与其所引用对象的类型一致；
        // 但是 由两个例外：
        //在初始化常量引用时允许用任意表达式作为初始值，只要该表达式的结果能转化成引用的类型即可；
        //允许一个常量引用绑定非常量的对象、字面值，甚至是个一般表达式
        int i = 42;
        const int &r1 = i; // 允许把const int &绑定到一个普通的int对象上
        const int &r2 = 42; // 正确 r1是一个常量引用
        const int &r3 = r1 * 2; // 正确 r3是一个常量引用
        //int &r4 = r1 * 2; // error r4是一个普通的非常量引用
    }


    {
        //对const的引用科能引用一个并非const的对象
        // 必须认识到 常量引用对引用可参与的操作做出了限定
        // 对于引用的对象本身是不是一个常量未做出限定，因此对象也可能是个非常量，所以允许通过其他的途径去改变他的值

        int i = 42;
        int &r1 = i; // 引用ri绑定对象i
        const int &r2 = i; // r2也绑定对象i，但是不允许通过r2去修改i的值
        r1 = 0; // r1并非常量
        //r2 = 0; //error r2是一个常量引用
    }

    {
        // 顶层const （top-level const）表示指针本身是一个常量；
        // 底层const （low-level const）表示所指向的对象是一个常量；
        int i = 0;
        int *const p1 = &i; // 不能改p1的值 这是一个顶层const
        const int ci = 42; // 不能改ci的值 这是一个顶层const
        const int *p2 = &ci; // 允许改变p2的值 这是一个底层的const
        const int *const p3 = p2; // 靠右边的const 顶层const， 靠左边的const 是底层const
        const int &r = ci; // 用于声明引用的const都是底层const

        //当执行对象的copy操作，常量是顶层const还是底层的const区别明显 顶层的const不受什么影响
        i = ci; // 正确 拷贝ci的值 ci是一个顶层的const
        p2 = p3; // 正确 p2 p3 指向对象的类型相同 p3顶层的const的部分不受影响
        // 执行拷贝的操作并不会改变拷贝对象的值 因此拷贝前后的对象是否是常量不受什么影响

        // 另一方面 底层的const限制不可以忽略，当执行对象的拷贝操作时，拷贝前后的对象必须具有相同的底层const
        // 或者说两个对象的数据类型必须能够转化，一般来说 非常量可以换成常量 反之不行
        int *p = p3; // error p3由底层的const p没有
        p2 = p3; // 正确 p2和p3都是底层的const
        p2 = &i; // 正确 int* 可以转化为const int*
        //int &r = ci; // 错误 普通的int & 不可以绑定到int常量上
        const int &r2 = i; // 正确 const int& 可以绑定到一个普通的int上
    }


    {
        // const指针
        // 指针是对象，而引用不是，因此就像其他的对象类型一样，允许把指针本身定位常量
        // 常量指针必须初始化，而且一旦初始化完成，他的值也急速hi存放在指针中的那个地址就不能改变
        // 把*放在const关键字之前可以说明指针是一个常量，不变的是指针本身的值而不是指向的那个值；
        int errNumb = 0;
        int *const curErr = &errNumb; // curErr将一直指向errNumb 不能在被改
        const double pi = 3.141596; //
        const double *const pip = &pi; // pip 是一个指向常量对象的常量指针
        //*pip = 2.72; // error pip是一个指向常量的指针
        if(*curErr) {
            // errorHandler();
            *curErr = 0;
        }
    }

    {
        const int a = 0; // a不能被修改
        int const b = 0; // b不能被修改

        //指针指向的对象声明为const或volatile
        const char *cpch; // 修饰符修饰的指针指向的对象 不能被修改
        volatile char *vpch;
        // 指针的值（即指针中存储的实际地址）声明为const或volatile
        char *const pchc = nullptr; // 修饰符修饰的指针的值 不能被修改
        char *volatile pchv;

        // 在c语言中const修饰的变量，可以通过间接赋值方式被修改
        const int value = 10;
        int *p = const_cast<int *>(&value);
        *p = 6;

        const char cch = 'A'; // cch的值不能被修改
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
