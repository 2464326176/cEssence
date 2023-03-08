#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {

    list<int> L; // 1 2 3 4 5 6 7 8 9
    for (int i = 1; i < 9; ++i) {
        L.push_back(i);
    }
    list<int>::iterator LPOS = L.begin();

    cout << "The list L is: ( ";
    for (auto L_Iter = L.begin(); L_Iter != L.end(); L_Iter++) {
        cout << *L_Iter << " ";
    }
    cout << ")." << endl;

    cout << "The iterator LPOS initially points to the first element: " << *LPOS << "." << endl;

    advance(LPOS, 4); // backwards compatibility
    cout << "LPOS is advanced 4 steps forward to point"
         << " to the fifth element: " << *LPOS << "." << endl;

    advance(LPOS, -3); // forward
    cout << "LPOS is moved 3 steps back to point to the "
         << "2nd element: " << *LPOS << "." << endl;
}