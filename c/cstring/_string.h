//**************************
// Author:  yh
// Time:    2022/1/3
//**************************

#ifndef CESSENCE__STRING_H
#define CESSENCE__STRING_H
/*
<cstring> (string.h)
定义了几个函数来操作 C 字符串和数组。
copy
memcpy 复制内存块void * memcpy ( void * destination, const void * source, size_t num );
memmove 移动内存块 void * memmove ( void * destination, const void * source, size_t num );
strcpy 复制字符串 char * strcpy ( char * destination, const char * source );
strncpy 从字符串中复制字符 char * strncpy ( char * destination, const char * source, size_t num );

strcat 连接字符串 char * strcat ( char * destination, const char * source );
strncat 从字符串追加字符 char * strncat ( char * destination, const char * source, size_t num );

memcmp 比较两个内存块 int memcmp ( const void * ptr1, const void * ptr2, size_t num );
strcmp 比较两个字符串 int strcmp ( const char * str1, const char * str2 );
strcoll 使用语言环境比较两个字符串
strncmp 比较两个字符串的字符
strxfrm 使用语言环境转换字符串

memchr 在内存块中定位字符    const void * memchr ( const void * ptr, int value, size_t num );
                            void * memchr (       void * ptr, int value, size_t num );
strchr 定位字符串中第一次出现的字符
strcspn 获取跨度直到字符串中的字符
strpbrk 定位字符串中的字符
strrchr 定位字符串中最后一次出现的字符
strspn 获取字符串中字符集的跨度 size_t strspn ( const char * str1, const char * str2 );
strstr 定位子串
strtok 将字符串拆分为标记

memset 填充内存块
strerror 获取指向错误消息字符串的指针 char * strerror ( int errnum );
strlen 获取字符串长度

NULL 空指针（宏）
size_t 无符号整数类型 (type )
 */
#endif //CESSENCE__STRING_H
