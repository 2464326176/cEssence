/*
 * @Author: yh
 * @Date: 2023-02-14 00:45:11
 * @LastEditTime: 2023-02-14 00:45:16
 * @Description:
 * @FilePath: \cEssence\exceptionHandling\tryCatch.cpp
 */
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

void MyFunc(int c) {
    if (c > numeric_limits<char>::max())
        throw invalid_argument("MyFunc argument too large.");
    //...
}

int main() {
    try {
        MyFunc(256); // cause an exception to throw
    }

    catch (invalid_argument &e) {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}