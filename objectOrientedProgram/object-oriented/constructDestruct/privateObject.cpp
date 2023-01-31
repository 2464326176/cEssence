/*
 * @Author: yh
 * @Date: 2023-01-08 23:35:04
 * @LastEditTime: 2023-01-08 23:41:46
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\object-oriented\constructDestruct\privateObject.cpp
 */
#include <iostream>
#include <stdexcept>

using namespace std;

class Object final {
public:
    Object() {}

    ~Object() {}
};

class Obj1 : public Object {
public:
    Obj1() {
        printf("Obj1()");
    }
};
int main() {

    Obj1 obj1;

    return 0;
}