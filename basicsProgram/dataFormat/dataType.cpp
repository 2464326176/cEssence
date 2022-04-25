//
// Created by 24643 on 2021/10/21.
//
#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;
int main() {
    cout << 0x11 << endl;
    cout << 0b11 << endl;
    cout << 011 << endl;
    cout << 11 << endl;
    int num = 10;
    //cout << "Binary：" << bitset<8>(num) << endl;
    //cout << "Binary：" << setbase(2) << num << endl;
    cout << "octal: " << oct << num << endl;
    cout << "decimal: " << dec << num << endl;
    cout << "hexadecimal: " << hex << num << endl;

    return 0;
}
