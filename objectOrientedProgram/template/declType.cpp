//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename It>
It &fcn(It begin, It end) {
    return begin;
}

template <typename It>
auto fdeclType(It begin, It end)-> decltype(*begin) {
    return *begin;
}
int main() {
    vector<int> vi{1, 2, 3, 4, 5};
    vector<string> vc{"111", "222"};
    auto &i = fcn(vi.begin(), vi.end());
    auto &s = fcn(vc.begin(), vc.end());
    auto &ideclType = fdeclType(vi.begin(), vi.end());
    auto &sdeclType = fdeclType(vc.begin(), vc.end());
    cout << "i " << &i << endl;
    cout << "s " << &s << endl;
    cout << "sdeclType " << ideclType << endl;
    cout << "ideclType " << sdeclType << endl;

    return 0;
}
