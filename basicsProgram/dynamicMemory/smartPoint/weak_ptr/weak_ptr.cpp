/*
 * @Author: yh
 * @Date: 2022/5/26 23:35
 * @Description:
 * @FilePath: weak_ptr.cpp
 */

#include "weak_ptr.h"

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}