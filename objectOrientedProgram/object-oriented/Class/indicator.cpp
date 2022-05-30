/*
 * @Author: yh
 * @Date: 2022/5/22 14:31
 * @Description: 
 * @FilePath: indicator.cpp
 */

#include <iostream>
#include <string>


using namespace std;

class Base {
public:
    Base() { std::cout << " Base() " << endl; }

    ~Base() { std::cout << " ~Base() " << endl; }

    void print() { std::cout << " age: " << age << " name: " << name << endl; }
    void serName() { std::cout << " print() " << endl; }
    void setAge() { std::cout << " print() " << endl; }

private:
    int age;
    string name;
};

class Derived : Base {

};

int main() {


    return 0;
}