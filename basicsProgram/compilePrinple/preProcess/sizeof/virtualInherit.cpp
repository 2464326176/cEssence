/*
 * @Author: yh
 * @Date: 2023-03-16 00:44:35
 * @LastEditTime: 2023-03-16 00:49:26
 * @Description:
 * @FilePath: \cEssence\basicsProgram\BasicCompilationPrinciple\preProcess\sizeof\virtualInherit.cpp
 */
#include <iostream>

using namespace std;

class A {};

class B {};

class C : public A, public B {};

class D : virtual public A {};

class E : virtual public A, virtual public B {};

class F {
public:
    int a;
    static int b;
};

int F::b = 12;

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;
    cout << sizeof(F) << endl;

    return 0;
}