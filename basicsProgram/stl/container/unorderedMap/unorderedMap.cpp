/*
 * @Author: yh
 * @Date: 2022/10/19 0:06
 * @Description: 
 * @FilePath: unorderedMap.cpp
 */

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_multimap<std::string, std::string> mymap = {
        {"mom", "church"},
        {"mom", "college"},
        {"dad", "office"},
        {"bro", "school"}};
    
    std::cout << "one of the values for 'mom' is: ";
    std::cout << mymap.find("mom")->second;
    std::cout << std::endl;
    
    return 0;
}

