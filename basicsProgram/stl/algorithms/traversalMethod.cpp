//**************************
// Author:  yh
// Time:    2022/5/16
//**************************

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class printVector {
public:
    void operator()(int i) {
        printf("%d ", i);
    }
};

void printV(int i) {
    printf("%d ", i);
}


int main() {
    vector<int> vc {4, 8, 9, 7, 2};

    for_each(vc.begin(), vc.end(), [](int i){
        printf("%d ", i);
    });
    printf("\n");

    for_each(vc.begin(), vc.end(), printV);
    printf("\n");

    for_each(vc.begin(), vc.end(), printVector());
    printf("\n");
    return 0;
}