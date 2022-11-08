//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#include "errorMsg.h"

template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &... rest) {
    os << t << ",";
    return print(os, rest...);
}

// packet extension
template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args... rest) {
    //return print(os, debug_rep(rest...)); //error
    // print(os, debug_rep(4, 9.0f, "sss", "alan"))
    return print(os, debug_rep(rest)...);
    // print(os, debug_rep(4), debug_rep(9.0f), debug_rep("sss"), debug_rep("alan"))
}

int main() {
    errorMsg(std::cout, 4, 9.0f, "sss", "alan");
    //print(std::cout, 1, 2, 3, 4, 9.0f, "sss", "alan");
    return 0;
}
