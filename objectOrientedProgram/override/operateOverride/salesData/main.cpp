/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2023-01-29 22:56:39
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\override\operateOverride\salesData\main.cpp
 */
//**************************
// Author:  yh
// Time:    2022/4/28
//**************************
#include "salesData.h"

int main() {
    Sales_data cp5;
    std::cin >> cp5;
    std::cout << cp5 << std::endl;

    Sales_data s1("book1", 150, 10);
    Sales_data s2("book1", 200, 20);

    std::cout << s1 << std::endl;

    // Assignment
    s1 = s1 + s2;
    std::cout << s1 << std::endl;

    // Compound assignment
    s1 += s2;
    std::cout << s1 << std::endl;

    // Compound substraction
    s1 -= s2;
    std::cout << s1 << std::endl;

    // Substraction
    s1 = s1 - s2;
    std::cout << s1 << std::endl;
    return 0;
}