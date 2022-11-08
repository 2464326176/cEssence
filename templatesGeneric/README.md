# 泛型编程

C++提供两种模板机制：**函数模板、类模板**，使得程序（算法）可以从逻辑功能上抽象，把被处理的对象（数据）类型作为参数传递。

# 一、函数模板

函数模板(function template)：
实际上是建立一个通用函数，其函数类型和形参类型不具体指定，用一个虚拟的类型来代表。这个通用函数就称为函数模板。凡是函数体相同的函数都可以用这个模板来代替，不必定义多个函数，只需在模板中定义一次即可。在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能。

- 模板把函数或类要处理的数据类型参数化，表现为参数的多态性，称为类属。
- 模板用于表达逻辑结构相同，但具体数据元素类型不同的数据对象的通用行为。

## 1.1 函数模板机制结论

- 编译器并不是把函数模板处理成能够处理任意类的函数；
- 编译器从函数模板通过具体类型产生不同的函数；
- 编译器会对函数模板进行**两次编译；**在声明的地方对模板代码本身进行编译；在调用的地方对参数替换后的代码进行编译。

## 1.2 函数模板和普通函数

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

### 1.2.1 **函数模板和普通函数区别：**

函数模板不允许自动类型转化

普通函数能够进行自动类型转换

### 1.2.2 **函数模板和普通函数在一起，调用规则：**

1. 函数模板可以像普通函数一样被重载
2. C++编译器优先考虑普通函数
3. 如果函数模板可以产生一个更好的匹配，那么选择模板
4. 可以通过空模板实参列表的语法限定编译器只通过模板匹配

## 1.3 template和class

template和class 没有本质区别，当希望通知编译器的一个名字表示类型的时候，必须使用关键字typename，不能使用class

```c++
//实例化声明。它的定义在别处
extern template class vector<string>;
//实例化定义。编译器将为它生成代码。 
template class vector<Sales_data>;
```

## 1.4 模板编译原理

普通函数：头文件的函数声明，cpp中定义函数接口时对应的，在需要的时候link，所以不会有问题；

模板函数：头文件中的时模板类型，cpp中的时已经生成的具体的类型，这样在其他文件调用的时候取link的时候找不到具体的对应，会编译报错；在模板cpp下调用则不会报错；

# 二、模板实参推断

## 2.1 类型转换与模板类型参数

与非模板函数一样，传递给函数模板的实参被用来初始化函数的形参，编译器通常不是对实参进行类型转换，而是生成一个新的模板实例。与往常一样，顶层const无论是在实参还是在形参中都会被忽略，在其他的类型转换中，能调用应用于函数模板的包括：

- const转换： 将一个非const对象的引用或者指针传递给一个const的引用或指针形参；
- 数组或者函数指针转换：如果函数形参不是引用类型，则可以对数组或者函数类型的实参应用于正常的指针转换。一个数组实参可以转换为一个指向与首元素的指针.类似的一个函数实参可以转换为一个该函数类型的指针；

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


// 相同模板参数类型的函数形参
template <class T> int compare(const T&, const T&);
compare("hi", "world"); //error static int compare(const char (&)[3], const char (&)[3])
compare("bye", "dad"); // template<T> int compare(const T &, const T &)
long i = 42;
//compare1(i, 1024); // error 1024会被推导为int  compare1(const A &v1, const A &v2)  这里是两个相同的类型
compare2(i, 1024); // compare2(const A &v1, const B &v2)

print(cout, 42); // print(ostream &os, const T &obj)
ofstream f("output");
print(f, 10); // f 转化为ostream &

 // 不同模板参数类型的函数形参
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
// 显示调用（explicit template argument ）
template<typename T1, typename T2, typename T3> T1 print(T2, T3);
auto val3 = print<long long>(i, lng); // long long print(int long)
```

### tips：

1.1 将实参传递给带模板类型的函数形参时， 能够自动应用的类型转换只有const转化及数组或函数到指针的转换。

1.2 在模板参数推导过程中会发生什么？ 从函数参数中确定模板参数的过程称为模板参数推导。在模板参数推导期间，编译器使用调用中的参数类型来查找生成与给定调用最匹配的函数版本的模板参数。 1.3
命名模板参数推导中涉及的函数参数允许的两种类型转换。 const 转换：作为const 引用（或指针）的函数参数可以传递一个对非常量对象的引用（或指针）;
数组或函数到指针的转换：如果函数参数不是引用类型，那么普通的指针转换将应用于数组或函数类型的参数。数组参数将转换为指向其第一个元素的指针。类似地，函数参数将被转换为指向函数类型的指针;

## 2.2 尾置返回类型和类型转化

```c++
template <typename It>
It &fcn(It begin, It end) {
    return begin;
}

