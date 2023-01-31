/*
 * @Author: yh
 * @Date: 2023-01-08 22:44:56
 * @LastEditTime: 2023-01-08 22:49:15
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\object-oriented\constructDestruct\objectArray.cpp
 */
#include <iostream>

using namespace std;

class object {
public:
    object() {
        printf("object()\n");
    }

    object(int x) {
        printf("object(int x) %d \n", x);
    }

    object(int x, int y) {
        printf("object(int x, int y) %d %d\n", x, y);
    }
};

int main() {
    object *p = new object[4] {{4,4}, {5,5}, {7,7}, {8,8}};

    delete [] p;
    p = nullptr;
    return 0;
}