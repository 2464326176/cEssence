/*
 * @Author: yh
 * @Date: 2023-01-08 15:23:37
 * @LastEditTime: 2023-01-08 15:47:59
 * @Description: 
 * @FilePath: \algorithm\practice\bit\resetBit.cpp
 */
#include <iostream>
#include <bitset>
#define BIT_MASK(bitPos) (0X01 << (bitPos))

bool bitReset(unsigned int *val, unsigned char pos) {
    if (pos > sizeof(unsigned int) * 8) {
        return false;
    }

    *val = (*val & ~BIT_MASK(pos));
    return true;
}


int main() {
    unsigned int x = 0Xff;
    unsigned char y = 4;
    std::cout << std::bitset<8>(y) << " |" << std::bitset<8>(~BIT_MASK(y)) << std::endl;
    bitReset(&x, y);

    std::cout << std::hex << x << std::endl;
    return 0;
}