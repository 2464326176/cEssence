/*
 * @Author: yh
 * @Date: 2022/9/11 20:39
 * @Description: 
 * @FilePath: object.h
 */

#ifndef CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_OBJECT_H
#define CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_OBJECT_H
#include <iostream>
#include <string>

using namespace std;

class object {
public:
    object() {
        cout << "object()" << endl;
        this->num = 0;
        this->name = "";
    }
    
    object(int num, string name) : num(num), name(name) {
        cout << "object(int num, int name)" << " num: " << num << " name: " << name << endl;
    }
    
    object(const object &obj) {
        this->num = obj.num;
        this->name = obj.name;
        cout << "object(object &obj)" << " num: " << num << " name: " << name << endl;
    }
    
    object(const object &&obj) {
        this->num = obj.num;
        this->name = obj.name;
        cout << "object(object &&obj)" << " num: " << num << " name: " << name << endl;
    }
    
    object &operator=(const object &obj) {
        this->num = obj.num;
        this->name = obj.name;
        cout << "object &operator=(object &obj)" << " num: " << num << " name: " << name << endl;
        return *this;
    }
//
//    object &operator=(const object &&obj) {
//        this->num = obj.num;
//        this->name = obj.name;
//        cout << "object &operator=(object &&obj)" << " num: " << num << " name: " << name << endl;
//        return *this;
//    }
    
    ~object() {
        cout << "~object()" << " num: " << num << " name: " << name << endl;
    }
private:
    int num;
    string name;
};

#endif //CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_OBJECT_H
