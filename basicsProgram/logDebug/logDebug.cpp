//**************************
// Author:  yh
// Time:    2022/4/25
//**************************

#include "logDebug.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
//__FILE__ 文件名字
//__LINE__ 当前行
//__TIME__ 编译的时间
//__DATA__ 编译的日期
//__func__ 文件名字


//#define DEBUG_LOG_INFO (__FILE__, __LINE__, __TIME__, __DATE__, __func__)

void printVec(vector<int> &vec)
{
#ifdef ENABLE_DEBUG
    //cout << DEBUG_LOG_INFO << endl;
    printf("%s %d  %s", __FILE__, __LINE__, __func__);
    cout << "vector size: " << vec.size() << endl;
#endif
}

int main()
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printVec(vec);
    cout << endl;

    return 0;
}
