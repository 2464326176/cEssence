/*
 * @Author: yh
 * @Date: 2022/10/25 23:36
 * @Description: 
 * @FilePath: nest.h
 */

#ifndef CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_NESTEDCLASS_NEST_H
#define CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_NESTEDCLASS_NEST_H

#include "stdlib.h"
#include "stdio.h"

class Nest {
public:
    int a;
    class A {
    public:
        void print1() {
            printf("A print()");
        }
    protected:
        void print2() {
            printf("A print()");
        }
    private:
        void print3() {
            printf("A print()");
        }
    };
protected:
    int b;
    class B {
    public:
        void print1() {
            printf("A print()");
        }
    protected:
        void print2() {
            printf("A print()");
        }
    private:
        void print3() {
            printf("A print()");
        }
    };
private:
    int c;
    class C {
    public:
        void print1() {
            printf("A print()");
        }
    protected:
        void print2() {
            printf("A print()");
        }
    private:
        void print3() {
            printf("A print()");
        }
    };
};

#endif //CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_NESTEDCLASS_NEST_H
