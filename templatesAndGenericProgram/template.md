# 泛型编程

C++提供两种模板机制：**函数模板、类模板**，使得程序（算法）可以从逻辑功能上抽象，把被处理的对象（数据）类型作为参数传递。

# 函数模板

函数模板(function template)： 实际上是建立一个通用函数，其函数类型和形参类型不具体指定，用一个虚拟的类型来代表。这个通用函数就称为函数模板。凡是函数体相同的函数都可以用这个模板来代替，不必定义多个函数，只需在模板中定义一次即可。在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能。

- 模板把函数或类要处理的数据类型参数化，表现为参数的多态性，称为类属。
- 模板用于表达逻辑结构相同，但具体数据元素类型不同的数据对象的通用行为。

## 函数模板机制结论

- 编译器并不是把函数模板处理成能够处理任意类的函数；
- 编译器从函数模板通过具体类型产生不同的函数；
- 编译器会对函数模板进行**两次编译；**在声明的地方对模板代码本身进行编译；在调用的地方对参数替换后的代码进行编译。

## template和class

template和class 没有本质区别，当希望通知编译器的一个名字表示类型的时候，必须使用关键字typename，不能使用class

```c++
//实例化声明。它的定义在别处
extern template class vector<string>;
//实例化定义。编译器将为它生成代码。 
template class vector<Sales_data>;
```

类型转化与模板类型参数

能调用应用于函数模板的：

const转换：可以将一个非const对象的引用（或者指针）传递给一个const的引用（或指针）形参

数组或函数到指针的转换：如果函数形参不是引用类型，可以对数组或函数类型的实参应用于正常的指针转换。一个数组的实参可以转换为一个指向其首元素的指针。

```c++
template<typename T> T fobj(T, T);   //实参被copy
template<typename T> T fref(const T&, const T&);   //引用
string s1("hello world");
const string s2("another value");
fobj(s1, s2);  // fobj(); const 被忽略
fref(s1, s2); //fref(const string&, const string&)`
int m_a[10], b[42];
fobj(m_a, b); // f(int*, int*)` 
fref(m_a, b); //error array type mismatch

template <class T> int compare(const T&, const T&);
compare("hi", "world"); //error static int compare(const char (&)[3], const char (&)[3])
compare("bye", "dad"); // template<T> int compare(const T &, const T &)

template <typename T> T f1(T, T) {};
template <typename T1, typename T2> T1 f2(T1, T2) {};

int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
f1(p1, p2);     // f1<int*>(int*, int*)
f2(p1, p2);     // f2<int*, int*>(int*, int*)
f1(cp1, cp2);   // f1<int const*>(int const*, int const*)
f2(cp1, cp2);   // f2<int const*, int const*>(int const*, int const*)
//f1(p1, cp1);    // deduced conflicting types for parameter 'T'
f2(p1, cp1);    // f2<int*, int const*>(int*, int const*)
// explicit template argument
template<typename T1, typename T2, typename T3> T1 sum(T2, T3);
auto val3 = sum<long long>(i, lng); // long long sum(int long)
```

将实参传递给带模板类型的函数形参时， 能够自动应用的类型转换只有const转化及数组或函数到指针的转换。

在模板参数推导过程中会发生什么？
从函数参数中确定模板参数的过程称为模板参数推导。在模板参数推导期间，编译器使用调用中的参数类型来查找生成与给定调用最匹配的函数版本的模板参数。
命名模板参数推导中涉及的函数参数允许的两种类型转换。
 • const 转换：作为const 引用（或指针）的函数参数可以传递一个对非常量对象的引用（或指针）
 • 数组或函数到指针的转换：如果函数参数不是引用类型，那么普通的指针转换将应用于数组或函数类型的参数。数组参数将转换为指向其第一个元素的指针。类似地，函数参数将被转换为指向函数类型的指针

## 函数模板和普通函数

```c++
void swapVariable(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    cout << "swapVariable(int &a, int &b)" << endl;
}

void swapVariable(char &a, char &b) {
    char t = a;
    a = b;
    b = t;
    cout << "swapVariable(int &a, int &b)" << endl;
}

template<typename T> // 泛型
void swapVariable(T &a, T &b) {
    T t;
    t = a;
    a = b;
    b = t;
    cout << "swapVariable(T &a, T &b)" << endl;
}

int x = 1, y = 2;
float a = 2.0, b = 3.0;
double a1 = 2.01, b1 = 3.01;
size_t a2 = 7, b2 = 8;
swapVariable(x, y); //自动数据类型 推导的方式 隐式调用 swapVariable(int &a, int &b)
swapVariable(a, b); //自动数据类型 推导的方式 隐式调用
swapVariable(a2, b2); //自动数据类型 推导的方式 隐式调用

swapVariable<float>(a, b); //显示类型调用
swapVariable<double>(a1, b1); //显示类型调用 swapVariable(T &a, T &b)
```

### **函数模板和普通函数区别：** 

函数模板不允许自动类型转化

普通函数能够进行自动类型转换

### **函数模板和普通函数在一起，调用规则：** 

1.  函数模板可以像普通函数一样被重载
2. C++编译器优先考虑普通函数
3. 如果函数模板可以产生一个更好的匹配，那么选择模板
4. 可以通过空模板实参列表的语法限定编译器只通过模板匹配



## 尾置返回类型和类型转化

## 模板实参推断和引用

- 从左值引用函数参数推断类型

    当一个函数参数式模板参数的一个普通（左值）引用时（T&），只能给它传递一个左值（一个变量或一个返回引用类型表达式），实参可以是const类型的，也可以不是。如果是const的，则T可以被推断为const类型

    ```c++
    template<typename T> void f1(T&) // 必须是一个左值
    f1(i); // int
    f1(ci); //const int
    f1(5); //error 必须为左值
    template<typename T> void f2(const T&) // 可以是一个右值
    f1(i); // int
    f1(ci); //const int
    f1(5); //const & 可以绑定到右值
    ```

- 从右值引用函数参数推断类型

    当一个函数参数是一个右值引用（T&&），正常的绑定规则告诉我们可以传递一个右值

    ```c++
    template<typename T> void f3(T&&)
    f3(42);
    ```

# 重载与模板

```c++
namespace text {
    template <typename T> void f(T)
    {
        std::cout << "f(T)\n";
    }

    template <typename T> void f(const T*)
    {
        std::cout << "f(const T*)\n";
    }
    template <typename T> void g(T)
    {
        std::cout << "template <typename T> void g(T)\n";
    }
    template <typename T> void g(T*)
    {
        std::cout << "template <typename T> void g(T*)\n";
    }
}

void text3()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    text::g(42);    //template <typename T> void g(T ); --is called
    text::g(p);     //template <typename T> void g(T*); --is called
    text::g(ci);    //template <typename T> void g(T)   --is called
    text::g(p2);    //template <typename T> void g(T*)  --is called
    text::f(42);    //f(T)
    text::f(p);     //f(T)
    text::f(ci);    //f(T)
    text::f(p2);    //f(const T*)
}
```

