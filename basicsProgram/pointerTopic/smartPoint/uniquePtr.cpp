//**************************
// Author:  yh
// Time:    2021/12/19
//**************************
#include <iostream>
#include <memory>
#include <vector>
#include "smartPoint.h"

std::unique_ptr<programming> programmingFactory(const int& age, const std::string& name) {
    return std::make_unique<programming>(age, name);
}

void makePerson() {
    auto person = std::make_unique<programming>(18, "cplusplus");
    person->coutParam();
    std::vector<std::string> name = {person->getName()};
    std::unique_ptr<programming> person2 = std::move(person);
    person2->coutParam();
    auto person3 = programmingFactory(19, "java");
    person3->coutParam();
    return;
}

void personVector()
{
    std::vector<std::unique_ptr<programming>> persons;

    // Create a few new unique_ptr<person> instances
    // and add them to vector using implicit move semantics.
    persons.push_back(std::make_unique<programming>(12, "Juice"));
    persons.push_back(std::make_unique<programming>(13, "Funky Town"));
    persons.push_back(std::make_unique<programming>(14, "Kimi ga Iru Dake de"));
    persons.push_back(std::make_unique<programming>(15, "Poker Face"));

    // Pass by const reference when possible to avoid copying.
    for (const auto& person : persons)
    {
        std::cout << "Artist: " << person->getAge() << " Title: " << person->getName() << std::endl;
    }
}


class MyClass
{
private:
    // MyClass owns the unique_ptr.
    std::unique_ptr<programming> factory;
public:

    // Initialize by using make_unique with ClassFactory default constructor.
    MyClass() : factory (std::make_unique<programming>())
    {
    }

    void MakeClass()
    {
        factory->coutParam();
    }
};


int main() {
    //makePerson();
    //personVector();

    auto p = std::make_unique<int[]>(5);
    // Initialize the array.
    for (int i = 0; i < 5; ++i)
    {
        p[i] = i;
        std::cout << p[i] << std::endl;
    }

    return 0;
}