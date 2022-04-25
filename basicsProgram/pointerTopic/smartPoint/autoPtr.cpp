//**************************
// Author:  yh
// Time:    2021/12/19
//**************************

#include <iostream>
#include <cstddef>
#include <memory>

void autoPtrRelease() {
    std::auto_ptr<int> auto_pointer (new int);
    int * manual_pointer;

    *auto_pointer=10;

    manual_pointer = auto_pointer.release();

    std::cout << "manual_pointer points to " << *manual_pointer << '\n';
    // (auto_pointer is now null-pointer auto_ptr)

    delete manual_pointer;
}

void autoPtrReset() {
    std::auto_ptr<int> p;
    p.reset (new int);
    *p=5;
    std::cout << *p << '\n';

    p.reset (new int);
    *p=10;
    std::cout << *p << '\n';
}

void autoPtrConstruct() {
    std::auto_ptr<int> p1 (new int);
    *p1.get()=10;

    std::auto_ptr<int> p2 (p1);
    if(p1.get()) {
        std::cout << "p1 points to " << *p1 << '\n';
    } else {
        std::cout << "p1 points is null" << '\n';
    }
    std::cout << "p2 points to " << *p2 << '\n';
    // (p1 is now null-pointer auto_ptr)
}

int dereferenceObjectMember () {
    typedef std::pair<int*,std::ptrdiff_t> mypair;
    std::auto_ptr<mypair> p (new mypair);
    *p = std::get_temporary_buffer<int>(5);

    if (p->second >= 5) {
        for (int i=0; i<5; i++)
            p->first[i]=i*5;

        for (int i=0; i<5; i++)
            std::cout << p->first[i] << " ";

        std::cout << '\n';
    }
    std::return_temporary_buffer (p->first);
    return 0;
}
int main () {
    //autoPtrRelease();
    dereferenceObjectMember();

    return 0;
}