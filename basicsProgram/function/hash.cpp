/*
 * @Author: yh
 * @Date: 2022/9/11 15:08
 * @Description: 
 * @FilePath: hash.cpp
 */

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

struct S {
    std::string first_name;
    std::string last_name;
};
bool operator==(const S &lhs, const S &rhs) {
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

// �Զ���ɢ�к������Ƕ�����������
struct MyHash {
    std::size_t operator()(S const &s) const {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // ��ʹ�� boost::hash_combine �������ۣ�
    }
};

// std::hash ���Զ����ػ���ע�� namespace std
namespace std {
template<> struct hash<S> {
    typedef S argument_type;
    typedef std::size_t result_type;
    result_type operator()(argument_type const &s) const {
        result_type const h1(std::hash<std::string>{}(s.first_name));
        result_type const h2(std::hash<std::string>{}(s.last_name));
        return h1 ^ (h2 << 1); // ��ʹ�� boost::hash_combine �������ۣ�
    }
};
}

int main() {
    
    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << '\n';
    
    S obj = {"Hubert", "Farnsworth"};
    // ʹ�ö����ĺ�������
    std::cout << "hash(" << std::quoted(obj.first_name) << ','
              << std::quoted(obj.last_name) << ") = "
              << MyHash{}(obj) << " (using MyHash)\n                           or "
              << std::hash<S>{}(obj) << " (using std::hash) " << '\n';
    
    // �Զ���ɢ�к�����������������ʹ���Զ������Ϳ���
    // ��ʾ����ʹ��ע��� std::hash �ػ���
    // ��Ҫʹ�� MyHash �����������Ϊ�ڶ�ģ���������
    std::unordered_set<S> names = {obj, {"Bender", "Rodriguez"}, {"Leela", "Turanga"}};
    for (auto &s: names)
        std::cout << std::quoted(s.first_name) << ' ' << std::quoted(s.last_name) << '\n';
}