template <typename It>
auto fdeclType(It begin, It end)-> decltype(*begin) {
    return *begin;
}
int main() {
    vector<int> vi{1, 2, 3, 4, 5};
    vector<string> vc{"111", "222"};
    auto &i = fcn(vi.begin(), vi.end());
    auto &s = fcn(vc.begin(), vc.end());
    auto &ideclType = fdeclType(vi.begin(), vi.end());
    auto &sdeclType = fdeclType(vc.begin(), vc.end());
    cout << "i " << &i << endl;
    cout << "s " << &s << endl;
    cout << "sdeclType " << ideclType << endl;
    cout << "ideclType " << sdeclType << endl;

    return 0;
}
```

## 2.3 函数指针和实参推断

```c++
template<typename T>
int compare(const T &a, const T &b) {
    cout << "a " << a << " b: " << b << endl;
}

int (*pf1)(const int &, const int &) = compare;
int (*pf2)(const string &, const string &);

void func(int(*)(const int &a, const int &b));
void func(int(*)(const string &a, const string &b));

int main() {
    //func(compare); // 无法获知使用那个实例
    pf1(1, 2);
    pf2 = &compare;
    pf2("hello", "world!!!");
    int a = 2, b = 3;
    func(compare<int>);
    
    return 0;
}
```

## 2.4 模板实参推断和引用

```C++
template<typename T>
void f(T &P);
```

函数参数p是一个模板类型参数T的引用，编译器会应用正常的引用绑定：const时底层的，不是顶层的；

- 从左值引用函数参数推断类型

  ​ 当一个函数参数式模板参数的一个普通（左值）引用时（T&），只能给它传递一个左值（一个变量或一个返回引用类型表达式），实参可以是const类型的，也可以不是。如果是const的，则T可以被推断为const类型

    ```c++
    template<typename T> void f1(T&) // 必须是一个左值
    f1(i); // int
    f1(ci); //const int
    f1(5); //error 必须为左值
    template<typename T> void f2(const T&) // 左值或const右值
    f1(i); // int
    f1(ci); //const int
    f1(5); //const & 可以绑定到右值
    ```

- 从右值引用函数参数推断类型

  当一个函数参数是一个右值引用（T&&），正常的绑定规则告诉我们可以传递一个右值

    ```c++
    template<typename T> void f3(T&&) // 绑定到非const右值
    f3(42); // 实参是一个int类型的右值，模板参数T是int
    ```

## 2.5 引用折叠、右值引用参数、move、forward

如果一个函数参数是一个指向模板类型参数的右值引用（T &&），则它可以被绑定到一个左值；

如果实参是一个左值，则推断出的模板实参类型将是一个左值引用，则函数实参将被实例化为一个（普通）左值引用参数（T&）;

```c++
// 折叠规则，只能应用于间接创建的引用的引用，如类型别名或者模板参数
/*
X& &、 X& &&和X&& & 被折叠成类型X&
X&& 和X&& &&被折叠成X&&
 */

// 顶层const和引用丢失了
template<typename F, typename T1, typename T2>
void flip(F f, T1 t1, T2 t2) {
f(t1, t2);
}

// f(42, i); // f 改变了实参i
// flip1(f, j, 42) // 通过flip1调用f不会改变j

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 &t2) {
f(t1, t2);
}

// 如果函数参数是一个指向模板类型参数的右值引用（T &&）,它对应的实参的const属性和左值/右值属性都可以保持
// 可以接受左值引用，不可以接受右值引用参数

//  flip2(f1, a, 42); 42 无法从右值转化为左值
// std::forward可以保存const属性和 左值/右值属性
template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
//f(std::forward<T1>(t1), std::forward<T2>(t2));
f(t1, t2);
}

template<typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2) {
f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int &v2) {
cout << "v1 " << v1 << " v2: " << ++v2 << endl;
}

