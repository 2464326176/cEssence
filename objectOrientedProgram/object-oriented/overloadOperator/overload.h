//**************************
// Author:  yh
// Time:    2021/12/12
//**************************

#ifndef CESSENCE_OVERLOAD_H
#define CESSENCE_OVERLOAD_H
#include <iostream>
#include <iostream>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::istream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(std::istream &is);

    Sales_data& operator+=(const Sales_data&);
    std::string getBookNo() const { return bookNo; }
private:
    inline double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    };
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CESSENCE_OVERLOAD_H
