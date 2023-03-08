#include <iostream>
#include <vector>

int main(int argc, char **argv) {
    std::vector<int> v{10, 20, 30};
    std::string src{"string"};

    const char *charPtr = std::data(src);
    int *intPtr1 = std::data(v);
    int *intPtr2 = std::data();
    int *intPtr3 = std::data(v);

    std::cout << charPtr << "|" << *intPtr << std::endl;
    return 0;
}