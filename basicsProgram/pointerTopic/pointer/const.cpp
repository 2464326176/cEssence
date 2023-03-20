/*
 * @Author: yh
 * @Date: 2023-03-17 01:16:34
 * @LastEditTime: 2023-03-17 01:23:01
 * @Description:
 * @FilePath: \cEssence\basicsProgram\pointerTopic\pointer\const.cpp
 */
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char const *str1 = "abc";
    char *const str2 = "acv";

    // str1[1] = 'A'; // Compilation error
    //*str1[2] = 'l'; // Compilation error
    //*str1 = "xyz"; // Compilation error
    str1 = "asdasd";

    str2[1] = 'A';
    //*str2[2] = 'l'; // Compilation error
    //*str2 = "xyz"; // Compilation error
    // str2 = "asdasd"; // Compilation error
    return 0;
}