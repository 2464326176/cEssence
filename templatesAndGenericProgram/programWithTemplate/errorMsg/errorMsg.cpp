//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#include "errorMsg.h"
template<typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << t;
}

template<typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest)
{
    os << t << ",";
    return print(os, rest...);
}

template<typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args... rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(std::cout, 1, 2, 3, 4, 9.0f, "sss", "alan");
    print(std::cout, 1, 2, 3, 4, 9.0f, "sss", "alan");
    return 0;
}
