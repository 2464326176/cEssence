#include <iostream>

using namespace std;

typedef int (*fun[3])(int, int);

int getMaxValue(int i, int j) { return std::max(i, j); }

int getMinValue(int i, int j) { return std::min(i, j); }

int getMidValue(int i, int j) { return (i >> 1) + (j >> 1); }

int main() {
    fun f;
    f[0] = getMaxValue;
    f[1] = getMinValue;
    f[2] = getMidValue;
    int a = 5, b = 8;
    cout << f[0](a, b) << endl;
    cout << f[1](a, b) << endl;
    cout << f[2](a, b) << endl;

    return 0;
}