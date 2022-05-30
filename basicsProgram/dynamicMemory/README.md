# 一、动态内存

## 1.1 静态内存

用来保存局部static对象、类static数据成员以及定义在任意函数之外的变量；

## 1.2 栈内存

栈内存用来保存定义在函数内的非static对象，分配在静态内存或者栈内存的对象由编译器自动创建和销毁，对于栈对象，仅在其定义的程序块运行时才存在；static对象在使用之前分配，在程序结束时销毁；

## 1.3 自由内存（free store）或者堆（heap）

程序员用堆来存储动态分配（dynamic allocate）的对象，那些在程序运行时分配的对象，对象的声明周期由程序员来控制，也就是动态对象不在使用时，必须用代码显式销毁它们；

## 二、智能指针（smart pointer）

智能指针类似于常规的指针，重要的区别在于他负责自动释放所指向的对象，新标准提供两种智能指针区别在于管理底层指针的方式，头文件在memory中。

## 2.1 shared_ptr

允许多个指针指向同一个对象；

```c++
//shared_ptr和unique_ptr都支持的操作
shared_ptr<T> sp;
unique_ptr<T> up;
p					//把p作为一个条件判断，若p指向一个对象，则为true
*P					// 解引用p 获取它指向的对象
p->mem				// 等价于(*p).mem
p->get();			//返回p中保存的指针，使用前要判空
swap(p, q);			// 交换
p.swap(q);
//shared_ptr 独有的操作
make_shared<T>(args);    //返回一个shared_ptr 指向一个动态分配的类型为T的对象，使用args初始阿化对象；
shared_ptr<T> P(q); 	 // p是q的拷贝，会增加q的计数器，q中的指针必须能转化为T*
p = q;					 // p q都是shared_ptr 所保存的指针必须能相互转化，此操作会减少p的引用计数，增加q的引用计数，若q的引用计数变成0 则将其管理的内存释放
p.unique();				 // p.use_count()为1 返回true，否则返回false
p.use_count();			 // 返回与p共享对象的智能指针数量 比较慢 用于调试
// 安全的分配内存函数
shared_ptr<int> p3 = make_shared<int>(423); // 423
shared_ptr<string> p3 = make_shared<int>(10, '9'); // "9999999999"
shared_ptr<int> p3 = make_shared<int>(); // 0
```

### 2.1.1 直接管理内存

```c++
string *ps = new string; // 默认初始化为空的string
string *ps = new string(); // 值初始化为空的string
int *pi = new int; // pi 指向一个为初始化的值
int *pi = new int(); // 初始化为0
int *pi = new int(1024);
vector<int> *pv = new vector<int>{0, 1, 2};
auto p1 = new auto(obj);
auto p2 = new auto{a, b ,c}; //error 括号智能由单个初始化器
int *p1 = new int; // 申请失败 new 抛出std::bad_alloc
int *p2 = new (nothrow) int; // 申请失败返回一个空指针
```

### 2.1.2 shared_ptr和new结合使用

``` c++
shared_ptr<double>  p1;
// 智能指针构造函数是explicit 不能把一个内置指针隐式转化为一个智能指针 必须使用直接初始化方式
shared_ptr<double>  p2 = new double(3.14); // error   必须使用直接初始化方式
shared_ptr<double>  p3(new double(3.14)); //正确

// error
shared_ptr<int> clone(int p) {
    return new int(p); // 隐式转化为shared_ptr<int>
}

shared_ptr<int> clone(int p) {
    return shared_ptr<int>(new int(p)); // 隐式转化为shared_ptr<int>
}
```

```c++
shared_ptr<T> P(q);  // p管理内置指针q的对象，必须指向new分配的内存 且能够转换为T*类型
shared_ptr<T> P(u); // p从unique_ptr 接管了对象的所有权 将u置为空
shared_ptr<T> P(q, d); // p接管了q所指向的对象的所有权 q必须能转换为T*类型的，p将使用对象d代替delete
shared_ptr<T> P(p2, d); // p是shared_ptr p2的拷贝，唯一的区别是p将用可调用对象代替delete

p.reset()  // 若p是唯一指向其对象的shared_ptr,reset会释放此对象；
p.reset(q)  // 将p指向q 
p.reset(q, d)  // 会调用d而不是delete来释放q
```

## 2.2 unique_ptr

独占所指向的对象；

## 2.3 weak_ptr

它是一种弱引用，指向shared_ptr所管理的对象；weak_ptr时一种不控制所指向对象生存周期的智能指针，它指向有一个shared_ptr管理的对象，将一个weak_ptr绑定到一个shared_ptr不会改变shared_Ptr的引用计数。一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放。即便由weak_ptr指向对象，对象还是会被释放，因此weak_ptr的名字抓住了这种智能指针弱共享对象的特点；

```
weak_ptr<T> W 空的weak_ptr可以指向类型为T的对象
weak_ptr<T> W(sp)  与shared_ptr  sp指向的相同的对象的weak_ptr,T必须能被转换为sp指向的类型；
w = p;  p可以是一个shared_ptr或者一个weak_ptr，赋值后w与p共享对象；
w.reset();    将w置空
w.user_count()  与w共享对象的shared_ptr的数量
w.expired()  若w.use_count()为0 返回true 返回false
w.lock()   若expired为true， 返回一个空的shared_ptr 否则返回一个指向w的对象的shared_ptr;
```

## 2.4 new 和shared_ptr unique_ptr

```c++
    int *p1 = new int; // 16211936
    int *p2 = new int(); // 0
    int *p3 = new int(0); // 0
    int *pia1 = new int[10]; // 16211936 0 16187728 0 0 0 150994953 29383 16211936 0
    int *pia2 = new int[10](); // 0 0 0 0 0 0 0 0 0 0
    int *pia3 = new int[10]{1, 3, 5, 7, 8, 9, 6}; // 1 3 5 7 8 9 6 0 0 0
    
    string *ps1 = new string[10];
    string *ps2 = new string[10](); // null
    string *ps3 = new string[10]{"a", "bbb", "cc", "dasd", "asdk", "aksdl;a"}; // a bbb cc dasd asdk aksdl;a
    
    // 当一个unique_ptr指向一个数组时，我们不能使用点和箭头成员运算符（指向数组的unique_ptr 不支持成员访问运算符）
    // 我们可以使用下表运算符来访问数组中的元素
    unique_ptr<int[]> p(new int[12]{1, 3, 8, 9, 74, 59, 6, 12, 45});
    
    for (int i = 0; i < 12; ++i) {
        printf("%d ", p[i]);
    }
    printf("\n");
    for (int *q = p.get(); q != p.get() + 12; ++q) {
        printf("%d ", *q);
        *q = 89;
    }
    printf("\n");
    
    for (int i = 0; i < 12; ++i) {
        printf("%d ", p[i]);
    }
    
    p.release(); // 自动调用delete[] 销毁其指针


    //shared_ptr<int[]> sp(new int[12]{8, 88, 8, 9, 74, 59, 6, 12, 45}, [](int *p) { delete[] p; }); // 可以使用下表
    shared_ptr<int> sp(new int[12]{8, 88, 8, 9, 74, 59, 6, 12, 45}, [](int *p) { delete[] p; }); // 不可以使用下表
    
    for (int *q = sp.get(); q != sp.get() + 12; ++q) {
        printf("%d ", *q);
        *q = 89;
    }
    printf("\n");
    
    for (int *q = sp.get(); q != sp.get() + 12; ++q) {
        printf("%d ", *q);
    }
    
    sp.reset(); // 自动调用delete[] 销毁其指针
```

















