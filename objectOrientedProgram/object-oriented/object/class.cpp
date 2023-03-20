//**************************
// Author:  yh
// Time:    2021/11/6
//**************************

#include "class.h"

Books::Books(const Books& orig)
        : bookNo(orig.bookNo),
        units_sold(orig.units_sold),
        revenue(orig.revenue) {}

Books::Books(const std::string &bookNo, int unitsSold, double revenue)
        : bookNo(bookNo),
        units_sold(unitsSold),
        revenue(revenue) {}

Books::~Books() {

}
