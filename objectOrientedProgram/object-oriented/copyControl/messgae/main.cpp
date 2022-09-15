/*
 * @Author: yh
 * @Date: 2022/9/15 23:33
 * @Description: 
 * @FilePath: main.cpp
 */

#include "message.h"

int main() {
    Folder folder0("java");
    Folder folder1("c++");
    Folder folder2("php");
    
    Message message1("I am java1");
    Message message2("I am java2");
    Message message3("I am java3");
    Message message4("I am java4");
    
    Message message5("I am c++1");
    Message message6("I am c++2");
    Message message7("I am c++3");
    
    Message message8("I am php1");
    Message message9("I am php2");
    Message message10("I am php3");
    Message message11("I am php4");
    
    message1.save(folder0);
    message2.save(folder0);
    message3.save(folder0);
    message4.save(folder0);
    
    message5.save(folder1);
    message6.save(folder1);
    message7.save(folder1);
    
    message1.print_debug();
    message5.print_debug();
    
    folder0.print_debug();
    folder1.print_debug();
    return 0;
}