//**************************
// Author:  yh
// Time:    2021/12/12
//**************************

#include "overload.h"

Sales_data::Sales_data(std::istream &is) : Sales_data() {
    is >> *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream& src, Sales_data& dest) {
    double price = 0.0f;
    src >> dest.bookNo >> dest.units_sold >> price;
    if (src) {
        dest.revenue = price * dest.units_sold;
    } else {
        dest = Sales_data();
    }
    return src;
}

std::ostream& operator<<(std::istream& src, const Sales_data& dest) {
    src << dest.getBookNo() << " " << dest.units_sold << " " << dest.revenue << " " << dest.avg_price();
}

Sales_data operator+(const Sales_data& src, const Sales_data& dest) {
    Sales_data sum = dest;
    sum += src;
    return sum;
}