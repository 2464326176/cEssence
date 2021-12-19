//**************************
// Author:  yh
// Time:    2021/12/19
//**************************

#ifndef CESSENCE_SMARTPOINT_H
#define CESSENCE_SMARTPOINT_H
#include <memory>
class largeObject {
public:
    void doSomething() {
        std::cout << "do something" << std::endl;
    };

    void setParam(int _age, std::string _name) {
        age = _age;
        name = _name;
    }

    void coutParam() {
        std::cout << "age: " << age << "name: " << name << std::endl;
    }
private:
    int age;
    std::string name;
};

class programming {
public:
    programming() {

    }
    programming(int _age, std::string _name) : age(_age), name(_name) {

    }
    void setParam(int _age, std::string _name) {
        age = _age;
        name = _name;
    }

    void coutParam() {
        std::cout << "age: " << age << "name: " << name << std::endl;
    }
    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
private:
    int age;
    std::string name;
};
void processLargeObject(const largeObject& lo) {
    std::cout << "process...." << std::endl;
}

void LegacyLargeObjectFunction(const largeObject* lo) {
    std::cout << "LegacyLargeObjectFunction...." << std::endl;
}

void useRawPointer() {
    int* intPtr = new int(1);
    delete intPtr;
}

void useSmartPoint() {
    std::unique_ptr<int> intPtr(new int(1));
    std::unique_ptr<largeObject> pLarge(new largeObject());
    pLarge->doSomething();
    processLargeObject(*pLarge);
    LegacyLargeObjectFunction(pLarge.get());
    pLarge.reset();  //release the memory before we exit function block
}
#endif //CESSENCE_SMARTPOINT_H
