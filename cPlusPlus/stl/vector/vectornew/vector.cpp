//********************
// Author:  yh 
// Time:    2020/10/11.
// 
//********************
//

void str_int()
{
    /*
     * std::pair<std::string, int>
     * std::make_pair(str, i)
     * { str, i }
     * str, i
     */

    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int i;
    std::cin >> str >> i;
    //while (std::cin >> str >> i)
    //vec.push_back(std::pair<std::string, int>(str, i));
    //vec.push_back(std::make_pair(str, i));
    //vec.push_back({ str, i });
    vec.emplace_back(str, i); //!! easiest way.

    for (const auto &p : vec)
        std::cout << p.first << ":" << p.second << std::endl;
}