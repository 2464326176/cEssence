# 引用（reference）

引用为对象起了另外一个名字，引用类型引用另外一种类型；

```c++
int value = 1024;
int &refVal = value; // refVal ??value ?value???????
//int &refVale2; //error

int &refVal3 = refVal; //refVal3???value
printf("%d %d %d \n", value, refVal, refVal3); // 1024 1024 1024

int i= refVal; // i?????value??
refVal3 = 101;
printf("%d %d %d %d\n", value, refVal, refVal3, i); // 101 101 101 1024


//int &refVal4 = 10;
double dValue = 3.1415926;
//int &refValue5 = dValue; //error ?????????
```

一般初始化变量的时候，初始值会被copy到新建的对象中，然后定义引用时，程序把引用和他的初始值绑定在一起，而不是把初始值copy给引用；一旦初始化完成，引用将和他的初始值对象一直绑定在一起，因为无法令引用重新绑定到另外一个对象因此必须初始化；

引用并非对象，他是一个已经存在的对象所起的另外一个名字；

# 指针（pointer）

指针是指向另外一种类型的复合类型，与引用类似，指针也实现了对对象的间接访问，然而指针与引用相比有一些不同之处；

- 指针本身就是一个对象，允许指针赋值和拷贝，而且指针的声明周期内它可以指向不同的对象；
- 指针无需定时时赋值初始化，和其他的内置类型一样，在块作用域内定义的指针如果没有被初始化，也将拥有一个不确定的值；

```c++
int *ip1, *ip2; // ip1 ip2 都是指向int型对象的指针
double dp, *dp2; // dp2是指向double型对象的指针 dp是double型对象

int ival = 42;
// p是一个指向int的指针 初始化p使得它指向ival的int对象
// 因为 引用不是对象 没有实际的地址 所以不能定义指向引用的指针
int *p = &ival; // p存放ival的地址 p是指向ival的指针

double dval;
double *pd = &dval; // p 指向double型对象的地址
double *pd2 = pd; // pd2指向pd 指向double型对象的指针

// 在声明语句中指针的类型实际上被用于指定它所指向对象的类型 所以两者必须匹配
//int *pi1 = pd; // error 类型不匹配
//int *pi2 = &dval;; // error 类型不匹配
```

## 指针的值

- 指向一个对象；
- 指向紧邻对象所占空间的下一个位置；
- 空指针，没有指向任何的对象；
- 无效指针；

# 指针和引用

```c++
{
    int iv = 42;
    int *piv = &iv;
    cout << *piv;   // 由符号*（解引用符号）得到指针p所指向的对象，输出42；
    *p = 58; // 由符号*得到指针p所指向的对象 既可由p为变量ival赋值
    cout << *piv;

    int i = 43;
    int &r = i; // &紧随着类型名出现 是声明的一部分 r是一个引用
    int *pi; // &紧随着类型名出现 是声明的一部分 p是一个指针
    pi = &i; // &在表达式中 是一个取地址符号
    *pi = i; // *在表达式中 是一个解引用符号
    int &r2 = *pi; // &是声明的一部分 *是一个解引用符号
}

{
    // 指向指针的指针
    int iVal = 1024;
    int *piVal = &iVal; // p1 指向int型的数
    int **ppiVal = &piVal; // ppi指向int型的指针
}


{
    //指向指针的引用
    int i = 42;
    int *p; // p 是一个对int型的指针
    int *&r = p; // r 是一个对指针p的引用 r是p的别名
    r = &i; //r 引用了一个指针  p也指向对象i
    *r = 0; // 解引用i  将i改成0
}
```





















