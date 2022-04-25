//**************************
// Author:  yh
// Time:    2022/1/2
//**************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>
#include <numeric>
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

void _fill() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    std::fill(vecInt.begin(), vecInt.end(), 9);
    _print(vecInt);
}

void _accomulate() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    cout << std::accumulate(vecInt.begin(), vecInt.end(), 0) << endl;
    _print(vecInt);
}

/*
set_union:  构造一个有序序列，包含两个有序序列的并集。
set_intersection:  构造一个有序序列，包含两个有序序列的交集。
set_difference:  构造一个有序序列，该序列保留第一个有序序列中存在而第二个有序序列中不存在的元素。
*/
void _set() {
    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(7);
    vecIntA.push_back(9);

    vector<int> vecIntB;
    vecIntB.push_back(1);
    vecIntB.push_back(3);
    vecIntB.push_back(5);
    vecIntB.push_back(6);
    vecIntB.push_back(8);

    vector<int> vecIntC;
    vecIntC.resize(10);
    vector<int>::iterator it;
    it = set_union(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());		//vecIntC : {1,3,5,6,7,8,9,0,0,0}
    vecIntC.resize(it - vecIntC.begin());
    _print(vecIntC);
    fill(vecIntC.begin(),vecIntC.end(),0);
    it = set_intersection(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());		//vecIntC: {1,3,5,0,0,0,0,0,0,0}
    vecIntC.resize(it - vecIntC.begin());
    _print(vecIntC);

    fill(vecIntC.begin(),vecIntC.end(),0);
    it = set_difference(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());			//vecIntC: {7,9,0,0,0,0,0,0,0,0}
    vecIntC.resize(it - vecIntC.begin());
    _print(vecIntC);
}

int main() {
    //_fill();
    //_accomulate();
    _set();
    return 0;
}