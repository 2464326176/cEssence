/*
 * @Author: yh
 * @Date: 2022/5/26 0:47
 * @Description: shared_ptr 和 new结合
 * @FilePath: explicit.cpp
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct stu {
  stu(string name) : name(name) {
      printf("stu construct function\n");
  }
  ~stu() {
      printf("~std destruct function\n");
  }
  string name;
};


// error
//shared_ptr<int> clone(int p) {
//    return new int(p); // 隐式转化为shared_ptr<int>
//}

shared_ptr<int> clone(int p) {
    return shared_ptr<int>(new int(p)); // 隐式转化为shared_ptr<int>
}

void explicit_test() {
    shared_ptr<double> p1;
    // 智能指针构造函数是explicit 不能把一个内置指针隐式转化为一个智能指针 必须使用直接初始化方式
    //shared_ptr<double> p2 = new double(3.14); // error   必须使用直接初始化方式
    shared_ptr<double> p3(new double(3.14)); //正确
}

int main() {
    
    return 0;
}