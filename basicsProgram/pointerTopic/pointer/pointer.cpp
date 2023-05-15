/*
 * @Author: yh
 * @Date: 2023-03-26 01:19:50
 * @LastEditTime: 2023-03-26 18:42:12
 * @Description:
 * @FilePath: \cEssence\basicsProgram\pointerTopic\pointer\pointer.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int value = 10;                                    // value: 10, &value: 000000000062fe00
    int *p = nullptr;                                  // p是指向int类型的指针变量 空间为4个字节
    p = &value;                                        // *p: 10, p: 000000000062fe00
    const int *p1;                                     // const指针 指针指向的值不可以被修改
    int const *p2;                                     // const指针 指针指向的值不可以被修改
    int *const p3 = &value;                            // 指向const的指针 指针的地址不可以被修改
    const int *const p4 = &value;                      // 指向const的const指针 指针指向的值，指针的地址都不可以被修改
    int array1[]{1, 2, 3, 5};                          // a是一个数组 其中有10个元素
    int *p5 = array1;                                  // a是一个int数组类型 p指向a的首元素
    int(*p6)[4] = &array1;                             // 数组指针，p0类型是 int(*)[10],其本质是一个指向数组地址的指针
    int *p7[3] = {&array1[0], &array1[1], &array1[2]}; // 数组指针，p7本质是一个数组，里面存放的是int元素的指针地址
    typedef char (*getMax)(int x, int y);              // 函数指针，其本质就是一个指针，指向函数
    typedef char (*a[10])(int x, , int y);             // char函数指针数组
    char *getStr(int x, int y);                        // 指针函数，其本质是一个函数，返回值是指针
    return 0;
}