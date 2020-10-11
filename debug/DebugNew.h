//********************
// Author:  yh
// Time:    2020/10/8.
// 
//********************
//

#ifndef DEBUG_DEBUGNEW_H
#define DEBUG_DEBUGNEW_H

#include "TraceNew.h"

#ifdef DEBUGNEW

#define new new(__FILE__, __LINE__)

#endif //DEBUG

#endif //DEBUG_DEBUGNEW_H
