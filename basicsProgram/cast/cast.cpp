/*
 * @Author: yh
 * @Date: 2023-01-08 16:03:39
 * @LastEditTime: 2023-01-08 16:17:17
 * @Description: 
 * @FilePath: \cEssence\basicsProgram\cast\cast.cpp
 */
#include <iostream>
#include <memory>

class IGlyph {
public:
    virtual ~IGlyph() {}
    virtual std::string Text() = 0;
    virtual IIcon* Icon() = 0;
};

int main() {
    char *p = "a";
    //int a1 = int(&p);
    //int a2 = static_cast<int>(&p);
    //int a3 = reinterpret_cast<int>(p);
    int a4 = int('a');
    return 0;
}