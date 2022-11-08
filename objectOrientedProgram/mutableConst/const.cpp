/*
 * @Author: yh
 * @Date: 2022/9/16 3:01
 * @Description: 
 * @FilePath: const.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class triangular {
    int getLength() const { return length; }
    int getBegPos() const { return begPos; }
    int getElem(int pos) { return elems[pos - 1]; }
    // error 修改了 next的值
//    bool getNext(int &val) const {
//        if (next<begPos + length - 1) {
//            val = elems[next++];
//            return true;
//        }
//        return false;
//    }
    void next_val() { next = begPos - 1; }
private:
    int length;
    int begPos;
    int next;
    static vector<int> elems;
};

class obj {
public:
    obj(int i = 0) : val(i) {};
    const int &getVal() const {
        return val;
    }
    int &getVal() {
        return val;
    }
private:
    int val;
};

void swapObj(const obj *pObj, obj &refObj) {
    cout << pObj->getVal() << endl;
    cout << refObj.getVal() << endl;
}

int main() {
    obj obj1(2), obj2(3);
    swapObj(&obj1, obj2);
    return 0;
}