//**************************
// Author:  yh
// Time:    2021/12/24
//**************************

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

void readFileToOtherFile(const string& inputFile, const string& outputFileOdd, const string& outputFileEven) {
    ifstream ifs(inputFile);
    ofstream ofs_odd(outputFileOdd), ofs_even(outputFileEven);

    istream_iterator<int> in(ifs), in_eof;
    ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, " ");

    for_each(in, in_eof, [&out_odd, &out_even](const int i) {
        *((i & 0x1 ) ? out_odd : out_even)++ = i;
    });
}



int main() {
    readFileToOtherFile("../cPlusPlus/data/input.txt", "../cPlusPlus/data/odd.txt", "../cPlusPlus/data/even.txt");

    return 0;
}