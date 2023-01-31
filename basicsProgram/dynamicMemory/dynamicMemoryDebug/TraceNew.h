/*
 * @Author: yh
 * @Date: 2022-05-20 23:53:25
 * @LastEditTime: 2020/10/8. 01:58:00
 * @Description: 
 * @FilePath: \cEssence\basicsProgram\dynamicMemory\dynamicMemoryDebug\TraceNew.h
 */
#ifndef DEBUG_TRACENEW_H
#define DEBUG_TRACENEW_H

#define DEBUGNEW

#ifdef DEBUGNEW
#include <iostream>
#include <map>

using namespace std;

void* operator new(size_t size, const char *file, long line);
void* operator new(size_t size);
void* operator new[](size_t size, const char *file, long line);
void operator delete(void *p);
void operator delete[](void *p);


class TraceNew {

    class TraceNewInfo
    {
    public:
        TraceNewInfo(const char *file = nullptr, long line = 0);
        const char* File() const;
        long Line() const;

    private:
        const char *file_;
        long line_;
    };

    class Lock
    {
    public:

        Lock(TraceNew &trace):trace_(trace)
        {
            trace_.lock_count_++;
        }

        ~Lock()
        {
            trace_.lock_count_--;
        }
    private:
        TraceNew &trace_;
    };
public:
    static bool Ready;
    TraceNew();
    ~TraceNew();
    void Add(void *p, const char *file, long line);
    void Remove(void *p);
    void DumpInfo();
private:
    std::map<void*, TraceNewInfo> trace_infos_;
    long lock_count_;
};

extern TraceNew NewTrace_;

#endif //DEBUGNEW

#endif //DEBUG_TRACENEW_H