void f1(int &&v1, int &v2) {
cout << "v1 " << v1 << " v2: " << ++v2 << endl;
}

int main() {
int a = 5;
f(1, a); // a 的值会改变  f(int v1, int &v2)
printf("a: %d\n", a);

flip(f, 2, a); // -》flip(void(*fcn)(int, int&), int t1, int t2);
printf("a: %d\n", a); // a 不会被改变

flip1(f, 2, a); // -》flip1(void(*fcn)(int, int&), int t1, int &t2); 仅限于左值传递
printf("a: %d\n", a); // a会被改变

//flip2(f1, a, 42);//
flip3(f1, a, 42);

flip2(f, 2, a); // -》flip2(void(*fcn)(int, int&), int &&t1, int &&t2); 可以涵盖右值
// 2
printf("a: %d\n", a);

return 0;
}

int main2() {
template<typename T>
void f(T &P);
// 函数参数p是一个模板类型参数T的引用，编译器会应用正常的引用绑定：const时底层的，不是顶层的；

// 从左值引用函数参数推断类型
template<typename T> void f1(T &) // 必须是一个左值
f1(i); // int
f1(ci); //const int
f1(5); //error 必须为左值
template<typename T> void f2(const T &) // 可以是一个右值
f1(i); // int
f1(ci); //const int
f1(5); //const & 可以绑定到右值

// 从右值引用函数参数推断类型
template<typename T> void f3(T &&)
f3(42); // 实参是一个int类型的右值，模板参数T是int


return 0;
}
```

## 2.6 重载与模板

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

// always declare first:
template<typename T>
std::string debug_rep(const T &t);

template<typename T>
std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char *p);
std::string debug_rep(const char *p);
// print any type we don't otherwise.
template<typename T>
std::string debug_rep(const T &t) {
    printf("debug_rep(const T &t)\n");
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// print pointers as their pointer value, followed by the object to which the pointer points
template<typename T>
std::string debug_rep(T *p) {
    printf("debug_rep(T *p)\n");
    std::ostringstream ret;
    ret << "pointer: " << p;
    
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    
    return ret.str();
}
// non-template version
std::string debug_rep(const std::string &s) {
    printf("debug_rep(const std::string &s)\n");
    return '"' + s + '"';
}

// convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p) {
    printf("debug_rep(char *p)\n");
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    printf("debug_rep(const char *p)\n");
    return debug_rep(std::string(p));
}

void print(const string &str) {
    cout << str << endl;
}
int main() {
    int *p = new int(1024);
    int i = 42;
    char cStr[20]{"hello world!!!"};
    string str("this is one day!!!");
    
    print(debug_rep(p));
    print(debug_rep(i));
    print(debug_rep(cStr));
    print(debug_rep(str));
    
    return 0;
}
```

# 三、 可变参数模板

- 可变参数模板（variadic template）：一个接受可变数目参数的模板函数或模板类；
- 可变数目参数被称为参数包（parameter packet）;

- 模板参数包（template parameter packet）：表示零个或多个模板参数；

- 函数参数包（function parameter packet）：表示零个或多个函数参数；

```c++
// Args 表示一个模板参数包 rest是一个函数参数包
// Args 表示零个或者多个模板类型参数
// rest 表示零个或者多个函数参数
template <typename T, typename... Args>
void foo(const T &t, const Args& rest)
```

```c++
template<typename T>
std::string debug_rep(const T& t);
template<typename T>
std::string debug_rep(T* p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);


template<typename T>
std::string debug_rep(const T& t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
std::string debug_rep(T* p) {
    std::ostringstream ret;
    ret << (p ? (" " << debug_rep(p)) : "null pointer");
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

std::string debug_rep(char* p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return  debug_rep(std::string(p));
}

template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &... rest) {
    os << t << ",";
    return print(os, rest...);
}

// packet extension
template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args... rest) {
    //return print(os, debug_rep(rest...)); //error
    // print(os, debug_rep(4, 9.0f, "sss", "alan"))
    return print(os, debug_rep(rest)...);
    // print(os, debug_rep(4), debug_rep(9.0f), debug_rep("sss"), debug_rep("alan"))
}

int main() {
    errorMsg(std::cout, 4, 9.0f, "sss", "alan");
    //print(std::cout, 1, 2, 3, 4, 9.0f, "sss", "alan");
    return 0;
}
```

