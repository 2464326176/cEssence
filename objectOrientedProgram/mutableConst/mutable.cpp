/*
 * @Author: yh
 * @Date: 2022/9/16 3:23
 * @Description: 
 * @FilePath: mutable.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class triangular {
    int getLength() const { return length; }
    int getBegPos() const { return begPos; }
    int getElem(int pos) { return elems[pos - 1]; }
    bool getNext(int &val) const {
        if (next<begPos + length - 1) {
            val = elems[next++];
            return true;
        }
        return false;
    }
    void next_val() { next = begPos - 1; }
private:
    int length;
    int begPos;
    mutable int next;
    static vector<int> elems;
};