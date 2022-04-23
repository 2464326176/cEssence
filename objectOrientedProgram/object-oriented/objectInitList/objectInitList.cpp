//**************************
// Author:  yh
// Time:    2022/4/17
//**************************

#include "objectInitList.h"

//2 先执行 被组合对象的构造函数
//如果组合对象有多个,按照定义顺序, 而不是按照初始化列表的顺序

//析构函数 : 和构造函数的调用顺序相反

//3 被组合对象的构造顺序 与定义顺序有关系 ,与初始化列表的顺序没有关系.
//4 初始化列表 用来 给const 属性赋值
void main()
{

    objectInitList0 obj1(10);
    objectInitList obj2(1, 2);

    objectInitList obj3(1, 2,3, 4);


    return ;
}
