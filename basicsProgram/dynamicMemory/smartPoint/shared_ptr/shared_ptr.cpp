/*
 * @Author: yh
 * @Date: 2022/5/23 22:34
 * @Description: 
 * @FilePath: shared_ptr.cpp
 */

#include "shared_ptr.h"
#include <string>
#include <list>
#include <vector>

using namespace std;

shared_ptr<string> factory(string arg) {
    return make_shared<string>(arg);
}

void use_factory(string arg) {
    auto p = make_shared<string>(arg); // p 离开了作用域 他指向的内存就会被自动释放掉
}

shared_ptr<string> retUseFactory(string arg) {
    auto p = make_shared<string>(arg);
    return p; // 当返回p时候 引用计数器惊醒了递增操作 p离开了作用域 但是它指向的内存不会被释放掉
}

void test() {
    shared_ptr<string> p1;
    shared_ptr<int> p2 = make_shared<int>(41);
    shared_ptr<string> p3 = make_shared<string>(10, '9');
    shared_ptr<int> p4 = make_shared<int>();
    auto p5 = make_shared<vector<string>>();
    
    if (p1 && p1->empty()) {
        *p1 = "hello world!!!";
    }
    
    printf("%d \n", *p2);
    printf("%s %s\n", p3->c_str(), (*p3).c_str());
    printf("%d \n", *p4);
    
    // 拷贝
    printf("p2 use_count: %d\n", p2.use_count());
    shared_ptr<int> p6(p2);
    printf("p6 p2 use_count: %d %d\n", p6.use_count(), p2.use_count());
    
    // 赋值
    auto p7(p4);
    printf("p7 p4 p2 use_count: %d %d %d\n", p7.use_count(), p4.use_count(), p2.use_count());
    p4 = p2;
    printf("p7 p4 p2 use_count: %d %d %d\n", p7.use_count(), p4.use_count(), p2.use_count());
    
}

int main() {
    test();
    shared_ptr<string> sp1 = factory("string");
    shared_ptr<string> sp2 = retUseFactory(string("string"));
    
    printf("%d %d\n", sp1.use_count(), sp2.use_count());
    return 0;
}
