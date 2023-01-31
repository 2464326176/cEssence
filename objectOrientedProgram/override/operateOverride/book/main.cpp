/*
 * @Author: yh
 * @Date: 2023-01-29 20:47:03
 * @LastEditTime: 2023-01-29 20:55:03
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\override\operateOverride\book\main.cpp
 */
#include "book.h"

int main() {
    Book book1(123, "CP5", "Lippman", "2012", 3);
    Book book2(123, "CP5", "Lippman", "2012", 2);
    Book book3(123, "cp6", "c++", "2019", 1);

    Book cp5_1(12345, "CP5", "Lippmen", "2012", 2);
    Book cp5_2(12345, "CP5", "Lippmen", "2012", 4);

    std::cout << cp5_1 + cp5_2 << std::endl;

    if (book1 == book2) {
        std::cout << "book1 and book2 is equal " << book1 << std::endl;
    } else {
        std::cout << "book1 and book2 is not equal " << book1 << std::endl;
    }

    if (book1 == book3) {
        std::cout << "book1 and book3 is equal " << book1 << std::endl;
    } else {
        std::cout << "book1 and book3 is not equal " << book1 << std::endl;
    }

    return 0;
}