/*
 * @Author: yh
 * @Date: 2023/11/26 3:12
 * @Description:
 * @FilePath: test.h
 */

#ifndef C_BASICSPROGRAM_POINTERTOPIC_SMARTPOINT_AUTOPTR_TEST_H
#define C_BASICSPROGRAM_POINTERTOPIC_SMARTPOINT_AUTOPTR_TEST_H

#include <cstring>
#include <iostream>
#include <memory>

class Test {
public:
    Test() = default;

    Test(const char *_name) {
        size_t size = strlen(_name) + 1;
        name = new char[size];
        strncpy(name, _name, size);
    }

    Test(const Test& _test) {
        if (name) {
            delete name;
            name = NULL;
        }

        size_t size = strlen(_test.name) + 1;
        name = new char[size];
        strncpy(name, _test.name, size);
    }

    Test& operator=(const Test& _test) {
        if (name) {
            delete name;
            name = NULL;
        }

        size_t size = strlen(_test.name) + 1;
        name = new char[size];
        strncpy(name, _test.name, size);
        return *this;
    }

    void showName() {
        printf("name : %s\n", name ? name : "");
    }

public:
    char *name;
};

#endif // C_BASICSPROGRAM_POINTERTOPIC_SMARTPOINT_AUTOPTR_TEST_H
