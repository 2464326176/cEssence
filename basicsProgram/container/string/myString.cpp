//********************
// Author:  yh 
// Time:    2020/11/1.
// 
//********************
//
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "myString.h"

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


