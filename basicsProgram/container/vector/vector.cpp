//**************************
// Author:  yh
// Time:    2022/1/1
//**************************

#include "vector.h"



template <typename T>
void _print(vector<T> &V) {
    for(auto &v : V) {
        cout << v << " ";
    }
    cout << endl;
}

// construct
void _construct() {
    vector<int> other_vec{1, 3, 7 , 9, 11, 15, 19};
    vector<int> vec1;                       // vec is empty
    vector<int> vec2(10);                // 0
    vector<int> vec3(10, 1);       // 1
    vector<int> vec4{ 1, 2, 3, 4, 5 };      // 1, 2, 3, 4, 5
    vector<int> vec5(other_vec);            // same as other_vec
    vector<int> vec6(other_vec.begin(), other_vec.end()); // same as other_vec

    _print(vec1);
    _print(vec2);
    _print(vec3);
    _print(vec4);
    _print(vec5);
    _print(vec6);
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

//find iterator
void _bound() {
    vector<int> v{1, 3, 7 , 9, 11, 15, 19};




}



int main1() {
    _construct();
    //_insert();
    //_erase();
    return 0;
}