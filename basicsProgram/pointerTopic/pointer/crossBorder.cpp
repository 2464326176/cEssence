/*
 * @Author: yh
 * @Date: 2023-03-17 01:01:42
 * @LastEditTime: 2023-03-17 01:05:18
 * @Description:
 * @FilePath: \cEssence\basicsProgram\pointerTopic\pointer\crossBorder.cpp
 */
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char ch;
    char *pStr = &ch;
    char *str{"hello"}; // cross border
    strcpy(pStr, str);
    str[2] = 'A'; // 常量无法被修改

    printf("%s %s\n", pStr, str);
    return 0;
}