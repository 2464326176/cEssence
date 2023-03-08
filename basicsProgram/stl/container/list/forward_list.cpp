#include <forward_list>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    std::forward_list<std::pair<string, int>> fl;
    fl.emplace_after(fl.before_begin(), "c++", 18);
    fl.emplace_after(fl.before_begin(), "java", 14);
    fl.emplace_front("php", 14);

    fl.insert_after(fl.begin(), {"html", 14});
    fl.insert_after(fl.before_begin(), {"html1", 14});
    fl.insert_after(fl.cbefore_begin(), {"html2", 14});
    for (auto const &item : fl) {
        cout << item.first << " " << item.second << ", ";
    }
    cout << endl;
    return 0;
}