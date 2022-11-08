/*
 * @Author: yh
 * @Date: 2022/11/8 23:51
 * @Description: 
 * @FilePath: emplace.cpp
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PerstemplatesGeneric/templateLink/main.
cpp on{
    std::string name;
    int age = 0;
    
    Person() = default;
    
    Person(string name, int age) : name(name), age(age) {
        printf_s("Person(string name, int age)\n");
    }
};

int main() {
    vector<Person> vc;
    vc.push_back({"index", 2});
    //vc.push_back("index", 2); // error
    vc.push_back(Person("index", 2));
    vc.emplace_back("index", 2);
    vc.emplace_back(Person("index", 2));
    // vc.emplace_back({"index", 2}); // error
    
    return 0;
}