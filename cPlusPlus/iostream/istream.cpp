//**************************
// Author:  yh
// Time:    2021/11/7
//**************************
#include <iostream>

using namespace std;

istream& func(istream &ist) {
    string buf;
    while(ist >> buf) {
        cout << buf << endl;
    }
    ist.clear();
    return ist;
}

int main() {
    istream& is = func(cin);
    cout << is.rdstate() << endl;
    return 0;
}












