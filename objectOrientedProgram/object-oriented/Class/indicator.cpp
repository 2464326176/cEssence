/*
 * @Author: yh
 * @Date: 2022/5/22 14:31
 * @Description:
 * @FilePath: indicator.cpp
 */

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal() = default;
    Animal(string name, int age) : name(name), age(age) { std::cout << " Animal(string name, int age)" << endl; }
    Animal(Animal &animal) = delete;
    Animal &operator=(Animal &animal) = default;
    ~Animal() { std::cout << " ~Animal() " << endl; }
    
    explicit operator int() const {
        cout << "operator int()" << endl;
        return int(age);
    }
    virtual void printAnimal() final { cout << "animal" << endl; }
    virtual void print() { std::cout << "animal age: " << age << " name: " << name << endl; }
    virtual string getName() { return this->name; }
    virtual int getAge() { return this->age; }
    virtual void setName(string name) { this->name = name; }
    virtual void setAge() { this->age = age; }
protected:
    int age;
    string name;
};

class Dog : public Animal {
public:
    Dog(string name, int age) : Animal(name, age) { std::cout << " Dog(string name, int age)" << endl; }
    void print() override final { std::cout << "Dog age: " << age << " name: " << name << endl; } // 子类不能在被继承
    void bark() {
        cout << "bark()" << endl;
    }
    
};
// 子类不能在继承Cat
class Cat final : public Animal {
public:
    Cat(string name, int age) : Animal(name, age) { std::cout << " Cat(string name, int age)" << endl; }
    void print() override { std::cout << "Cat age: " << age << " name: " << name << endl; }
    void sleep() {
        cout << "sleep()" << endl;
    }
    //void printAnimal() { cout << "animal" << endl; } // error 不可继承
    
};
int main() {
    Animal *animal;
    Dog dog("dog", 11);
    Cat cat("cat", 9);
    dog.printAnimal();
    dog.print();
    dog.bark();
    dog.printAnimal();
    //cout << "dog age: " << static_cast<int>(dog.getAge()) << endl;
    cout << "name: " << dog.getName() << " age: " << static_cast<int>(dog) << endl;
    
    cat.print();
    cat.sleep();
    
    animal = &dog;
    animal->print();
    cout << "name: " << animal->getName() << " age: " << static_cast<int>(*animal) << endl;
    animal = &cat;
    animal->print();
    return 0;
}