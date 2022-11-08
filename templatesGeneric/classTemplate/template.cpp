//**************************
// Author:  yh
// Time:    2021/12/21
//**************************

#include "template.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
namespace myFunction {
    template<typename Iterator, typename Value>
    auto find(Iterator first, Iterator last, Value const& value) {
        for(; ((first != last) && (*first != value)); ++first) { }
        return first;
    }

    template<typename Arr>
    void print(Arr const& arr) {
        for(auto const& elem: arr) {
            cout << elem << " ";
        }
        cout << endl;
    }

    template<typename Container>
    ostream& printf(Container const& container, ostream& os) {
        /*for(typename Container::size_type i = 0; i != container.size(); ++i) {
            os << container[i] << " ";
        }*/

        for(auto curr = container.cbegin(); curr != container.cend(); ++curr) {
            os << *curr << " ";
        }
        return os;
    }
    template<typename T, unsigned size>
    T* begin_def(T(&arr)[size]) {
        return arr;
    }

    template<typename T, unsigned size>
    T* end_def(T(&arr)[size]) {
        return arr + size;
    }

    template<typename T, unsigned size>
    constexpr unsigned getSize(const T(&)[size]) {
        return size;
    }

    template<typename T>
    int compare(const T& lhs, const T& rhs)
    {
        if(lhs < rhs) return -1;
        if(rhs < lhs) return  1;
        return 0;
    }
}


void textFindElem() {
    vector<int> v{1, 2, 3, 4, 5};
    auto is_in_vector = (v.cend() != myFunction::find(v.cbegin(), v.cend(), 5));
    cout << "is_in_vector: " << (is_in_vector ? "found\n" : "not found\n");

    std::list<string> lString{"aa", "ab", "abc", "abcd"};
    auto is_in_list = (lString.cend() != myFunction::find(lString.cbegin(), lString.cend(), "ab"));
    cout << "is_in_list: " << (is_in_list ? "found\n" : "not found\n");
}

void printArr() {
    string s[]{"sss", "aaa", "bbbb"};
    char c[]{'a', 'b', 'c', 'd'};
    int i[]{1, 2, 3, 4};
    myFunction::print(s);
    myFunction::print(c);
    myFunction::print(i);
}

void retBeginAndEnd() {
    string s[]{"aaa", "bbb", "def"};
    cout << *(myFunction::begin_def(s)) << endl;
    cout << *(myFunction::begin_def(s) + 1) << endl;
    cout << *(myFunction::end_def(s) - 1) << endl;
}

void printfGetSize() {
    string s[]{"sss"};
    cout << myFunction::getSize(s) << endl;

    char c[]{"s"};
    cout << myFunction::getSize(c) << endl;

}

void printElems() {
    std::vector<int> v = { 1, 23, 6, 4, 5, 7, 4 };
    std::list<std::string> l = { "ss", "sszz", "saaas", "s333s", "ss2"," sss" };
    myFunction::printf(v, std::cout) << std::endl;
    myFunction::printf(l, std::cout) << std::endl;
}

class Sales_data{ };

void textCompare()
{
    // Test compare function
    cout << myFunction::compare(1, 0) << endl;
    vector<int> vec1{ 1, 2, 3 }, vec2{ 4, 5, 6 };
    cout << myFunction::compare(vec1, vec2) << endl;
}
template <class T> int compare(const T&, const T&);

void text1() {
    //compare("hi", "world");
    //compare("bye", "dad");
}

template <typename T> T f1(T, T) {};
template <typename T1, typename T2> T1 f2(T1, T2) {};

void text2() {
    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;
    f1(p1, p2);     // f1<int*>(int*, int*)
    f2(p1, p2);     // f2<int*, int*>(int*, int*)
    f1(cp1, cp2);   // f1<int const*>(int const*, int const*)
    f2(cp1, cp2);   // f2<int const*, int const*>(int const*, int const*)
    //f1(p1, cp1);    // deduced conflicting types for parameter 'T'
    f2(p1, cp1);    // f2<int*, int const*>(int*, int const*)
}

namespace text {
    template <typename T> void f(T)
    {
        std::cout << "f(T)\n";
    }

    template <typename T> void f(const T*)
    {
        std::cout << "f(const T*)\n";
    }
    template <typename T> void g(T)
    {
        std::cout << "template <typename T> void g(T)\n";
    }
    template <typename T> void g(T*)
    {
        std::cout << "template <typename T> void g(T*)\n";
    }
}

int text3()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    text::g(42);    //template <typename T> void g(T ); --is called
    text::g(p);     //template <typename T> void g(T*); --is called
    text::g(ci);    //template <typename T> void g(T)   --is called
    text::g(p2);    //template <typename T> void g(T*)  --is called
    text::f(42);    //f(T)
    text::f(p);     //f(T)
    text::f(ci);    //f(T)
    text::f(p2);    //f(const T*)
}

int main() {
    //textFindElem();
    //printArr();
    //retBeginAndEnd();
    //printfGetSize();
    //printElems();
    //textCompare();
    //text3();
    return 0;
}