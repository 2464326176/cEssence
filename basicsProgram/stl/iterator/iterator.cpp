/*
 * @Author: yh
 * @Date: 2023-02-04 10:03:07
 * @LastEditTime: 2023-02-04 10:35:22
 * @Description:
 * @FilePath: \cEssence\basicsProgram\stl\iterator\iterator.cpp
 */
#include <algorithm> // std::copy
#include <deque>
#include <iostream> // std::cout
#include <iterator> // std::front_inserter
#include <list>     // std::list
#include <vector>

void backInsertIterator() {
    std::vector<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }

    std::back_insert_iterator<std::vector<int>> back_it(foo);

    std::copy(bar.begin(), bar.end(), back_it);

    std::cout << "foo:";
    for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void frontInsertIterator() {
    std::deque<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }

    std::front_insert_iterator<std::deque<int>> front_it(foo);

    std::copy(bar.begin(), bar.end(), front_it);

    std::cout << "foo:";
    for (std::deque<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void insertIterator() {
    std::list<int> foo, bar;
    for (int i = 1; i <= 5; i++) {
        foo.push_back(i);
        bar.push_back(i * 10);
    }

    std::list<int>::iterator it = foo.begin();
    advance(it, 3);

    std::insert_iterator<std::list<int>> insert_it(foo, it);

    std::copy(bar.begin(), bar.end(), insert_it);

    std::cout << "foo:";
    for (std::list<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void reverseIterator() {
    std::vector<int> myvector;
    for (int i = 0; i < 10; i++)
        myvector.push_back(i);

    typedef std::vector<int>::iterator iter_type;
    // ? 0 1 2 3 4 5 6 7 8 9 ?
    iter_type from(myvector.begin());                 //   ^
                                                      //         ------>
    iter_type until(myvector.end());                  //                       ^
                                                      //
    std::reverse_iterator<iter_type> rev_until(from); // ^
                                                      //         <------
    std::reverse_iterator<iter_type> rev_from(until); //                     ^

    std::cout << "myvector:";
    while (rev_from != rev_until)
        std::cout << ' ' << *rev_from++;
    std::cout << '\n';
}

void moveIterator() {
    std::vector<std::string> foo(3);
    std::vector<std::string> bar{"one", "two", "three"};

    typedef std::vector<std::string>::iterator Iter;

    std::copy(std::move_iterator<Iter>(bar.begin()), std::move_iterator<Iter>(bar.end()), foo.begin());

    std::cout << "bar:";
    for (std::string &x : bar)
        std::cout << ' ' << x;
    std::cout << '\n';

    // bar now contains unspecified values; clear it:
    bar.clear();

    std::cout << "foo:";
    for (std::string &x : foo)
        std::cout << ' ' << x;
    std::cout << '\n';
}

int main() {
    moveIterator();
    std::cout << "------------------------------\n";
    reverseIterator();
    return 0;
}