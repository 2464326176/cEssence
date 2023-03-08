//**************************
// Author:  yh
// Time:    2022/5/15
//**************************
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int myCompare(int x, int y) {
    return x > y;
}

int main() {
    int myArray[] = {1, 6, 8, 4, 3, 2, 3, 5, 1};
    printf("%d %d\n", sizeof(myArray), sizeof(myArray) / sizeof(int));
    vector<int> v(myArray, myArray + sizeof(myArray) / sizeof(int));

    //stable_sort(v.begin(), v.end());// 1 1 2 3 3 4 5 6 8
    stable_sort(v.begin(), v.end(), myCompare);// 8 6 5 4 3 3 2 1 1

    for(auto &val : v) {
        std::cout << val << " ";
    }
    std::cout << endl;

    vector<int>::iterator low, up;
    pair<vector<int>::iterator, vector<int>::iterator> equal;
    // lower_bound Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
    // upper_bound Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
    //A pair object, whose member pair::first is an iterator to the lower bound of the subrange of equivalent values, and pair::second its upper bound.
    //The values are the same as those that would be returned by functions lower_bound and upper_bound respectively.
    // lower_bound(first, last, val); key >= val
    // upper_bound(first, last, val); key > val
    // equal_range [lower_bound, upper_bound]
    low = lower_bound(v.begin(), v.end(), 4);
    up = upper_bound(v.begin(), v.end(), 4);
    equal = equal_range(v.begin(), v.end(), 4);
    printf("low: %d up: %d\n", low - v.begin(), up - v.begin());
    printf("equal: %d %d\n", equal.first - v.begin(), equal.second - v.begin());

    bool isSearch = binary_search(v.begin(), v.end(), 4, myCompare);
    printf(" %s \n", isSearch ? "found " : "no found");
    return 0;
}