//********************
// Author:  yh 
// Time:    2020/11/1.
// 
//********************
//
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "String.h"
namespace c {

String::String(const char *str) {
    if (str == nullptr) {
        m_sptr = new char[1];
        if (m_sptr == nullptr) {
            std::cout << "registration failed!" << std::endl;
            exit(1);
        }
        m_sptr[0] = '\0';
    } else {
        m_sptr = new char[strlen(str) + 1];
        if (m_sptr == nullptr) {
            std::cout << "registration failed!" << std::endl;
            exit(1);
        }
        strcpy(m_sptr, str);
    }
}

String::String(const String &str) {
    m_sptr = new char[strlen(str.m_sptr) + 1];
    if (m_sptr == nullptr) {
        std::cout << "registration failed!" << std::endl;
        exit(1);
    }
    strcpy(m_sptr, str.m_sptr);
}

String &String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }
    delete[] m_sptr;
    
    m_sptr = new char[strlen(other.m_sptr) + 1];
    if (m_sptr == nullptr) {
        std::cout << "registration failed!" << std::endl;
        exit(1);
    }
    strcpy(m_sptr, other.m_sptr);
    
    return *this;
}

String::~String() {
    delete[] m_sptr;
}
}

namespace cPlusPlus {

String::String() {
    m_sptr = new char[1];
    m_sptr[0] = '\0';
}

String::~String() {
    if (m_sptr) {
        delete m_sptr;
        m_sptr = nullptr;
    }
}

String::String(const char *str = nullptr) {
    if (str) {
        size_t chSize = strlen(str);
        m_sptr = new char[chSize + 1];
        if (m_sptr == nullptr) {
            std::cout << "registration failed!" << std::endl;
            exit(1);
        }
        std::copy(m_sptr, m_sptr + chSize + 1, str);
    } else {
        m_sptr = new char[1];
        m_sptr[0] = '\0';
    }
}

String::String(const String &str) {
    if (str.m_sptr) {
        size_t chSize = strlen(str.m_sptr);
        m_sptr = new char[chSize + 1];
        if (m_sptr == nullptr) {
            std::cout << "registration failed!" << std::endl;
            exit(1);
        }
        std::copy(m_sptr, m_sptr + chSize + 1, str);
    }
    
}

String &String::operator=(const String &str) {
    if (this != &str) {
        String tmpStr(str.m_sptr);
        char *pStr = tmpStr.m_sptr;
        tmpStr.m_sptr = m_sptr;
        m_sptr = pStr;
    }
    
    return *this;
}
    
}
