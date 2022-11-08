/*
 * @Author: yh
 * @Date: 2022/10/30 18:25
 * @Description: 
 * @FilePath: sum.h
 */

#ifndef CESSENCE_TEMPLATESGENERIC_TEMPLATELINK_SUM_H
#define CESSENCE_TEMPLATESGENERIC_TEMPLATELINK_SUM_H
#include <iostream>

using namespace std;
template<typename T>
void sum(T a) {
    cout << "a: " << a << endl;
}

template<typename T1, typename T2>
void sum(T1 a, T2 b) {
    cout << "a: " << a << "b: " << b << endl;
}

template<typename T1, typename T2, typename T3>
void sum(T1 a, T2 b, T3 c) {
    cout << "a: " << a << "b: " << b << "c: " << c << endl;
}
#endif //CESSENCE_TEMPLATESGENERIC_TEMPLATELINK_SUM_H
