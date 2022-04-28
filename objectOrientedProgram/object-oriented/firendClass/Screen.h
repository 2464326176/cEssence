//**************************
// Author:  yh
// Time:    2022/4/28
//**************************

#ifndef CESSENCE_SCREEN_H
#define CESSENCE_SCREEN_H

#include <iostream>

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {} // 2
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {} // 3

    char get() const { return contents[cursor]; }

    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};


#endif //CESSENCE_SCREEN_H
