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
// 泛型
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
    swapVariable(x, y); //自动数据类型 推导的方式 隐式调用 swapVariable(int &a, int &b)
    swapVariable(a, b); //自动数据类型 推导的方式 隐式调用
    swapVariable(a2, b2); //自动数据类型 推导的方式 隐式调用

    swapVariable<float>(a, b); //显示类型调用
    swapVariable<double>(a1, b1); //显示类型调用 swapVariable(T &a, T &b)


    cout << Max(a, b) << endl; //当函数模板和普通函数都符合调用时,优先选择普通函数
    cout << Max<>(a, b) << endl; //若显示使用函数模板,则使用<> 类型列表
    cout << Max(3.0, 4.0) << endl; //如果 函数模板产生更好的匹配 使用函数模板
    cout << Max(5.0, 6.0, 7.0) << endl; //重载
    cout << Max('a', 100) << endl;  //调用普通函数 可以隐式类型转换
    return 0;
}



