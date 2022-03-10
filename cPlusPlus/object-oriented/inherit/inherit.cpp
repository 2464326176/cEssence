//**************************
// Author:  yh
// Time:    2022/3/1
//**************************

#include "inherit.h"
#include <iostream>

int main() {
    Derive d(10);
    std::cout << d.val << d.Base::val << std::endl;
    return 0;
}
