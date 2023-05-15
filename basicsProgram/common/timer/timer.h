/*
 * @Author: yh
 * @Date: 2023-03-14 00:02:24
 * @LastEditTime: 2023-04-06 01:57:16
 * @Description:
 * @FilePath: \cEssence\basicsProgram\common\timer\timer.h
 */
#include <iostream>
#include <time.h>

using namespace std;

inline int64_t getTimeMicro() {
    timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    return ts.tv_sec * 1e9 + ts.tv_nsec;
}