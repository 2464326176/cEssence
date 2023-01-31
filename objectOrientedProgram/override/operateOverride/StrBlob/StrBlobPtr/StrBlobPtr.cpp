/*
 * @Author: yh
 * @Date: 2023-01-29 23:04:47
 * @LastEditTime: 2023-01-29 23:06:52
 * @Description: 
 * @FilePath: \cEssence\objectOrientedProgram\override\operateOverride\StrBlob\StrBlobPtr\StrBlobPtr.cpp
 */
#include <iostream>

StrBlobPtr&
StrBlobPtr_pointer::operator *() const
{
    return *pointer;
}

StrBlobPtr*
StrBlobPtr_pointer::operator ->() const
{
    return pointer;
}

int main()
{
    StrBlob sb{ "hello", "world" };
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_pointer p(&iter);
    std::cout << p->deref() << std::endl;
}
