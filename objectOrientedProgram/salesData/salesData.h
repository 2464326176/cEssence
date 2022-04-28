//**************************
// Author:  yh
// Time:    2022/4/27
//**************************

#ifndef CESSENCE_SALESDATA_H
#define CESSENCE_SALESDATA_H

#include <iostream>
#include <string>

class SalesData {
    friend std::istream &read(std::istream &is, SalesData &item);
    friend std::ostream &print(std::ostream &os, const SalesData &item);
    friend SalesData& add(const SalesData &lhs, const SalesData &rhs);
public:
    //SalesData() = default;
    //SalesData(std::string &bookNo) : bookNo(bookNo) {}
    SalesData(std::string bookNo, unsigned units_sold, double price) :
            bookNo(bookNo), units_sold(units_sold), revenue(units_sold * price) {}
    //SalesData(std::istream &is);

    SalesData() : SalesData("", 0, 0) {} // 构造函数全部委托给另外一个构造函数
    SalesData(std::string &bookNo) : SalesData(bookNo, 0, 0) {}
    SalesData(std::istream &is)  : SalesData() { read(is, *this)};



    std::string isBookNo() const { return this->bookNo; }
    SalesData &combine(const SalesData &salesData);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CESSENCE_SALESDATA_H
