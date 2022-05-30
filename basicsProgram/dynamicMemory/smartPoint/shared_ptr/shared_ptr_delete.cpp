/*
 * @Author: yh
 * @Date: 2022/5/26 1:45
 * @Description: 
 * @FilePath: shared_ptr_delete.cpp
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Stu {
  Stu(string name) : name(name) {
      printf("Stu construct function\n");
  }
  ~Stu() {
      printf("~std destruct function\n");
  }
  string name;
};

void end_delete(Stu *&stu) {
    if (stu) {
        delete stu;
    }
}

void printStu(Stu *&stu) {
    //shared_ptr<Stu> p(stu, end_delete);
    shared_ptr<Stu> p(stu, [](Stu *&stu) {
      if (stu) {
          delete (stu);
      }
    });
}

int main() {
    Stu *p1 = new Stu("c++");
    printStu(p1);
    
    return 0;
}