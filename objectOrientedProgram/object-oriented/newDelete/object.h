//**************************
// Author:  yh
// Time:    2022/4/17
//**************************

#ifndef CESSENCE_OBJECT_H
#define CESSENCE_OBJECT_H
#include <iostream>

using namespace std;

class Object {
public:
    Object(int _a) {
        a = _a;
        cout << "construct function" << endl;
    }

    ~Object() {
        cout << "destruct function" << endl;
    }

protected:
private:
    int a;
};

#endif //CESSENCE_OBJECT_H
