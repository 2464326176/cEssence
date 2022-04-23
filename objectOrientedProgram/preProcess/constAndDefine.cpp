//**************************
// Author:  yh
// Time:    2022/3/29
//**************************
#include <iostream>


#define FIND(Struct, elem) (size_t)&(((Struct*)0)->elem)
struct Struct {
    int a;
    int array[20];
    char *p;
};

int main () {
    std::cout << "a: " << FIND(Struct, a) << std::endl;
    std::cout << "array: " << FIND(Struct, array) << std::endl;
    std::cout << "p: " << FIND(Struct, p) << std::endl;

    return 0;
}