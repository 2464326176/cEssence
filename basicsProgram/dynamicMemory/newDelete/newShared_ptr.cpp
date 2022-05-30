/*
 * @Author: yh
 * @Date: 2022/5/30 23:32
 * @Description: 
 * @FilePath: newShared_ptr.cpp
 */

#include <iostream>
#include <memory>

using namespace std;

int main() {
    // 当一个unique_ptr指向一个数组时，我们不能使用点和箭头成员运算符（指向数组的unique_ptr 不支持成员访问运算符）
    // 我们可以使用下表运算符来访问数组中的元素
    //shared_ptr<int[]> sp(new int[12]{8, 88, 8, 9, 74, 59, 6, 12, 45}, [](int *p) { delete[] p; });
    shared_ptr<int> sp(new int[12]{8, 88, 8, 9, 74, 59, 6, 12, 45}, [](int *p) { delete[] p; });
    
    for (int *q = sp.get(); q != sp.get() + 12; ++q) {
        printf("%d ", *q);
        *q = 89;
    }
    printf("\n");
    
    for (int *q = sp.get(); q != sp.get() + 12; ++q) {
        printf("%d ", *q);
    }
    
    sp.reset(); // 自动调用delete[] 销毁其指针
    return 0;
}