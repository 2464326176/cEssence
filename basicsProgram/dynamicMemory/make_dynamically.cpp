//**************************
// Author:  yh
// Time:    2021/11/9
//**************************
#include <string>
#include <vector>
#include <iostream>
#include <memory>
using Ptr = std::vector<int>*;

auto make_dynamically() {
    return new std::vector<int> {};
}

Ptr populate(Ptr vec) {
    for (int i; std::cout << "please enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

auto print(Ptr vec) -> std::ostream&
{
    for (auto i : *vec) std::cout << i << " ";
    return std::cout;
}

using Sptr = std::shared_ptr <std::vector<int>> ;

auto make_with_shared_ptr()
{
    return std::make_shared<std::vector<int>>();
}

auto populate(Sptr vec)
{
    for (int i; std::cout << "Pls Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

auto print(Sptr vec) -> std::ostream&
{
    for (auto i : *vec) std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = populate(make_with_shared_ptr());
    print(vec) << std::endl;

    return 0;
}
