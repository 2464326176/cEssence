//**************************
// Author:  yh
// Time:    2021/11/7
//**************************
#include <iostream>
#include <cstring>

#define STR_BUF_LENGTH    64

using namespace std;

istream &func(istream &ist) {
    string buf;
    while (ist >> buf) {
        cout << buf << endl;
    }
    ist.clear();
    return ist;
}

int main11() {
    istream &is = func(cin);
    cout << is.rdstate() << endl;
    return 0;
}

void getLine() {
    char str[STR_BUF_LENGTH], str1[STR_BUF_LENGTH];
    cin.clear();
    cout << "please input a word: \n";
    cin.getline(str, STR_BUF_LENGTH); // exitn
    std::cout << cin.gcount() << " characters read: " << str << " sizeof(str) " << sizeof(str) << " strlen(str)"
              << strlen(str) << "\n";
    cin.clear();
    cout << "please input a word: \n";
    cin.getline(str1, STR_BUF_LENGTH, 'n'); // 给str1前插入\n  不会加上n
    std::cout << cin.gcount() << " characters read: " << str1 << " sizeof(str1) " << sizeof(str1) << " strlen(str1)"
              << strlen(str1) << "\n";

/*
please input a word:
exitn
6 characters read: exitn sizeof(str) 64 strlen(str)5
please input a word:
exitn
5 characters read: exit sizeof(str1) 64 strlen(str1)4
*/
}

void get() {
    char str2[STR_BUF_LENGTH], str3[STR_BUF_LENGTH];
    cout << "please input a word: \n";

    cin.clear();
    cin.get(str2, STR_BUF_LENGTH);
    // 字符串之前没有加上\n
    std::cout << cin.gcount() << " characters read: " << str2 << " sizeof(str2) " << sizeof(str2) << " strlen(str2)"
              << strlen(str2) << "\n";

    cout << "please input a word: \n";
    cin.clear();
    // 字符串之前加上\n
    cin.get(str3, STR_BUF_LENGTH, 'n');
    std::cout << cin.gcount() << " characters read: " << str3 << " sizeof(str3) " << sizeof(str3) << " strlen(str3)"
              << strlen(str3) << "\n";
/*
    please input a word:
    exitn
    5 characters read: exitn sizeof(str2) 64 strlen(str2)5
    please input a word:
    exitn
    5 characters read:
    exit sizeof(str3) 64 strlen(str3)5
*/
}

void ignore() {
    char first, last;
    std::cout << "Please, enter your first name followed by your surname: ";
    first = std::cin.get();     // get one character
    std::cin.ignore(256,' ');   // ignore until space
    last = std::cin.get();      // get one character
    std::cout << "Your initials are " << first << last << '\n';
}


int main() {
    //get();
    //getLine();

    return 0;
}





