//**************************
// Author:  yh
// Time:    2021/11/9
//**************************

#ifndef CESSENCE_STRBLOB_H
#define CESSENCE_STRBLOB_H
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <exception>

using std::string;
using std::vector;
class StrBlob {
    using size_type = vector<string>::size_type;
public:
    StrBlob(): data(std::make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> init_list):data(std::make_shared<vector<string>>(init_list)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &str) { data->push_back(str); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string& front() const{
        check(0, "front on empty StrBlob");
        return data->front();
    }

    const std::string& back() const{
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const string &msg) const{
        if(i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
private:
    std::shared_ptr<vector<string>> data;
};
#endif //CESSENCE_STRBLOB_H
