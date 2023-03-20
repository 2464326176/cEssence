#include "shape.h"

using namespace std;

void printfArea(Shape *shape) { shape->draw(); }

int main() {
    Rectangle rectangle(3, 4);
    Square square(4);
    Circle circle(5);
    /*rectangle.draw();
    square.draw();
    circle.draw();*/

    /*Shape *shape = nullptr;
    shape = &rectangle;
    shape->draw();
    shape = &square;
    shape->draw();
    shape = &circle;
    shape->draw();*/

    printfArea(&rectangle);
    printfArea(&square);
    printfArea(&circle);
    return 0;
}