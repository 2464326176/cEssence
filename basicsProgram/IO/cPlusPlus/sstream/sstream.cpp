//**************************
// Author:  yh
// Time:    2022/5/1
//**************************

#include "sstream.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

bool valid(const string& str)
{
    return isdigit(str[0]);
}

string format(const string& str)
{
    return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}


void ReadFileToVec(const string &filename, vector<PersonInfo> &vec) {
    vec.clear();
    string line, word;
    ifstream ifs(filename);
    while (getline(ifs, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        vec.push_back(info);
    }
}

void run() {
    vector<PersonInfo> vec;
    ReadFileToVec("../staticFile/data/phonenumbers.txt", vec);
    /*for (const auto &str: vec) {
        for (const auto &phone: str.phones) {
            printf("%s %d\n", str.name.c_str(), phone.c_str());
        }
    }*/


    for (const auto &entry : vec)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
}

int main(int argc, char **argv) {
    run();

    return 0;
}