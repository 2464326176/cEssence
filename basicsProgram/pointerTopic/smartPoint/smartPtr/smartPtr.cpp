/*
 * @Author: yh
 * @Date: 2023/11/26 2:49
 * @Description:
 * @FilePath: smartPtr.cpp
 */
#include <iostream>
#include "../autoPtr/test.h"
template <class T>
class SmartPtr {
public:
    SmartPtr() = default;
    SmartPtr(T *ptr) {
        mPtr = ptr;
        mRefCount = 1;
    }

    SmartPtr(SmartPtr &smartPtr) {
        ++smartPtr.mRefCount;
        mPtr = smartPtr.mPtr;
        mRefCount = smartPtr.mRefCount;
    }

    SmartPtr<T> &operator=(SmartPtr<T> &smartPtr) {
        ++smartPtr.mRefCount;
        decrRef();
        mPtr = smartPtr.mPtr;
        mRefCount = smartPtr.mRefCount;
        return *this;
    }

    T* operator->() {
        if (mPtr) {
            return  mPtr;
        }

        throw std::runtime_error("null pointer");
    }

    T& operator*() {
        if (mPtr) {
            return  *mPtr;
        }

        throw std::runtime_error("null pointer");
    }

    ~SmartPtr() {
        decrRef();
    }

private:
    void decrRef() {
        if (--mRefCount == 0) {
            delete mPtr;
            mPtr = NULL;
        }
    }

    size_t mRefCount = 0;
    T *mPtr = nullptr;
};


int main(int argc, char **argv) {
    SmartPtr<Test> t1;
    SmartPtr<Test> t2(new Test("hello"));
    SmartPtr<Test> t3(new Test("world"));

    try {
        t1->showName();
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    t2->showName();
    *t2 = "hello hello";
    t2->showName();
    t2 = t3;

    return 0;
}