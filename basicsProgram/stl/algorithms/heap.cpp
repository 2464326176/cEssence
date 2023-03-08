#include <algorithm> // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <functional>
#include <iostream> // std::cout
#include <vector>   // std::vector

void print(const std::vector<int> &v) {
    for (unsigned i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << '\n';
}

int main() {
    int myints[] = {10, 20, 30, 5, 15};
    std::vector<int> v(myints, myints + 5);
    std::make_heap(v.begin(), v.end(), std::less<int>()); // greater heap
    // std::make_heap(v.begin(), v.end(), std::greater<int>()); // less heap
    // std::make_heap(v.begin(), v.end()); // greater heap
    std::cout << "initial max heap   : " << v.front() << '\n';
    print(v);
    std::pop_heap(v.begin(), v.end());
    v.pop_back();
    std::cout << "max heap after pop : " << v.front() << '\n';

    v.push_back(99);
    std::push_heap(v.begin(), v.end());
    std::cout << "max heap after push: " << v.front() << '\n';

    std::sort_heap(v.begin(), v.end(), std::less<int>()); //
    print(v);
    std::sort_heap(v.begin(), v.end(), std::greater<int>()); //
    print(v);
    return 0;
}