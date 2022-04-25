//**************************
// Author:  yh
// Time:    2022/1/2
//**************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>
using std::cout;
using std::endl;
using std::vector;
using std::set;

template <typename T>
void _print(vector<T> &V) {
    for(auto &v : V) {
        cout << v << " ";
    }
    cout << endl;
}
bool greatTree(int num) {
    return num > 3 ? true : false;
}

void _copy() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    std::sort(vecInt.begin(), vecInt.end());

    std::vector<int> vecInt2;
    vecInt2.resize(vecInt.size());
    std::copy(vecInt.begin(), vecInt.end(), vecInt2.begin());
    _print(vecInt2);
}

void _replace() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    std::sort(vecInt.begin(), vecInt.end());


    std::replace(vecInt.begin(), vecInt.end(), 2, 8);
    _print(vecInt);
}

void _replace_if() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);

    std::replace_if(vecInt.begin(), vecInt.end(), greatTree, 9);
    _print(vecInt);
}

void _swap() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);

    vector<int> vecInt1;
    vecInt1.push_back(0);
    vecInt1.push_back(0);
    vecInt1.push_back(0);
    vecInt1.push_back(0);
    vecInt1.push_back(0);
    vecInt1.push_back(0);

    vecInt1.swap(vecInt);

    _print(vecInt);
}
int main() {
    //_copy();
    //_replace();
    //_replace_if();
    _swap();
    return 0;
}