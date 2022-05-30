//**************************
// Author:  yh
// Time:    2022/4/28
//**************************

#include <iostream>

class object {
public:
    // 定义默认的构造函数
    object(int a = 0, float b = 0, int r = 0) : a(a), b(b), r(r) {

    }
    /*object(int a, float b, int r) {
        this->a = a;
        this->b = b; // error 不能给const 赋值
        this->r = r; // 错误 r没被初始化
    }*/
    // 列表初始化
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