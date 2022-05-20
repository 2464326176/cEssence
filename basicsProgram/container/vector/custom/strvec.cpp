//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#include "strvec.h"

strVec::strVec(std::initializer_list<std::string> _list) {
    std::string* const newData = alloc.allocate(_list.size());
    auto p = newData;
    for(const auto &_str : _list) {
        alloc.construct(p++, _str);
    }
    element = newData;
    first_free = cap = element + _list.size();
}
// copy construct function
strVec::strVec(const strVec &_str) {
    std::pair<std::string*, std::string*> newData = alloc_n_copy(_str.begin(), _str.end());
    element = newData.first;
    first_free = newData.second;
}

strVec &strVec::operator=(const strVec &_refStr) {
    std::pair<std::string*, std::string*> newData = alloc_n_copy(_refStr.begin(), _refStr.end());
    free();
    element = newData.first;
    first_free = cap = newData.second;
    return *this;
}

/*strVec &strVec::operator+(const strVec &_refStr) {

}*/

strVec::~strVec() {
    free();
}

void strVec::push_back(const std::string &_str) {
    chk_n_alloc();
    alloc.construct(first_free++, _str);
}

void strVec::reserve(std::size_t n) {
    if(n <= capacity()) { return ;}
    wy_alloc_n_move(n);
}

void strVec::resize(std::size_t n) {
    resize(n, std::string());
}

void strVec::resize(std::size_t n, const std::string &_str) {
    if(n < size()) {
        for(auto p = element + n; p != first_free;) {
            alloc.destroy(p++);
        }
        first_free = element + n;
    } else if(n > size()) {
        for(auto i = size(); i != n; ++i) {
            push_back(std::string(_str));
        }
    }
}

void strVec::reallocate() {
    size_t newCapacity = size() ? 2 * size() : 1;
    wy_alloc_n_move(newCapacity);
}

void strVec::free() {
    if(element) {
        for(auto p = first_free; p != element;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(element, capacity());
    }
}

void strVec::wy_alloc_n_move(std::size_t n) {
    size_t newCapacity = n;
    std::string* newData = alloc.allocate(n);
    std::string* dest = newData;
    std::string* elem = element;

    for(size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    element = newData;
    first_free = dest;
    cap = element + newCapacity;
}

std::pair<std::string *, std::string *> strVec::alloc_n_copy(std::string *b, std::string *e) {
    std::string* data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}
