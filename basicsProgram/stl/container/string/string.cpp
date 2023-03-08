/*
 * @Author: yh
 * @Date: 2022-12-23 15:23:07
 * @LastEditTime: 2023-02-25 01:33:34
 * @Description:
 * @FilePath: \cEssence\basicsProgram\stl\container\string\string.cpp
 */
#include <iostream>
#include <new>
#include <string>

using namespace std;
/*operator new(size_t size) {

}*/

int main() {
    std::string str;
    for (int i = 0; i < 256; ++i) {
        std::string str1;
        str1.reserve(64);
        str1 = to_string(i);
        printf("%p, %d %d\n", &str, str.size(), str.capacity());
        str += str1;
    }

    return 0;
}