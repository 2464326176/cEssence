//**************************
// Author:  yh
// Time:    2022/4/27
//**************************

#include "salesData.h"

SalesData &SalesData::combine(const SalesData &salesData) {
    //this->bookNo;
    this->units_sold += salesData.units_sold;
    this->revenue += salesData.revenue;
    return *this;
}


std::istream &read(std::istream &is, SalesData &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const SalesData &item) {
    os << item.isBookNo() << " " << item.units_sold << " " << item.revenue;
    return os;
}

SalesData& add(const SalesData &lhs, const SalesData &rhs) {
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}


SalesData::SalesData(std::istream &is) {
    read(is, *this);
}
