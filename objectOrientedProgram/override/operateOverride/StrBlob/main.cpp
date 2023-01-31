/*
 * @Author: yh
 * @Date: 2023-01-29 23:11:09
 * @LastEditTime: 2023-01-30 21:55:54
 * @Description:
 * @FilePath: \cEssence\objectOrientedProgram\override\operateOverride\StrBlob\main.cpp
 */
#include "StrBlob.h"
#include <iostream>

int main() {
    StrBlob sb{"Hello", "World", "Pezy"};

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;

    StrBlob sb1{"a", "b", "c"};
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) {
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter != sb1.cend(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }

    ConstStrBlobPtr iter(sb2);
    std::cout << iter->size() << std::endl;

    return 0;
}
