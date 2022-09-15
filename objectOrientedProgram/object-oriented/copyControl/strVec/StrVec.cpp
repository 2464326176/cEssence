/*
 * @Author: yh
 * @Date: 2022/9/12 23:55
 * @Description: 
 * @FilePath: StrVec.cpp
 */

#include "StrVec.h"
#include <algorithm>
void StrVec::push_back(const string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free, [this](std::string &rhs) { alloc.destroy(&rhs); });
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::range_initialize(const std::string *first, const std::string *last) {
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &rhs) {
    range_initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    range_initialize(il.begin(), il.end());
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap) {
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap) {
    if (new_cap <= capacity())
        return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count) {
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s) {
    if (count > size()) {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    } else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

StrVec::StrVec(StrVec &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap) {
// leave s in a state in which it is safe to run the destructor.
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.
            elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}