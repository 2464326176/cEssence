/*
 * @Author: yh
 * @Date: 2022/9/11 14:32
 * @Description: 
 * @FilePath: customCompareContainer.cpp
 */
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using my_pair_t = std::pair<size_t, bool>;
using my_container_t = std::vector<my_pair_t>;

int main() {
    auto my_comp = [](const my_pair_t &e1, const my_pair_t &e2) { return e1.first > e2.first; };
    std::priority_queue<my_pair_t, my_container_t, decltype(my_comp)> queue(my_comp);
    queue.push(std::make_pair(5, true));
    queue.push(std::make_pair(3, false));
    queue.push(std::make_pair(7, true));
    std::cout << std::boolalpha;
    while (!queue.empty()) {
        const auto &p = queue.top();
        std::cout << p.first << " " << p.second << "\n";
        queue.pop();
    }
}
