# 函数

函数三要素：返回类型、函数名、形参类型；

函数的声明和定义分开，函数的声明一般写在头文件；

函数是一个命名了的代码块，函数有0~多个参数，通常会产生一个结果；可以支持重载，同一个名字对应几个不同的函数；一个函数一般包括：返回类型（return type）、函数名字、形参（parameter）组成的列表以及函数体；

通过调用运算符（call operator）来执行函数，调用运算符的形式是一对圆括号，他是一个表达式，该表达式是函数或者指向函数的指针；圆括号之内是一个用逗号隔开的实参（argument）列表，用实参来初始化函数的形参，调用表达式的类型就是函数的返回类型；

```c++
void doNothing1();// 隐式定义空形参列表
void doNothing2(void);// 显示定义空形参列表

int add(int a, int b) {
    return a + b; // 1.返回结果 2.控制权从被调函数返回到主调函数
}
int main() {
    add(4, 5); 
    //1.calling function -> called function
    //2. 实参初始化函数对应的形参
    return 0;
}
```

## 实参和形参

**Parameters**：在函数参数列表中声明的局部变量。它们由每个函数调用中提供的参数初始化。

**Arguments**：函数调用中提供的用于初始化函数参数的值。

```c++
(a) int f() {  // return should be string, not int
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }  // function needs return type
(c) int calc(int v1, int v1) { /* ... */ } 
// parameter list cannot use same name twice
(d) double square (double x) return x * x; // function body needs braces
```

## 局部对象

在c++中，名字有作用域，对象有声明周期（lifetime）；

- 名字的作用域是程序文本的一部分，名字在其中可见；
- 对象的生命周期是程序执行过程中该对象存在的一段时间；

## 自动对象

只存在与执行期间的对象成为自动对象（automatic object），当块的执行结束后，快中创建的自动对象的值就变成未定义的了；

形参是一种自动对象，函数开始为形参盛情存储空间，因为形参定义在函数体作用域之外，所以一旦函数终止，形参会被销毁；

用传递给函数的实参初始化形参对象的自动对象；对于局部变量对应的自动对象来说，变量定义含有初始值，就用这个初始值进行初始化；否则执行默认初始化；

## 局部静态对象

local static object：在程序的执行路径第一次经过对象定义语句时初始化，直到程序结束销毁；如果静态局部变量没有显示初始化，他将被执行值初始化，内置类型的局部变量初始化为0；

## 形参、局部变量、局部静态变量

**local variable**: 在块内定义的变量；

**parameter**: 在函数参数列表中声明的局部变量

**local static variable**: 在第一次执行通过对象的定义之前初始化局部静态变量（对象）。函数结束时不会破坏局部静态；当程序终止时，它们将被销毁。

## 分离式编程

## 参数传递

形参的类型决定了形参和实参交互的方式，如果形参是引用类型，它将绑定到对应的实参上；否则，将实参的值copy后赋值给形参；

当形参是引用类型时，对应的实参被引用传递（passed by reference）或者被引用调用（called by reference）；引用形参是它绑定的对象的别名；也就是说引用形参就是它对应的实参的别名；

当实参的值被copy赋值给形参，实参和形参是两个相互对立的对象；这样的实参被值传递（passed by value）或者函数被传值调用（called by value）；

## 指针形参

指针的行为和其他的非引用类型是一样的，当执行指针copy操作时，copy的时指针的值；copy后两个指针时不同的指针；因为指针使我们可以间接访问它所指的对象，所以通过指针可以修改它所指向的对象的值；

```c++
void reset(int *pInt) {
    *pInt = 0; // pInt 所指的对象值为0
    pInt = 0; // 只改变了pInt的局部copy 实参未被修改
}

int main() {
    int i = 5;//
    int k = i;// k是i的副本
    k = 42; // 值传递

    int n = 4, m = 5;
    int *p = &n, *q = &m;
    *p = 6; // n = 6
    p = q; // p指向了m， 但是m的值不变
    printf("m addr:%d m:%d, n addr:%d n:%d", m, &m, n, &n);

    reset(&m);
    printf("m addr:%d m:%d, n addr:%d n:%d", m, &m, n, &n);

    return 0;
}
```

传引用参数

```c++
int n = 0, i = 42;
int &r = n; // r绑定了n r是n的另外一个名字
r = 42; // n的值是42
r = i; // n和i相同
i = r; // i的值和n相同

// 该函数接受一个int对象的引用 然后将对象的值置为0
void reset(int &i) {  // i是传给reset函数的对象的另外一个名字
    i = 0;  // 改变了i所引对象的值
}

int j = 42;
reset(j); // j采用了引用方式 它的值被改变 j = 0

```


















