//**************************
// Author:  yh
// Time:    2022/1/2
//**************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::set;

bool greatTree(int num) {
    return num > 3 ? true : false;
}

void _count() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    int iCount = count(vecInt.begin(),vecInt.end(),2);	//iCount==3
    cout << "vecInt find value 2 num: " << iCount << endl;
    int iGreatNumCount = count_if(vecInt.begin(),vecInt.end(),greatTree);	//iCount==3
    cout << "vecInt find value great 3 num: " << iGreatNumCount << endl;
}

void _find() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    vector<int>::const_iterator iCount = find(vecInt.begin(),vecInt.end(),2);	//iCount==3
    cout << "find 2 : " << *iCount << endl;

    vector<int>::const_iterator iGreatNumCount = find_if(vecInt.begin(),vecInt.end(),greatTree);	//iCount==3
    cout << "find great 3 : " << *iCount << endl;

}

void _binary_serach() {
    set<int> setInt;
    setInt.insert(3);
    setInt.insert(1);
    setInt.insert(7);
    setInt.insert(5);
    setInt.insert(9);
    bool bFind = binary_search(setInt.begin(),setInt.end(),5);
    cout << (bFind ? "find" : "not find") << endl;
}

void _adjacent_find() {
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(5);
    vector<int>::iterator it = adjacent_find(vecInt.begin(), vecInt.end());
    cout << "value : " << *it << endl;
}
int main() {
    //_binary_serach();
    //_adjacent_find();
    _find();
    return 0;
}