//**************************
// Author:  yh
// Time:    2022/4/17
//**************************

#include "object.h"

// 1
//		malloc	free				c语言的函数
//		new		delete 操作符	c++的语法
//2		new 基础类型变量  分配数组变量  分配类对象
//3

//assignment base type
void main01()
{
    //
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    //free(p);
    delete p;

    int *p2 = new int; //分配基础类型
    *p2 = 20;
    free(p2);
    //
    int *p3 = new int(30);
    printf("*p3:%d \n", *p3);
    //delete p3;
    free(p3);

    return ;
}

//assignment array type
void main02()
{
    //c语言分配数组
    int *p = (int *)malloc(sizeof(int) * 10);  //int array[10];
    p[0] = 1;
    //free(p);
    delete[] p;

    //c++分配数组
    int *pArray = new int[10] ;
    pArray[1] = 2;
    //delete [] pArray; //数组不要把[] 忘记
    free(pArray);

    char *pArray2 = new char[25] ; //char buf[25]
    delete [] pArray2;
    return ;
}

//分配对象new delete
//相同 和 不同的地方 new能执行类型构造函数   delete操作符 能执行类的析构函数

//	malloc 	free函数 C
//1 new 	delete 操作符号 c++的关键字
//结论
int main()
{
    //c
    Object *pT1 = (Object *)malloc(sizeof(Object));
    //free(pT1);
    delete pT1;

    //c++
    Object *pT2 = new Object(10);
    //delete pT2;
    free(pT2);

    return 0;
}