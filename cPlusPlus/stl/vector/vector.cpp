//**************************
// Author:  yh
// Time:    2022/1/1
//**************************

#include "vector.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void _print(vector<T> &V) {
    for(auto &v : V) {
        cout << v << " ";
    }
    cout << endl;
}

int _insert() {
    vector<int> vInt;
    vector<int> vInt1;

    vInt.push_back(3);
    vInt.push_back(6);
    vInt.push_back(7);
    vInt.push_back(1);
    vInt.push_back(2);
    _print(vInt);

    vInt1.push_back(1);
    vInt1.push_back(1);
    vInt1.push_back(1);
    vInt1.push_back(1);
    vInt1.push_back(1);
    _print(vInt1);

    vInt.insert(vInt.begin(), 111);
    _print(vInt);
    vInt.insert(vInt.begin(), 4, 222);
    _print(vInt);
    vInt.insert(vInt.begin(), vInt1.begin(), vInt1.end());
    _print(vInt);
    return 0;
}

void _erase() {
    vector<int> vInt{1, 2, 3, 4};
    _print(vInt);
    vInt.erase(vInt.begin());
    _print(vInt);
    vInt.erase(vInt.begin(), vInt.end() - 1);
    _print(vInt);
    vInt.clear();
    _print(vInt);
}

int main() {
    //_insert();
    _erase();
    return 0;
}