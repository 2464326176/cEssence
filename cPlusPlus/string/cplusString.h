//********************
// Author:  yh 
// Time:    2020/11/1.
// 
//********************
//

#ifndef STRING_CPLUSSTRING_H
#define STRING_CPLUSSTRING_H



class String
{
public:
    String(const char *str = nullptr);
    String(const String &str);
    String & operator =(const String &str);

    char* c_str(){ return m_sptr;}
    void printS(){ std::cout << m_sptr << std::endl;}
    ~String();
private:
    char* m_sptr;
};


#endif //STRING_CPLUSSTRING_H
