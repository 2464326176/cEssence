//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#ifndef CESSENCE_STRVEC_H
#define CESSENCE_STRVEC_H
#include <string>
#include <memory>
class strVec {
public:
    strVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    strVec(std::initializer_list<std::string> _list);
    strVec(const strVec& _str);
    strVec& operator=(const strVec& _refStr);
    strVec& operator+(const strVec& _refStr);
    ~strVec();

    void push_back(const std::string& _str);
    void reserve(std::size_t n);
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string& _str);
    std::size_t size() const { return first_free - element; }
    std::size_t capacity() const { return cap - element; }

    std::string* begin() const { return element; }
    std::string* end() const { return first_free; }
private:
    std::string* element;
    std::string* first_free;
    std::string* cap;
    std::allocator<std::string> alloc;

    void reallocate();
    void chk_n_alloc()      { if (size() == capacity()) reallocate(); }
    void free();
    // used in reallocate() reserve() and resize().
    void wy_alloc_n_move(std::size_t n);
    std::pair<std::string*, std::string*>
    alloc_n_copy (std::string* b, std::string* e);
};
#endif //CESSENCE_STRVEC_H
