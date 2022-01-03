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

void _sort() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    std::sort(vecInt.begin(), vecInt.end());
    _print(vecInt);
}

void _reverse() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    std::reverse(vecInt.begin(), vecInt.end());
    _print(vecInt);
}

void _random_shuffle() {
    srand(std::time(0));
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    std::random_shuffle(vecInt.begin(), vecInt.end());
    _print(vecInt);
}

void _merge() {
    srand(std::time(0));
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(5);


    vector<int> vecInt1;
    vecInt.push_back(3);
    vecInt.push_back(4);
    vecInt.push_back(2);

    std::merge(vecInt.begin(), vecInt.end(), vecInt1.begin(), vecInt1.end(), vecInt.begin());
    _print(vecInt);
}
int main() {
    //_sort();
    //_reverse();
    //_random_shuffle();
    _merge();
    return 0;
}