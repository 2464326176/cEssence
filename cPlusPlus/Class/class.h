//**************************
// Author:  yh
// Time:    2021/11/6
//**************************

#ifndef CESSENCE_CLASS_H
#define CESSENCE_CLASS_H
#include <string>
class Books {
    Books();  // construct function
    Books(const Books&);
    Books(const std::string &bookNo, int unitsSold, double revenue);
    virtual ~Books();
    // copy construct function
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};
#endif //CESSENCE_CLASS_H
