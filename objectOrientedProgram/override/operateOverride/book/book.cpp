/*
 * @Author: yh
 * @Date: 2023-01-29 20:44:29
 * @LastEditTime: 2023-01-29 22:53:33
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\override\operateOverride\book\book.cpp
 */
#include "book.h"

std::istream& operator>>(std::istream &in, Book &book)
{
    in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.number_;
    return in;
}

std::ostream& operator<<(std::ostream &out, const Book &book)
{
    out << book.no_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_ << " " << book.number_ << std::endl;
    return out;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs)
{
    return lhs.no_ < rhs.no_;
}

bool operator>(const Book &lhs, const Book &rhs)
{
    return rhs < lhs;
}

Book& Book::operator+=(const Book &rhs)
{
    if (rhs == *this)
        this->number_ += rhs.number_;

    return *this;
}

Book operator+(const Book &lhs, const Book &rhs)
{
    Book book = lhs;
    book += rhs;
    return book;
}
