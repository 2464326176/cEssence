/*
 * @Author: yh
 * @Date: 2022/6/12 13:52
 * @Description: 
 * @FilePath: reloadTemplate.cpp
 */
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

// always declare first:
template<typename T>
std::string debug_rep(const T &t);

template<typename T>
std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char *p);
std::string debug_rep(const char *p);
// print any type we don't otherwise.
template<typename T>
std::string debug_rep(const T &t) {
    printf("debug_rep(const T &t)\n");
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// print pointers as their pointer value, followed by the object to which the pointer points
template<typename T>
std::string debug_rep(T *p) {
    printf("debug_rep(T *p)\n");
    std::ostringstream ret;
    ret << "pointer: " << p;
    
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    
    return ret.str();
}
// non-template version
std::string debug_rep(const std::string &s) {
    printf("debug_rep(const std::string &s)\n");
    return '"' + s + '"';
}

// convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p) {
    printf("debug_rep(char *p)\n");
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    printf("debug_rep(const char *p)\n");
    return debug_rep(std::string(p));
}

void print(const string &str) {
    cout << str << endl;
}
int main() {
    int *p = new int(1024);
    int i = 42;
    char cStr[20]{"hello world!!!"};
    string str("this is one day!!!");
    
    print(debug_rep(p));
    print(debug_rep(i));
    print(debug_rep(cStr));
    print(debug_rep(str));
    
    return 0;
}
