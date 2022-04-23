//**************************
// Author:  yh
// Time:    2021/12/20
//**************************
#include <iostream>

// declare member function template
struct X {
    template<class T> void mf(T* t) {
        std::cout << "t: " << *t << "\n";
    }
};

//define member template outsize class
template<typename T>
class a{
public:
    template<typename U> void mf(const U& u);
};

template<typename T> template<typename U>
void a<T>::mf(const U& u) {

}

//template user defined conversions
template<class T>
struct b{
    template<class U> operator b<U>() {
        return b<U>();
    }
};



int main() {
    /*int i;
    X* x = new X();
    x->mf(&i);*/
    b<int> s1;
    b<long> s2 = s1;
    return 0;
}














