/*
 * @Author: yh
 * @Date: 2022/5/26 23:45
 * @Description: 
 * @FilePath: weak_ptr.h
 */

#ifndef CESSENCE_BASICSPROGRAM_DYNAMICMEMORY_SMARTPOINT_WEAK_PTR_WEAK_PTR_H
#define CESSENCE_BASICSPROGRAM_DYNAMICMEMORY_SMARTPOINT_WEAK_PTR_WEAK_PTR_H
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;

class StrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
    
    StrBlobPtr begin();
    StrBlobPtr end();
    
    using size_type = vector<string>::size_type;
    
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> ls) : data(make_shared<vector<string>>(ls)) {}
    
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    
    void push_back(const string &t) { data->push_back(t); }
    void pop_back() {
        check(0, "front on empty StrBlob");
        data->front();
    }
    
    string &front(const string &t) {
        check(0, "front on empty StrBlob");
        
        return data->front();
    }
    
    string &back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    
    const string &front(const string &t) const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    
    const string &back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }
private:
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) {
            throw out_of_range(msg);
        }
    }

private:
    std::shared_ptr<vector<string>> data;
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {};
    string &deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    };
    StrBlobPtr &incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    };

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw runtime_error("unbound StrBlobPtr");
        }
        
        if (i >= ret->size()) {
            throw out_of_range(msg);
        }
        return ret;
    };

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

#endif //CESSENCE_BASICSPROGRAM_DYNAMICMEMORY_SMARTPOINT_WEAK_PTR_WEAK_PTR_H
