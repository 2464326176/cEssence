# 新关键字

## default 

允许程序员显示声明类的缺省构造/析构 拷贝构造 赋值函数等，让编译器更好优化代码；

## delete

让程序员显示地禁用某些函数；

## override

虚函数地声明需要加上virtual关键字，如果一个成员函数时虚函数，那么后续派生类同名函数不需要再加上virtual关键字，为了方便阅读可以在后续子类虚函数加上override关键字；

## final

在类名后使用final，显示禁用类被继承，不能在派生类；

在虚函数后可以使用final，显示禁用此函数在子类中被重载；

```c++
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
```

## 成员初始化

不需要在借用构造函数来初始化参数；

```
public:
    // 成员初始化
    int x = 0;              // 赋值方式
    string s = "hello";     // 赋值方式
    vector<int> v{1, 2, 3}; // 花括号方式
};
```

## 委托构造

```c++
class demo {
public:
    demo() = default;
    demo(int a, string str, vector<int> v) : x(a), s(str), v(v) {}
    demo(int a) : demo(a, "null", {}) {}
    demo(string s) : demo(0, s, {}) {}
    demo(vector<int> v) : demo(0, "null", v) {}
    void print() {
        printf("%d %s \n", x, s.c_str());
        for (auto &vv: v) {
            printf("%d ", vv);
        }
        printf("\n");
    }
private:
    // 成员初始化
    int x = 0;              // 赋值方式
    string s = "hello";     // 赋值方式
    vector<int> v{1, 2, 3}; // 花括号方式
};

int main() {
    demo d0;
    demo d1(1);
    demo d2("c++");
    demo d3(vector<int>{6, 9, 7, 8});
    demo d4(3, "java", vector<int>{8, 5, 2, 7});
    d0.print(); // 0 hello 1 2 3
    d1.print(); // 1 null 
    d2.print(); // 0 c++ 
    d3.print(); // 0 null 6 9 7 8
    d4.print(); // 3 java 8 5 27
    return 0;
}
```

















