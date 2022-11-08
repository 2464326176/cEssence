//**************************
// Author:  yh
// Time:    2021/12/26
//**************************
#include <iostream>
//#include "strvec.h"
#include <string>
#include <vector>

void vectorGrowth() {
    std::vector<std::string> v;
    //for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
    //    std::cout << v.capacity() << std::endl;
    for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
        std::cout << "size: " << v.size() << "capacity: " << v.capacity() << std::endl;
}
int main() {
    /*strVec string({"hello world!"});
    std::cout << *(string.begin());*/
    vectorGrowth();
    return 0;
}
