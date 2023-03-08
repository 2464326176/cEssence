//**************************
// Author:  yh
// Time:    2022/1/2
//**************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

int myrandom(int i) { return std::rand() % i; }

int myCompare(int x, int y) {
    return x > y;
}

template<typename T>
void _print(vector<T> &V) {
    for (auto &v: V) {
        cout << v << " ";
    }
    cout << endl;
}

bool greatTree(int num) {
    return num > 3 ? true : false;
}

void _sort() {
    vector<int> vecInt{1, 8, 9, 36, 7, 2};
    std::sort(vecInt.begin(), vecInt.end());
    _print(vecInt);
}

void _reverse() {
    vector<int> vecInt{1, 8, 9, 36, 7, 2};
    std::reverse(vecInt.begin(), vecInt.end());
    _print(vecInt);
}

void _random_shuffle() {
    srand((unsigned int) time(NULL));
    vector<int> vecInt{1, 8, 9, 36, 7, 2};
    std::random_shuffle(vecInt.begin(), vecInt.end());
    _print(vecInt);
    std::random_shuffle(vecInt.begin(), vecInt.end(), myrandom);
    _print(vecInt);
}

void _merge() {
    srand(std::time(0));
    vector<int> vecInt{1, 8, 9, 36, 7, 2};
    vector<int> vecInt1 {3, 4, 2};
    std::merge(vecInt.begin(), vecInt.end(), vecInt1.begin(), vecInt1.end(), vecInt.begin());
    _print(vecInt);
}

void _partial_sort() {
    int myArray[] = {1, 6, 8, 4, 3, 2, 3, 5, 1};
    printf("%d %d\n", sizeof(myArray), sizeof(myArray) / sizeof(int));
    vector<int> v(myArray, myArray + sizeof(myArray) / sizeof(int));
    _print(v);
    //stable_sort(v.begin(), v.end());// 1 1 2 3 3 4 5 6 8
    partial_sort(v.begin(), v.begin() + 4, v.end());// 8 6 5 4 3 3 2 1 1
    //partial_sort(v.begin(), v.end(), myCompare);// 8 6 5 4 3 3 2 1 1
    _print(v);
}

int main() {
    //_sort();
    //_reverse();
    _random_shuffle();
    //_merge();
    //_partial_sort();
    return 0;
}