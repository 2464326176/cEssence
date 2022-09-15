/*
 * @Author: yh
 * @Date: 2022/9/11 3:15
 * @Description: 
 * @FilePath: priorityQueue.cpp
 */
#include <queue>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void print_queue(priority_queue<int> priQue) {
    while (!priQue.empty()) {
        cout << priQue.top() << " ";
        priQue.pop();
    }
    cout << endl;
}

template<typename T>
void print_queue(T &q) {
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    std::priority_queue<int> c1(std::less<int>(), {5, 6, 4, 2, 1});
    print_queue(c1);

//    std::priority_queue<int> c2(std::greater<int>(), {5, 6, 4, 2, 1});
//    print_queue(c2);
    
    std::priority_queue<int> q;
    for (int n: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q.push(n);
    }
    print_queue(q);
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    for (int n: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q2.push(n);
        
    }
    print_queue(q2);
    
    // 用 lambda 比较元素。
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
    
    for (int n: {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) {
        q3.push(n);
        cout << n << "^1:" << (n ^ 1) << " ";
    }
    cout << endl;
    print_queue(q3);
    return 0;
}
