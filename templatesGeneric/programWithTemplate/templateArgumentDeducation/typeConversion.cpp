/*
 * @Author: yh
 * @Date: 2022/6/12 1:12
 * @Description: 
 * @FilePath: typeConversion.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;
template<typename T>
T fobj(T t1, T t2) {
    printf("fobj\n");
} // 实参被copy

template<typename T>
T fref(const T &t1, const T &t2) {
    printf("fref\n");
} // 引用

template<typename A>
int compare1(const A &v1, const A &v2) {
    return (v1 > v2) ? 1 : ((v1 < v2) ? -1 : 0);
}

template<typename A, typename B>
int compare2(const A &v1, const B &v2) {
    return (v1 > v2) ? 1 : ((v1 < v2) ? -1 : 0);
}

template<typename T>
ostream &print(ostream &os, const T &obj) {
    return os << obj;
}

template<typename T>
void f1(T t1, T t2);
template<typename T1, typename T2>
void f2(T1 t1, T2 t2);
template<typename T1, typename T2, typename T3>
T1 sum(T2 t2, T3 t3) {
    T1 t1{};
    printf("%s %s %s\n", typeid(t1).name(), typeid(t2).name(), typeid(t3).name());
    return t2 + t3;
}
int main() {
/*    string s1("hello");
    const string s2("world!!!");
    fobj(s1, s2); // T fobj(T t1, T t2); // 实参被copy
    fref(s1, s2); // T fref(const T &t1, const T &t2); // 引用
    
    int a[10]{10, 10, 10,}, b[5]{5, 5, 5,};
    fobj(a, b); // fobj(int *, int *)
    //fref(a, b); // error 数组类型不匹配
    // 将实参传递给带模板类型的函数形参时，能够自动应用的类型转化只有const转化及数组或函数到指针的转化
    
    // 相同模板参数类型的函数形参
    long i = 42;
    //compare1(i, 1024); // error 1024会被推导为int  compare1(const A &v1, const A &v2)  这里是两个相同的类型
    compare2(i, 1024); // compare2(const A &v1, const B &v2)
    
    print(cout, 42); // print(ostream &os, const T &obj)
    ofstream f("output");
    print(f, 10); // f 转化为ostream &
    
    // 不同模板参数类型的函数形参
    {
        int i = 0, j = 42, *p1 = &i, *p2 = &j;
        const int *cp1 = &i, *cp2 = &j;
        f1(p1, p2);     // f1<int*>(int*, int*)
        f2(p1, p2);     // f2<int*, int*>(int*, int*)
        f1(cp1, cp2);   // f1<int const*>(int const*, int const*)
        f2(cp1, cp2);   // f2<int const*, int const*>(int const*, int const*)
        //f1(p1, cp1);    // deduced conflicting types for parameter 'T'
        f2(p1, cp1);    // f2<int*, int const*>(int*, int const*)
    }
    */
    printf("\n-------------------------\n");
    // 显示调用模板实参
    {
        int i = 3;
        long l = 1024;
        auto v1 = sum<long long>(i, l);
        auto v2 = sum<long long, int, long>(i, l);
        
    }
    return 0;
}