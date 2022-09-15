/*
 * @Author: yh
 * @Date: 2022/9/12 0:00
 * @Description: 
 * @FilePath: String.h
 */

#ifndef CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_STRING_H
#define CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_STRING_H
#include <memory>

class String {
public:
    String() : String("") {}
    String(const char *);
    String(const String &);
    String(String &&) noexcept;
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
    ~String();
    
    const char *c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void range_initializer(const char *, const char *);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

#endif //CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_STRING_H
