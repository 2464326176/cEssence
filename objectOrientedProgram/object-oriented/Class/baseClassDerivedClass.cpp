//**************************
// Author:  yh
// Time:    2021/11/6
//**************************

#include "baseClassDerivedClass.h"

int main() {
    /*Derived1* d1 = new Derived1();
    Derived2 d2 = Derived2("Bob");
    delete d1;*/

    /*
    派生类中定义了析构函数来释放其申请的资源，但是并没有得到调用。
    原因是基类指针指向了派生类对象，而基类中的析构函数却是非virtual的，
    之前讲过，虚函数是动态绑定的基础。现在析构函数不是virtual的，
    因此不会发生动态绑定，而是静态绑定，指针的静态类型为基类指针，
    因此在delete时候只会调用基类的析构函数，而不会调用派生类的析构函数。
    这样，在派生类中申请的资源就不会得到释放，就会造成内存泄漏，这是相当危险的：
    如果系统中有大量的派生类对象被这样创建和销毁，就会有内存不断的泄漏，久而久之，系统就会因为缺少内存而崩溃。
     */
    cout << "base -> derived" << endl;
    Base* base[2] = {
            new Derived1(),
            new Derived2("Bob")
    };

    for (int i = 0; i != 2; ++i) {
        delete base[i];
    }

    return 0;
}