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

void ReadFileToVec(const string& filename, vector<string>& vec) {
    ifstream ifs(filename);
    if(ifs) {
        string buf;
        /*while(std::getline(ifs, buf)) {
            vec.push_back(buf);
        }*/
        while(ifs >> buf) {
            vec.push_back(buf);
        }
    } else {
        cout << "error open";
    }
}
int main() {
    vector<string> vec;
    ReadFileToVec("../cplus/", vec);

    for(const auto &str : vec) {
        cout << str << endl;
    }

    return 0;
}