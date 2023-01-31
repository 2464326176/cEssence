/*
 * @Author: yh
 * @Date: 2022/11/16 0:37
 * @Description: 
 * @FilePath: copyConstruct.cpp
 */
#include <iostream>

using namespace std;

class A {
private:
    int value = 0;
public:
    A(int a) {
        value = a;
    }
    
    A(A a) {
        value = a.value;
    }
    
    void print() {
        cout << value << endl;
    }
};

int main() {
    A a = 10;
    A b = a;
    b.print();
    return 0;
}
