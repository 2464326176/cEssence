//**************************
// Author:  yh
// Time:    2022/1/1
//**************************

#include "string.h"
#include <algorithm>

//赋值操作
/*
string &operator=(const string &s);//把字符串s赋给当前的字符串
string &assign(const char *s); //把字符串s赋给当前的字符串
string &assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
string &assign(const string &s);  //把字符串s赋给当前字符串
string &assign(int n,char c);  //用n个字符c赋给当前字符串
string &assign(const string &s,int start, int n);  //把字符串s中从start开始的n个字符赋给当前字符串
字符串连接
string &operator+=(const string &s);  //把字符串s连接到当前字符串结尾
string &operator+=(const char *s);//把字符串s连接到当前字符串结尾
string &append(const char *s);    //把字符串s连接到当前字符串结尾
string &append(const char *s,int n);  //把字符串s的前n个字符连接到当前字符串结尾
string &append(const string &s);   //同operator+=()
string &append(const string &s,int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string &append(int n, char c);   //在当前字符串结尾添加n个字符c
 */

void _print(string _str) {
    cout << _str << endl;
}
void _assign() {
    char cStr[] = "hello world!!!";
    string str;
    string str0("c++");
    string str1(str0);
    string str2(cStr);
    string str3(10, 'a');

    _print(str0);
    _print(str1);
    _print(str2);
    _print(str3);
    _print("-------------------");
    str.assign(cStr, 3);
    _print(str);
    str.assign(cStr, 2, 3);
    _print(str);
    str.assign(10, 'c');
    _print(str);
}
/*
int find(char c,int pos=0) const;  //从pos开始查找字符c在当前字符串的位置
int find(const char *s, int pos=0) const;  //从pos开始查找字符串s在当前字符串的位置
int find(const string &s, int pos=0) const;  //从pos开始查找字符串s在当前字符串中的位置
find函数如果查找不到，就返回-1
int rfind(char c, int pos=npos) const;   //从pos开始从后向前查找字符c在当前字符串中的位置
int rfind(const char *s, int pos=npos) const;
int rfind(const string &s, int pos=npos) const;
//rfind是反向查找的意思，如果查找不到， 返回-1
string &replace(int pos, int n, const char *s);//删除从pos开始的n个字符，然后在pos处插入串s
string &replace(int pos, int n, const string &s);  //删除从pos开始的n个字符，然后在pos处插入串s
void swap(string &s2);    //交换当前字符串与s2的值

 */
void _find_replace() {
    string s1 = "c++ yu c++ yu c++ java java";
    size_t index = s1.find("c++", 0);
    cout << "index: " << index << "\n";

    index = s1.find("c++", 0);
    while (index != string::npos)
    {
        cout << "index: " << index << " find c++\n";
        index = s1.find("c++", index + 1);
    }

    //replace
    string s2 = "c++ hello c++ 111 c++ 222 c++ 333";
    s2.replace(0, 3, "php");
    cout << s2 << endl;

    index = s2.find("c++", 0);
    while (index != string::npos)
    {
        cout << "index: " << index << " find c++\n";
        s2.replace(index, 3, "php");
        index = index + 1;
        index = s1.find("c++", index);
    }
    cout << "s2: " << s2 << endl;
}

/*
string &insert(int pos, const char *s);
string &insert(int pos, const string &s);
//前两个函数在pos位置插入字符串s
string &insert(int pos, int n, char c);  //在pos位置 插入n个字符c
string &erase(int pos=0, int n=npos);  //删除pos开始的n个字符，返回修改后的字符串
 */

void _insert_earse() {
    string str("qwer hello world");
    _print(str);
    str.insert(0, "lol");
    _print(str);
    str.insert(0, 12, 'c');
    _print(str);
    str.erase(0, 6);
    _print(str);
    string substr = str.substr(0, 6);
    _print(substr);
    char _copystr[20]{""};
    str.copy(_copystr, 8, 0);
    _print(_copystr);
    string _copyStr;
}

void _algorithms() {
    string s2 = "AAAbbb";
    std::transform(s2.begin(), s2.end(), s2.begin(), toupper);
    cout << s2 << endl;
    string s3 = "AAAbbb";
    std::transform(s3.begin(), s3.end(), s3.begin(), tolower);
    cout << s3 << endl;
}

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); ) {
        if (oldVal == string{ cur, cur + oldVal.size() }){
            cur = s.erase(cur, cur + oldVal.size()),
            cur = s.insert(cur, newVal.begin(), newVal.end()),
            cur += newVal.size();
        } else {
            ++cur;
        }
    }

}

int _replace()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    cout << s << endl;

    return 0;
}

void _find_first_of()
{
    string numbers{ "123456789" };
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    string str{ "ab2c3d7R4E6" };

    cout << "numeric characters: ";
    for (int pos = 0; (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << "\nalphabetic characters: ";
    for (int pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;
}

int main() {
    //_assign();
    //_find_replace();
    //_insert_earse();
    //_algorithms();


    return 0;
}


















