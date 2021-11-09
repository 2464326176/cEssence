//********************
// Author:  Administrator 
// Time:    2020/10/8.
// 
//********************
//

#include "TraceNew.h"

#ifdef DEBUGNEW
#include <cstdlib>
#include <iostream>

TraceNew NewTrace_;
bool TraceNew::Ready = false;


void* operator new(size_t size, const char* file, long line)
{

    void* p = malloc(size);
    if(TraceNew::Ready)
        NewTrace_.Add(p, file, line);
    return p;
}

void* operator new(size_t size)
{
    void *p = malloc(size);
    if(TraceNew::Ready)
        NewTrace_.Add(p, "unknow", -1);
    return p;
}

void* operator new[](size_t size, const char* file, long line)
{
    void *p = malloc(size);
    if(TraceNew::Ready)
        NewTrace_.Add(p, file, line);
    return p;
}

void operator delete(void* p)
{
    if(TraceNew::Ready)
        NewTrace_.Remove(p);
    free(p);

}

void operator delete[](void* p)
{
    if(TraceNew::Ready)
        NewTrace_.Remove(p);
    free(p);

}

TraceNew::TraceNew():lock_count_(0)
{
    TraceNew::Ready = true;

}

TraceNew::~TraceNew()
{
    TraceNew::Ready = false;
    DumpInfo();

}

void TraceNew::Add(void *p, const char *file, long line)
{
    if(lock_count_ > 0)
        return;
    Lock lock(*this);
    trace_infos_[p] = TraceNewInfo(file, line);

}

void TraceNew::Remove(void *p)
{
    if(lock_count_ > 0)
        return;
    Lock lock(*this);
    auto it = trace_infos_.find(p);
    if(it != trace_infos_.end())
    {
        trace_infos_.erase(it);
    }
}

void TraceNew::DumpInfo()
{
    for(auto trace_info : trace_infos_)
    {
        std::cout<< "0x" << trace_info.first << ":\t" << trace_info.second.File()
                << "\tIn line" << trace_info.second.Line() << std::endl;
    }
}

TraceNew::TraceNewInfo::TraceNewInfo(const char* file, long line):file_(file),line_(line)
{

}

const char* TraceNew::TraceNewInfo::File() const
{
    return file_;
}

long TraceNew::TraceNewInfo::Line() const
{
    return line_;
}
#endif //DEBUGNEW








