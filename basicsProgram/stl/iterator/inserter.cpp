/*
 * @Author: yh
 * @Date: 2023-02-04 10:03:07
 * @LastEditTime: 2023-02-04 10:21:59
 * @Description:
 * @FilePath: \cEssence\basicsProgram\stl\iterator\inserter.cpp
 */
#include <algorithm> // std::copy
#include <deque>
#include <iostream> // std::cout
#include <iterator> // std::front_inserter
#include <list>     // std::list
#include <vector>
void inserter() {
    std::list<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }

    std::list<int>::iterator it = foo.begin();
    advance(it, 3);

    std::copy(bar.begin(), bar.end(), std::inserter(foo, it));

    std::cout << "foo contains:";
    for (std::list<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void frontInserter() {
    std::deque<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }

    std::copy(bar.begin(), bar.end(), std::front_inserter(foo));

    std::cout << "foo contains:";
    for (std::deque<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void backInserter() {
    std::vector<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }

    std::copy(bar.begin(), bar.end(), back_inserter(foo));

    std::cout << "foo contains:";
    for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main() {
    inserter();
    std::cout << "------------------------\n";
    frontInserter();
    std::cout << "------------------------\n";
    backInserter();
    return 0;
}