//**************************
// Author:  yh
// Time:    2021/12/30
//**************************
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "map.h"

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::make_pair;
using std::multimap;
/*1个key值可以对应多个value  =分组
公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人）
人员信息有：姓名，年龄，电话、工资等组成
通过 multimap进行 信息的插入、保存、显示
分部门显示员工信息 */

typedef enum {
    SALE_DEPARTMENT,
    DEVELOPMENT_DEPARTMENT,
    FINANCIAL_DEPARTMENT,
}DEPARTMENT;

typedef enum {
    NAME,
    AGE,
    PHONENUM,
    SALARY
}STAFFINFOTYPE;

struct staffInfo{
string name{""};
size_t age{0};
size_t phoneNum{0};
float salary{0};
    staffInfo() {}
    template<typename V>
    staffInfo(STAFFINFOTYPE _k, V &_v) {
        (NAME == _k) ? name(_v)
        : (AGE == _k) ? age(_v)
        : nullptr;
    }
    staffInfo(string _name, size_t _age, size_t _phoneNum, float _salary)
        : name(_name), age(_age), phoneNum(_phoneNum), salary(_salary) {
    };

    bool operator<(const staffInfo &_staffInfo) {
        return (name == _staffInfo.name) ? true
                : (age == _staffInfo.age) ? true
                : (phoneNum == _staffInfo.phoneNum) ? true
                : false;
    }

    bool operator()(const string &_name) {
        return (name == _name);
    }

    bool operator()(const size_t &_age) {
        return (age == _age);
    }

    bool operator()(const staffInfo &_staffInfo) {
        return (name == _staffInfo.name) ? true
            : (age == _staffInfo.age) ? true
            : (phoneNum == _staffInfo.phoneNum) ? true
            : false;
    }
};

typedef multimap<DEPARTMENT, staffInfo>::iterator lIt;
multimap<DEPARTMENT, staffInfo>::size_type sz_type;

class map_value_finder
{
public:
    map_value_finder(const staffInfo &_staffInfo):m_staffInfo(_staffInfo) { }
    bool operator ()(const multimap<DEPARTMENT, staffInfo>::value_type &pair)
    {
        return (m_staffInfo.name == pair.second.name) ? true
            : (m_staffInfo.age == pair.second.age) ? true
            : (m_staffInfo.phoneNum == pair.second.phoneNum) ? true
            : false;
    }
private:
    const staffInfo &m_staffInfo;
};


void _insert(multimap<DEPARTMENT, staffInfo>*_info) {
    staffInfo sale1("sale1", 12, 1234, 100);
    staffInfo sale2("sale2", 14, 12345, 123);
    staffInfo development1("c++", 12, 123456, 100);
    staffInfo development2("java", 15, 23456, 106);
    staffInfo development3("python", 17, 23456, 107);
    staffInfo financial1("finance1", 12, 3456, 101);
    staffInfo financial2("finance2", 18, 3456, 102);
    _info->insert(pair<DEPARTMENT, staffInfo>(SALE_DEPARTMENT, sale1));
    _info->insert(pair<DEPARTMENT, staffInfo>(SALE_DEPARTMENT, sale2));

    _info->insert(make_pair(DEVELOPMENT_DEPARTMENT, development1));
    _info->insert(make_pair(DEVELOPMENT_DEPARTMENT, development2));
    _info->insert(make_pair(DEVELOPMENT_DEPARTMENT, development3));

    _info->insert(multimap<DEPARTMENT, staffInfo>::value_type(FINANCIAL_DEPARTMENT, financial1));
    _info->insert(multimap<DEPARTMENT, staffInfo>::value_type(FINANCIAL_DEPARTMENT, financial1));
    //sNameTable[5] = "string";
}

void _print(multimap<DEPARTMENT, staffInfo>::const_iterator &it) {
    cout << "department: " << ((SALE_DEPARTMENT == it->first) ? "sale"
        : (DEVELOPMENT_DEPARTMENT == it->first) ? "develop"
        : (FINANCIAL_DEPARTMENT == it->first) ? "finance" : " ")
        << "name: " << it->second.name << "age: " << it->second.age
        << "phone num: " << it->second.phoneNum << "salary: "
        << it->second.salary << endl;
}

void _print(lIt &it) {
    cout << "department: " << ((SALE_DEPARTMENT == it->first) ? "sale"
        : (DEVELOPMENT_DEPARTMENT == it->first) ? "develop"
        : (FINANCIAL_DEPARTMENT == it->first) ? "finance" : " ")
        << "name: " << it->second.name << "age: " << it->second.age
        << "phone num: " << it->second.phoneNum << "salary: "
        << it->second.salary << endl;
}

void _traverse(multimap<DEPARTMENT, staffInfo>*_info) {
    multimap<DEPARTMENT, staffInfo>::const_iterator it;
    for(it = _info->cbegin(); it != _info->cend(); ++it) {
        _print(it);
    }
}



void _findInDepartment(multimap<DEPARTMENT, staffInfo>*_info, DEPARTMENT _department) {
    pair<lIt, lIt> pos = _info->equal_range(_department);
    while(pos.first != pos.second) {
        _print(pos.first);
        ++pos.first;
    }
}

void _findInName(multimap<DEPARTMENT, staffInfo>*_info) {
    /*std::for_each(_info->cbegin(), _info->cend(), [&](const multimap<DEPARTMENT, staffInfo> _mmap){
        if() {

        } else {

        }
    });*/
}

void _findInAge(multimap<DEPARTMENT, staffInfo>*_info, size_t _age) {

}

void _findInPhoneNum(multimap<DEPARTMENT, staffInfo>*_info) {

}

void _findInSalary(multimap<DEPARTMENT, staffInfo>*_info) {

}

int main() {
    multimap<DEPARTMENT, staffInfo> sInfo;
    _insert(&sInfo);
    _traverse(&sInfo);
    _findInDepartment(&sInfo, DEVELOPMENT_DEPARTMENT);
    // find name

    // find age

    // find phone num
    /*
    it = find_if(sInfo.begin(), sInfo.end(), );
    it = find_if(sInfo.begin(), sInfo.end(), );*/
    /*_findInAge(&sInfo, 14);
    _findInName();
    _findInSalary();
    _findInPhoneNum()*/
    return 0;
}