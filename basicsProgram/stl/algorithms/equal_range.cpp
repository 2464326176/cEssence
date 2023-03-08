/*
 * @Author: yh
 * @Date: 2023-02-02 22:23:28
 * @LastEditTime: 2023-02-02 22:35:40
 * @Description:
 * @FilePath: \cEssence\basicsProgram\stl\container\algorithms\equal_range.cpp
 */

#include <algorithm> // std::equal_range, std::sort
#include <iostream>  // std::cout
#include <vector>    // std::vector

bool mygreater(int i, int j) { return (i > j); }

int main() {
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
    std::vector<int> v(myints, myints + 8); // 10 20 30 30 20 10 10 20
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;

    // using default comparison:
    std::sort(v.begin(), v.end());                     // 10 10 10 20 20 20 30 30
    bounds = std::equal_range(v.begin(), v.end(), 20); //          ^        ^

    std::cout << bounds.first - v.begin() << " " << bounds.second - v.begin() << std::endl;
    // using "mygreater" as comp:
    std::sort(v.begin(), v.end(), mygreater);                     // 30 30 20 20 20 10 10 10
    bounds = std::equal_range(v.begin(), v.end(), 20, mygreater); //       ^        ^
    std::cout << bounds.first - v.begin() << " " << bounds.second - v.begin() << std::endl;
    /*std::cout << "bounds at positions " << (bounds.first - v.begin());
    std::cout << " and " << (bounds.second - v.begin()) << '\n';*/

    return 0;
}