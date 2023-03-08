/*
 * @Author: yh
 * @Date: 2023-02-02 20:49:18
 * @LastEditTime: 2023-02-02 20:52:12
 * @Description:
 * @FilePath: \cEssence\basicsProgram\stl\container\algorithms\all_of.cpp
 */
#include <algorithm> // std::all_of
#include <array>     // std::array
#include <iostream>  // std::cout

int main() {
    std::array<int, 8> foo = {3, 8, 7, 11, 13, 17, 19, 23};

    if (std::all_of(foo.begin(), foo.end(), [](int i) { return i % 2; })) {
        std::cout << "All the elements are odd numbers.\n";
    }

    return 0;
}