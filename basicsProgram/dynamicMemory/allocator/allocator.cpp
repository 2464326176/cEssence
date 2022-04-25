//**************************
// Author:  yh
// Time:    2021/12/26
//**************************
#include "allocator.h"

void inputReverseOutputString(size_t n) {
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string str;
    auto q = p;
    while(q != p + n && std::cin >> str) {
        alloc.construct(q++, str);
    }

    while(q != p) {
        cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}


int main() {
    inputReverseOutputString(5);
    return 0;
}
