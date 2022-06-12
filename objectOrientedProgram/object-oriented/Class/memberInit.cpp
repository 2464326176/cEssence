/*
 * @Author: yh
 * @Date: 2022/5/22 23:38
 * @Description: 
 * @FilePath: memberInit.cpp
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class demo {

public:
    // 成员初始化
    int x = 0;              // 赋值方式
    string s = "hello";     // 赋值方式
    vector<int> v{1, 2, 3}; // 花括号方式
};
int main() {
    
    return 0;
}