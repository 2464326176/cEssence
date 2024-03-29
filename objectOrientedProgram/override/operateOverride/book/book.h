/*
 * @Author: yh
 * @Date: 2023-01-29 20:44:22
 * @LastEditTime: 2023-01-29 22:53:14
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\override\operateOverride\book\book.h
 */

#ifndef OPERATE_OVERRIDE_BOOK
#define OPERATE_OVERRIDE_BOOK
#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend Book operator+(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate, unsigned number):no_(no), name_(name), author_(author), pubdate_(pubdate), number_(number) { }
    Book(std::istream &in) { in >> *this; }

    Book& operator+=(const Book&);

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
bool operator>(const Book&, const Book&);
Book operator+(const Book&, const Book&);

#endif // OPERATE_OVERRIDE_BOOK