/*
 * @Author: yh
 * @Date: 2022/10/25 23:36
 * @Description: 
 * @FilePath: nest.cpp
 */
#include <iostream>
#include "nest.h"

using namespace std;

int main() {
    Nest nest;
    cout << nest.a << endl;
    Nest::A a1;
    a1.print1(); // public
    a1.print2(); // error
    a1.print3(); // error
    
    Nest::B b1; // error protected
    Nest::C c1; // error private
    return 0;
}