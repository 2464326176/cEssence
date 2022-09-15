/*
 * @Author: yh
 * @Date: 2022/9/12 23:55
 * @Description: 
 * @FilePath: StrVec.h
 */

#ifndef CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_STRVEC_H
#define CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_STRVEC_H
#include <string>
#include <memory>

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<string>);
    StrVec(const StrVec &);
    StrVec(const StrVec &&) noexcept;
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();
    
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    
    string &at(size_t pos) { return *(elements + pos); }
    const string &at(size_t pos) const { return *(elements + pos); }
    
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string &);

private:
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    };
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string *, string *);
private:
    string *elements;
    string *first_free;
    string *cap;
    static std::allocator<string> alloc;
};

#endif //CESSENCE_OBJECTORIENTEDPROGRAM_OBJECT_ORIENTED_COPYCONTROL_STRVEC_H
