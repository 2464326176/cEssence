//**************************
// Author:  yh
// Time:    2022/4/28
//**************************
#include "salesData.h"

int readPrint() {
    SalesData total;
    if (read(std::cin, total)) {
        SalesData trans;
        while (read(std::cin, trans)) {
            if (total.isBookNo() == trans.isBookNo()) {
                total.combine(trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "no data!!!" << std::endl;
        return -1;
    }
}

void construct() {
    SalesData s1;
    print(std::cout, s1) << std::endl;

    std::string bookNo("xxx-1156-9875");
    SalesData s2(bookNo);
    print(std::cout, s2) << std::endl;

    SalesData s3("xxx-asjkaa-6576", 4.8, 9);
    print(std::cout, s3) << std::endl;

    SalesData s4(std::cin);
    print(std::cout, s4) << std::endl;

    /*SalesData s5("xxx-1156-9875");
    print(std::cout, s5) << std::endl;*/ // error
}


int main() {
    construct();

    return 0;
}