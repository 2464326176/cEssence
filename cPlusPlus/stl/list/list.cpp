//**************************
// Author:  yh
// Time:    2022/1/3
//**************************

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>

using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::end;
using std::forward_list;

int text()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    // init
    vector<int> vec(ia, end(ia));
    list<int> lst(vec.begin(), vec.end());

    // remove odd value
    for(auto it = lst.begin();  it != lst.end(); )
        if(*it & 0x1) it = lst.erase(it);
        else ++it;

    // remove even value
    for(auto it = vec.begin();  it != vec.end(); )
        if(! (*it & 0x1)) it = vec.erase(it);
        else ++it;

    // print
    cout << "list : ";
    for(auto i : lst)   cout << i << " ";
    cout << "\nvector : ";
    for(auto i : vec)   cout << i << " ";
    cout << std::endl;

    return 0;
}

template <typename T>
void _print(forward_list<T> &V) {
    for(auto &v : V) {
        cout << v << " ";
    }
    cout << endl;
}

void find_and_insert(forward_list<string> &list, string const& to_find, string const& to_add)
{
    auto prev = list.before_begin();
    for (auto curr = list.begin(); curr != list.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            list.insert_after(curr, to_add);
            return;
        }
    }
    list.insert_after(prev, to_add);
}

int main() {
    std::forward_list<string> fStr{"str", "yuh", "asdd", "asdw2", "asdasd"};
    find_and_insert(fStr, "QWER", "bb");
    _print(fStr);


    return 0;
}