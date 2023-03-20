//**************************
// Author:  yh
// Time:    2022/5/14
//**************************

#include <iostream>


int main() {
    {
        int m = 6;
        double n = 3.15;
        auto item1 = m + n; //乱码
        auto item2 = n + m;
        printf("%d %f ", item1, item2);
        auto i = 0, *p = &i; // i是整数 p是整型指针
        // auto sz = 0, pi = 3.145; // 错误 sz和pi 类型不一致
    }

    {
        int i = 0, &r = i;
        auto a = r; // a是一个整数 r是i的别名 而i是一个整数

        // auto会忽略顶层const 底层const会保留下来
        const int ci = i, &cr = ci;
        auto b = ci; // b是一个整数 （ci的顶层const特性被忽略了）
        auto c = cr; // c是一个整数（cr是ci的别名 ci本身就是一个顶层const）
        auto d = &i; // d是一个整型指针 （整数的地址就是指向整数的指针）
        auto e = &ci; // e是一个指向整数常量的指针（对常量对象取地址是一种底层的const）

        //如果希望推断出来的auto类型是一个顶层的const
        const auto f = ci; // ci是int f是const int

        //将引用类型设未auto
        auto &g = ci; // g是一个整型常量引用 绑定到ci
        //auto &h = 42; // error 不能为非常量引用绑定字面值
        const auto &j = 42; // 可以为常量引用绑定字面值


        auto k = ci, &l = i; // k是整数 l是整型引用
        auto &m = ci, *p = &ci; // m是对整型常量的引用 p是指向整型常量的指针
        //auto &n = i, *p2 = &ci; // error i的类型是int ci的类型是const int
    }


    return 0;
}