//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#ifndef CESSENCE_ERRORMSG_H
#define CESSENCE_ERRORMSG_H
#include <iostream>
#include <memory>
#include <sstream>

template<typename T>
std::string debug_rep(const T& t);
template<typename T>
std::string debug_rep(T* p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);


template<typename T>
std::string debug_rep(const T& t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
std::string debug_rep(T* p) {
    std::ostringstream ret;
    ret << (p ? (" " << debug_rep(p)) : "null pointer");
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

std::string debug_rep(char* p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return  debug_rep(std::string(p));
}


#endif //CESSENCE_ERRORMSG_H
