/*
 * @Author: yh
 * @Date: 2022/9/12 0:00
 * @Description: 
 * @FilePath: String.cpp
 */
#include "String.h"
#include <algorithm>
#include <iostream>

#define PRINT_FUN_NAME std::cout << "funtion name" << __func__ << std::endl;

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e) {
    PRINT_FUN_NAME;
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char *first, const char *last) {
    PRINT_FUN_NAME;
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s) {
    PRINT_FUN_NAME;
    char *sl = const_cast<char *>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

String::String(const String &rhs) {
    PRINT_FUN_NAME;
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String::String(String &&rhs) noexcept: elements(rhs.elements), end(rhs.end) {
    PRINT_FUN_NAME;
    rhs.elements = rhs.end = nullptr;
}

void String::free() {
    PRINT_FUN_NAME;
    if (elements) {
        std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String() {
    PRINT_FUN_NAME;
    free();
}

String &String::operator=(const String &rhs) {
    PRINT_FUN_NAME;
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

String &String::operator=(String &&rhs) noexcept {
    PRINT_FUN_NAME;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    return *this;
}
