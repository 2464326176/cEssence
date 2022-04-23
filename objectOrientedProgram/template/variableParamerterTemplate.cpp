//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#include <iostream>

template<typename T, typename ...Args>
void foo(T t, Args ...args)
{
    std::cout << sizeof...(Args) << std::endl;  //类型参数的数目
    std::cout << "\n";
    std::cout << sizeof...(args) << std::endl;  //函数参数的数目
}

template<typename PT>
auto print(std::ostream &os, PT const &pt)-> decltype(os) {
    return os << pt;
}

template<typename PT, typename... Args>
auto print(std::ostream &os, PT const &pt, Args const&... rest)-> decltype(os) {
    return print(os << pt << ", ", rest...);
}
void text1() {
    foo(1, 2);
    foo(1, 23, "string", 5, "str");
}

void text2() {
    print(std::cout, 1) << std::endl;
    print(std::cout, 1, 2) << std::endl;
    print(std::cout, 1, 2, 3, 4, "sss", 42.4242) << std::endl;
}
int main()
{
    text2();
    return 0;
}
