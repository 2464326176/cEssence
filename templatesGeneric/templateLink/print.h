/*
 * @Author: yh
 * @Date: 2022/10/30 18:25
 * @Description: 
 * @FilePath: print.h
 */

#ifndef CESSENCE_TEMPLATESGENERIC_TEMPLATELINK_PRINT_H
#define CESSENCE_TEMPLATESGENERIC_TEMPLATELINK_PRINT_H
#include <iostream>

using namespace std;
template<typename T>
void print(T a) {
    cout << "a: " << a << endl;
}

template<typename T1, typename T2>
void print(T1 a, T2 b) {
    cout << "a: " << a << "b: " << b << endl;
}

template<typename T1, typename T2, typename T3>
void print(T1 a, T2 b, T3 c) {
    cout << "a: " << a << "b: " << b << "c: " << c << endl;
}
#endif //CESSENCE_TEMPLATESGENERIC_TEMPLATELINK_PRINT_H
