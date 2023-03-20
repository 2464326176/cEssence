#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

#define PI 3.1415926

class Shape {
public:
    virtual double getArea() = 0;
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y) : x(x), y(y) {}
    double getArea() { return x * y; }

    void draw() { printf("rectangle area: %lf\n", getArea()); }

public:
    int x = 0;
    int y = 0;
};

class Square : public Rectangle {
public:
    Square(int x) : x(x), Rectangle(x, x) {}
    double getArea() { return x << 2; }

    void draw() { printf("square area: %lf\n", getArea()); }

public:
    int x = 0;
};

class Circle : public Shape {
public:
    Circle(int r) : r(r) {}
    double getArea() { return PI * r * r; }

    void draw() { printf("circle area: %lf\n", getArea()); }

public:
    int r = 0;
};

#endif // SHAPE_H