//**************************
// Author:  yh
// Time:    2022/4/23
//**************************

#include "array.h"
#include <iostream>
#include <array>
#include <cstring>
// Member functions

void iterators() {
    std::array<int, 5> myarray = {2, 16, 77, 34, 50};

    std::cout << "contains order: ";
    for (auto it = myarray.begin(); it != myarray.end(); ++it) {
        std::cout << ' ' << *it << " ";
    }
    std::cout << '\n';

    std::cout << "contains reverse order: ";
    for (auto it = myarray.rbegin(); it != myarray.rend(); ++it) {
        std::cout << ' ' << *it << " ";
    }
    std::cout << '\n';

    std::cout << "const contains order: ";
    for (auto it = myarray.begin(); it != myarray.end(); ++it) {
        std::cout << ' ' << *it << " "; // not modify
    }
    std::cout << '\n';

    std::cout << "const contains reverse order: ";
    for (auto it = myarray.crbegin(); it != myarray.crend(); ++it) {
        std::cout << ' ' << *it << " "; // not modify
    }
    std::cout << '\n';
}

void elementAccess() {
    // 该函数自动检查 n 是否在容器中有效元素的范围内，
    // 如果不在则抛出 out_of_range 异常（即，如果 n 大于或等于其大小）。
    // 这与不检查边界的成员 operator[] 形成对比。
    std::array<int, 10> myarray;

    // assign some values:
    for (unsigned int i = 0; i < 10; i++) {
        myarray[i] = i;
    }

    // print content
    std::cout << "myarray contains:";
    for (unsigned int i = 0; i < 10; i++) {
        std::cout << ' ' << myarray[i];
    }
    std::cout << '\n';

    // assign some values:
    for (int i = 0; i < 10; i++) {
        myarray.at(i) = i + 1;
    }

    // print content:
    std::cout << "myarray contains:";
    for (int i = 0; i < 10; i++) {
        std::cout << ' ' << myarray.at(i);
    }
    std::cout << '\n';

    std::array<int,3> myarray1 = {5, 19, 77};

    std::cout << "myarray1 front is: " << myarray1.front() << std::endl;   // 5
    std::cout << "myarray1 back is: " << myarray1.back() << std::endl;     // 77

    myarray1.front() = 100;
    std::cout << "myarray1 now contains:";
    for ( int& x : myarray1 ) std::cout << ' ' << x;
    std::cout << '\n';

    myarray1.back() = 50;
    std::cout << "myarray1 now contains:";
    for ( int& x : myarray1 ) std::cout << ' ' << x;
    std::cout << '\n';


    std::array<int,3> myarray2 = {5, 8}; // 5 8 0
    std::cout << "myarray2 front is: " << myarray2.front() << std::endl;   // 5
    std::cout << "myarray2 back is: " << myarray2.back() << std::endl;     // 0

    myarray2.front() = 100;
    std::cout << "myarray2 now contains:";
    for ( int& x : myarray2 ) std::cout << ' ' << x;
    std::cout << '\n';

    myarray2.back() = 50;
    std::cout << "myarray2 now contains:";
    for ( int& x : myarray2 ) std::cout << ' ' << x;
    std::cout << '\n';

    /*for(auto *pItem = myarray2.data(); ; ) {

    }*/
    std::cout << '\n';

    const char* cstr = "Test string";
    std::array<char,12> charray;
    std::memcpy (charray.data(),cstr,12);
    std::cout << charray.data() << '\n';
}

void Capacity() {
    std::array<int, 10> myints;
    std::cout << "size of myints: " << myints.size() << '\n';
    std::cout << "sizeof(myints): " << sizeof(myints) << std::endl;
    std::cout << "max_size of myints: " << myints.max_size() << '\n';

}

void modify() {
    std::array<int,6> myarray;
    myarray.fill(8);
    std::cout << "myarray contains:";
    for ( int& x : myarray) { std::cout << ' ' << x; } // 8 8 8 8 8 8
    std::cout << '\n';

    std::array<int,5> first = {10, 20, 30, 40, 50};
    std::array<int,5> second = {11, 22, 33, 44, 55};

    first.swap (second);
    std::cout << "first:";
    for (int& x : first) std::cout << ' ' << x;
    std::cout << '\n';
    std::cout << "second:";
    for (int& x : second) std::cout << ' ' << x;
    std::cout << '\n';
}

void memberFunction() {
    //iterators();
    //Capacity();
    //elementAccess();
    modify();
}

/*Modifiers
        fill Fill array with value (public member function )
swap Swap content (public member function )

Non-member function overloads
        get (array) Get element (tuple interface) (function template )
relational operators (array) Relational operators for array (function template )

Non-member class specializations
        tuple_element<array> Tuple element type for array (class template specialization )
tuple_size<array> Tuple size traits for array (class template specialization )*/


int main() {
    memberFunction();
    return 0;
}