#include <iostream>


using namespace std;

template<typename T>
class SmartPtr {
public:
    SmartPtr() = default;
    
    SmartPtr(const T *ptr) {
        mRefCount = 1;
        mPtr = ptr;
    }

    SmartPtr(SmartPtr &smartPtr) {
        ++smartPtr.mRefCount;
        mRefCount = smartPtr.mRefCount;
        mPtr = smartPtr.ptr;
    }

    SmartPtr &operator==(SmartPtr &smartPtr) {
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

    ~SmartPtr() {}


private:
    void decrRefCount() {
        --mRefCount;
        if (0 == mRefCount) {
            delete mPtr;
        }
    }



private:
    size_t mRefCount = 0;
    T *mPtr = nullptr;
};