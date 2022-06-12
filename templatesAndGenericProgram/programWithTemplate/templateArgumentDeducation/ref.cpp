/*
 * @Author: yh
 * @Date: 2022/6/1 0:43
 * @Description: 
 * @FilePath: ref.cpp
 */

#include <iostream>
#include <string>
using namespace std;

// 折叠规则，只能应用于间接创建的引用的引用，如类型别名或者模板参数
/*
X& &、 X& &&和X&& & 被折叠成类型X&
X&& 和X&& &&被折叠成X&&
 */

// 顶层const和引用丢失了
template<typename F, typename T1, typename T2>
void flip(F f, T1 t1, T2 t2) {
    f(t1, t2);
}

// f(42, i); // f 改变了实参i
// flip1(f, j, 42) // 通过flip1调用f不会改变j

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 &t2) {
    f(t1, t2);
}

// 如果函数参数是一个指向模板类型参数的右值引用（T &&）,它对应的实参的const属性和左值/右值属性都可以保持
// 可以接受左值引用，不可以接受右值引用参数

//  flip2(f1, a, 42); 42 无法从右值转化为左值
// std::forward可以保存const属性和 左值/右值属性
template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
    //f(std::forward<T1>(t1), std::forward<T2>(t2));
    f(t1, t2);
}

template<typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int &v2) {
    cout << "v1 " << v1 << " v2: " << ++v2 << endl;
}

void f1(int &&v1, int &v2) {
    cout << "v1 " << v1 << " v2: " << ++v2 << endl;
}

int main() {
    int a = 5;
    f(1, a); // a 的值会改变  f(int v1, int &v2)
    printf("a: %d\n", a);
    
    flip(f, 2, a); // -》flip(void(*fcn)(int, int&), int t1, int t2);
    printf("a: %d\n", a); // a 不会被改变
    
    flip1(f, 2, a); // -》flip1(void(*fcn)(int, int&), int t1, int &t2); 仅限于左值传递
    printf("a: %d\n", a); // a会被改变
    
    //flip2(f1, a, 42);//
    flip3(f1, a, 42);
    
    flip2(f, 2, a); // -》flip2(void(*fcn)(int, int&), int &&t1, int &&t2); 可以涵盖右值
    // 2
    printf("a: %d\n", a);
    
    return 0;
}

/*int main2() {
    template<typename T>
    void f(T &P);
    // 函数参数p是一个模板类型参数T的引用，编译器会应用正常的引用绑定：const时底层的，不是顶层的；
    
    // 从左值引用函数参数推断类型
    template<typename T> void f1(T &) // 必须是一个左值
    f1(i); // int
    f1(ci); //const int
    f1(5); //error 必须为左值
    template<typename T> void f2(const T &) // 可以是一个右值
    f1(i); // int
    f1(ci); //const int
    f1(5); //const & 可以绑定到右值
    
    // 从右值引用函数参数推断类型
    template<typename T> void f3(T &&)
    f3(42); // 实参是一个int类型的右值，模板参数T是int
    
    
    return 0;
}*/