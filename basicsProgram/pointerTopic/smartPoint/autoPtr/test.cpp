/*
 * @Author: yh
 * @Date: 2023/11/26 2:10
 * @Description:
 * @FilePath: test.cpp
 */

#include "test.h"


int main() {
    std::unique_ptr<Test> testPtr(new Test("test"));
    // std::unique_ptr<Test> testPtr = Test(new Test("test"));
    testPtr->showName();
    *testPtr = "test2";
    testPtr->showName();
    return 0;
}