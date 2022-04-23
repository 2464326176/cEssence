//********************
// Author:  yh 
// Time:    2020/10/11.
// 
//********************
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <list>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::list;

int main() {
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 1, 2, 3, 4, 5 };
    std::vector<int> vec3{ 1, 2, 3, 4 };

    std::cout << (vec1 == vec2 ? "true" : "false") << std::endl;
    std::cout << (vec1 == vec3 ? "true" : "false") << std::endl;

    std::list<int>      li{ 1, 2, 3, 4, 5 };

    std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << std::endl;

    list<int> numbers = { 1, 2, 3, 4, 5 };
    list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
    //vector<int> numbers3(numbers);      // error: no matching function for call...
    //list<double> numbers4(numbers);     // error: no matching function for call...
    //numbers2(numbers.begin(), numbers.end());        // ok, numbers2 has the same elements as numbers
    vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is { 1, 2, 3, 4 }
    list<double> numbers4(++numbers.begin(), --numbers.end());        // ok, numbers4 is { 2, 3, 4 }
    //forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is { 1, 2, 3, 4, 5 }
    return 0;
}