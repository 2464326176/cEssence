//**************************
// Author:  yh
// Time:    2021/12/14
//**************************

#include "function.h"
#include <iostream>
#include <string>
#include <tuple>
/* template function */
template<typename leftValue, typename rightValue>
auto add(const leftValue& lv, const rightValue& rv) {
    return lv + rv;
}

auto a = add(3.12, 4.56);
auto b = add(std::string{"hello "}, std::string{"world!"});

struct personInfomation {
    std::string name;
    int age;
};

std::tuple<int, double, std::string> f() {
    int tuple_int{ 2 };
    double tuple_double{ 8.89 };
    std::string tuple_string{ "apple" };
}
int main() {
    /*
    std::cout << a << std::endl;
    std::cout << b << std::endl;
     */
    {
        std::string tmpName{"yuhang"};
        int age{11};
        personInfomation tmp = {
            tmpName,
            age
        };
        std::cout << "name: " << tmp.name << "age: " << tmp.age << std::endl;
    }
    {
        auto tmp = f();
        std::cout << "int: " << get<0>(tmp) <<  "double: " << get<1>(tmp) <<  "string: " << get<2>(tmp) << std::endl;

        int v1;
        double v2;
        std::string v3;
        std::tie(v1, v2, v3) = f();
        std::cout << "[v1, v2, v3]" << v1 << " " << v2 << " " << v3 << std::endl;
    }
    return 0;
}