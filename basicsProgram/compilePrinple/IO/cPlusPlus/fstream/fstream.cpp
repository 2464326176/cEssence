//**************************
// Author:  yh
// Time:    2021/11/9
//**************************

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

void ReadFileToVecByWord(const string &filename, vector<string> &vec) {
    vec.clear();
    ifstream ifs(filename);
    if (ifs) {
        string buf;
        // 单个字段读取 遇到空格换行符会挺
        while (ifs >> buf) {
            vec.push_back(buf);
        }
    } else {
        cout << "error open";
    }
}

void ReadFileToVecByLine(const string &filename, vector<string> &vec) {
    vec.clear();
    ifstream ifs(filename);
    if (ifs) {
        string buf;
        //整行读取
        while (std::getline(ifs, buf)) {
            vec.push_back(buf);
        }
    } else {
        cout << "error open";
    }
}

void run() {
    vector<string> vec;
    ReadFileToVecByWord("../objectOrientedProgram/data/phonenumbers.txt", vec);
    for (const auto &str: vec) {
        cout << str << endl;
    }

    ReadFileToVecByLine("../objectOrientedProgram/data/phonenumbers.txt", vec);
    for (const auto &str: vec) {
        cout << str << endl;
    }
}
int main(int argc, char **argv) {
    printf("argc: %d, argc: %s\n", argc, *argv);
    int i = 0;
    while(i < argc) {
        printf("%s\n", argv[i++]);
    }

    return 0;
}