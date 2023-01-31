#include <iostream>
#include <string>
#include <vector>

struct absInteger {
    int operator() (int i) const {
        return i > 0 ? i : -i;
    }
};

class GetInput {
public:
    GetInput(std::istream &i = std::cin) : is(i) { }
    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream &is;
};

int main() {
    // absInteger
    int i = -45;
    absInteger absObj;
    int result = absObj(i);
    std::cout << result << std::endl;

    // getInput
    GetInput getInput;
    std::cout << getInput() << std::endl;

    /*std::vector<std::string> vec;
    for ( std::string tmp; !( tmp = getInput() ).empty(); ) vec.push_back( tmp );
    for (const auto &str : vec) std::cout << str << " ";
    std::cout << std::endl;*/

    return 0;
}