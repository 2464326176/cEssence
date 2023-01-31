/*
 * @Author: yh
 * @Date: 2022/9/6 0:58
 * @Description:
 * @FilePath: \cEssence\objectOrientedProgram\runTimeTypeIdentify\typeid\typeid.cpp
 */
#include <iostream> // std::cout
#include <typeinfo> // operator typeid

using namespace std;

class A {
public:
    // object for class needs vtable
    // for RTTI
    virtual ~A();
};

class Shape {
public:
   virtual void virtualfunc() const {}
};

class Circle: public Shape {
public:
   virtual void virtualfunc() const {}
};

struct Base {};
struct Derived : Base {};
struct Poly_Base {
    virtual void Member() {}
};
struct Poly_Derived : Poly_Base {};

typedef int my_int_type;

int main() {
    A *a = NULL;

    try {
        cout << typeid(*a).name() << endl; // Error condition
    } catch (bad_typeid bad) {
        cout << bad.what() << endl;
    }

   Shape shape_instance;
   Shape& ref_shape = shape_instance;
   try {
      Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
   }
   catch (bad_cast b) {
      cout << "Caught: " << b.what() << endl;
   }

   Circle circle_instance;
   Circle& ref_circle = circle_instance;
   try {
      Shape& ref_shape = dynamic_cast<Shape&>(ref_circle);
   }
   catch (bad_cast b) {
      cout << "Caught: " << b.what() << endl;
   }


    std::cout << std::boolalpha;

    // fundamental types:
    std::cout << "int vs my_int_type: ";
    std::cout << (typeid(int) == typeid(my_int_type)) << '\n';

    // class types:
    std::cout << "Base vs Derived: ";
    std::cout << (typeid(Base) == typeid(Derived)) << '\n';

    // non-polymorphic object:
    Base *pbase = new Derived;

    std::cout << "Base vs *pbase: ";
    std::cout << (typeid(Base) == typeid(*pbase)) << '\n';

    // polymorphic object:
    Poly_Base *ppolybase = new Poly_Derived;

    std::cout << "Poly_Base vs *ppolybase: ";
    std::cout << (typeid(Poly_Base) == typeid(*ppolybase)) << '\n';

    std::cout << "Poly_Base vs *Poly_Derived: ";
    std::cout << (typeid(Poly_Derived) == typeid(*ppolybase)) << '\n';
    return 0;
}
