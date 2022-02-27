



# cEssence

# 编译过程



<img src="C:\Users\24643\Pictures\c++编译过程.png" alt="c++编译过程" style="zoom:50%;" />





# c++内存分配

- 栈区：编译器自动分配和释放， 存放函数的参数值、局部变量等，操作方式类似于栈；

- 堆区：一般有程序员分配和释放，如程序员不释放，程序结束可能有操作系统回收，操作方式类似于链表；

- 静态区：程序结束后由操作系统来释放；

  ​		数据段：存放已经初始化的全局变量和静态变量；

  ​		bss段：存放初始化为0和未初始化的全局变量和静态变量；

- 常量段：常量字符串，程序结束后由操作系统来释放；

- 程序代码区：存放函数体的二进制代码；

```c++
int g_i1 = 1, g_i2 = 0, g_i3;
static int g_si1 = 1, g_si2 = 0, g_si3;

int main() {
    static int s_i1 = 1, s_i2 = 0, s_i3;
    int i1 = 1, i2 = 0/*, i3 = 5*/;
    char cStr[20] = "word";
    char cStr1[10] = "word";
    char cStr2[10];
    float f = 0.0;
    float f1;
    char cStr3[10] = "word";
    char cStr4[10];
    char*p;
    char*q = "hello world!";
    p = (char *)malloc(64);
    strncpy(p, "hello world!", sizeof(p));

    /* stack area */
    printf("stack addr start:                       \n");
    printf("local intern init i1:                   %p, %d\n", &i1, &i1);
    /*printf("local intern init i2:                   %p, %d\n", &i2, &i2);
    printf("local intern not init i3:               %p, %d\n", &i3, &i3);
    printf("local intern not init i3 end:           %p, %d\n", size_t(&i3) - sizeof(i3), size_t(&i3) - sizeof(i3));
*/
    /* string area*/
    printf("string addr start:                      %p, %d\n", (size_t)cStr + sizeof(cStr), (size_t)cStr + sizeof(cStr));
    printf("cStr:                                   %p, %d\n", &cStr, &cStr);
    printf("cStr1:                                  %p, %d\n", &cStr1, &cStr1);
    printf("cStr2:                                  %p, %d\n", cStr2, cStr2);
    printf("f:                                      %p, %d\n", &f, &f);
    printf("f1:                                     %p, %d\n", &f1, &f1);
    printf("cStr3:                                  %p, %d\n", &cStr3, &cStr3);
    printf("cStr4:                                  %p, %d\n", cStr4, cStr4);
    printf("q:                                      %p, %d\n", &q, &q);
    printf("string addr end:                        \n");
    printf("stack addr end:                         \n");

    /* heap area */
    printf("heap addr start:                        \n");
    printf("heap end:                               %p, %d\n", p + 100, p + 100);
    printf("heap start:                             %p, %d\n", p, p);
    printf("heap addr end:                          \n");

    /* static area start */
    printf("static area start:                      \n");
    /* bss segment */
    printf("local intern static not init s_i3:      %p, %d\n", &s_i3, &s_i3);
    printf("local intern static init s_i2:          %p, %d\n", &s_i2, &s_i2);
    printf("global extern static not init g_si3:    %p, %d\n", &g_si3, &g_si3);
    printf("global extern static init g_si2:        %p, %d\n", &g_si2, &g_si2);
    printf("global extern not init g_i3:            %p, %d\n", &g_i3, &g_i3);
    printf("global extern init g_i2:                %p, %d\n", &g_i2, &g_i2);

    /*constant area*/
    printf("text constant area addr start:          %p, %d\n", &"hello world!", &"hello world!");

    /* data segment */
    printf("local intern static init s_i1:          %p, %d\n", &s_i1, &s_i1);
    printf("global extern static init g_si1:        %p, %d\n", &g_si1, &g_si1);
    printf("global extern init g_i1:                %p, %d\n", &g_i1, &g_i1);

    printf("static area end:                        \n");
    /* static area end */

    /* code area and */
    printf("code area start:                        \n");
    printf("code addr start:                        %p, %d\n", &main, &main);
    printf("code area and:                          \n");
    free(p);
    return 0;
}
```

# 指针

```c++
int value= 10；
int *p = nullPtr；
p  = &value;
```

1. p是一个指针， 存储着变量value的地址；

2. 指针p的类型必须与变量value类型一致；

   value: 10, value: 000000000062fe00
    p value: 10, p: 000000000062fe00

   变量value值为10， 地址为000000000062fe00

C++ 指针指向的对象声明为const或volatile

```c++
const char *cpch;
volatile char *vpch;
```

C++ 指针的值（即指针中存储的实际地址）声明为const或volatile

```cpp
char * const pchc;
char * volatile pchv;
```

C++ 语言阻止允许修改声明为 的对象或指针的分配 **`const`** 。

```cpp
const char cch = 'A';
char ch = 'B';
```

鉴于上述两个对象的声明 (类型为 `cch cch`和 的类型 `ch ch`) ，以下声明/初始化有效：

```cpp
const char *pch1 = &cch;
const char *const pch4 = &cch;
const char *pch5 = &ch;
char *pch6 = &ch;
char *const pch7 = &ch;
const char *const pch8 = &ch;
```

以下声明/初始化存在错误。

```cpp
char *pch2 = &cch;   // Error
char *const pch3 = &cch;   // Error
```

```c++
*pch1 = 'A';  // Error: object declared const
pch1 = &ch;   // OK: pointer not declared const
*pch2 = 'A';  // OK: normal pointer
pch2 = &ch;   // OK: normal pointer
*pch3 = 'A';  // OK: object not declared const
pch3 = &ch;   // Error: pointer declared const
*pch4 = 'A';  // Error: object declared const
pch4 = &ch;   // Error: pointer declared const
```

**`const`**可以将给定类型的指针分配给同一类型的指针。 但是，不能将非 **`const`** 的指针分配给 **`const`** 指针。 以下代码显示了正确和错误的赋值：

```cpp
// const_pointer.cpp
int *const cpObject = 0;
int *pObject;

int main() {
pObject = cpObject;
cpObject = pObject;   // C3892
}
```

以下示例显示了当有指针指向某个指向对象的指针时如何将对象声明为 const。

```cpp
struct X {
   X(int i) : m_i(i) { }
   int m_i;
};

int main() {
   // correct
   const X cx(10);
   const X * pcx = &cx;
   const X ** ppcx = &pcx;

   // also correct
   X const cx2(20);
   X const * pcx2 = &cx2;
   X const ** ppcx2 = &pcx2;
}
```

## 函数指针和指针函数

// Declare pointer to any function that... 

// ...accepts a string and returns a string 

string (*g)(string a); *

*// has no return value and no parameters void (*x)(); 

// ...returns an int and takes three parameters 

// of the specified types 

int (*i)(int i, string s, double d);



void (*f)()

void *f()

const int*;

int *cont

# 数组

## 一维数组

```c++
    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 7};
    int *p1 = &a1[0];
    int *p2 = a1;
	*(p1 + 1), (p2 + 1), a1[1]; // 三者等价，代表数组第二个元素，前两者为指针法，后者为下标法
```

## 二维数组

```c++
    int a2[][2]{
            {1, 2},
            {3, 4},
            {5, 6},
    };
    int (*p3)[2] = a2;  // p3指向2个整型元素的一位数组， 指向二维数组的0行
    a2[0], *(a2 + 0), *a2; // 0行0列元素地址
    a2 + 1, &a2[1]; // 1行首地址
    a2[1], *(a2 + 1); // 1行0列元素地址
    a2[1] + 2, *(a2 + 1) + 2, &a2[1][2]; // 1行2列元素地址
    *(a2[1] + 2), *(*(a2 + 1) + 2), a2[1][2]; // 1行2列元素值
```

### 二维数组作为函数形参

```c++
printfArray(a2); 	
printfArray((int *) a2);	// a2被拉伸为以为数组
printfArray((int **) a2);
printfArray1(a2);
// 编译器寻址规则， 先拿到数组p的地址，
// 在拿到寻址的行偏移量 p + i*列长度
// 再拿到寻址的列偏移量 p + i*列长度 + j
int printfArray(int array[][2]) {
    printf("%d \n", array[0][1]);
    return 0;
}

int printfArray(int **p) { // p转化为int *, 拿到步长
    printf("%d \n", *((int*)p + 2 * 0 + 0));
    printf("%d \n", *((int*)p) + 2 * 1 + 0);
    printf("%d \n", *((int*)p) + 2 * 2 + 0);
    return 0;
}

int printfArray(int *p) {
    printf("%d \n", *(p + 1));
    return 0;
}

int printfArray1(int (*p)[2]) {
    printf("%d \n", *(*(p + 0) + 1));
    return 0;
}
```

# 函数指针

在程序中定义一个函数，在编译的时候 编译系统为函数代码分配一段存储空间，被称为存储空间的起始地址（入口地址），也被称为函数的指针；

类型名 （* 指针变量名）（函数参数表列）

```c++
int (*p)(int, int); // p是一个指向函数的指针变量，它可以指向函数的类型为整型且有两个整型参数的函数
					// p 的类型用int(*)(int, int)表示， p先和*结合 指针变量 在和()结合表示一个函					// 数，该指针变量不是指向一般的变量，而是指向函数
p = max(a, b); 		// 把max函数返回值返回给p
p = max;			// 把max函数的入口地址返回给p
c = (*P)(a, b);		// 调用p指向的函数
```

# 返回指针值的函数

类型名 *函数名（参数表列）

```c++
int *a(int x, int y);  // a函数名字 调用a可以返回一个int*型（指向整型数据）的指针，得到整型数据的						//地址
```

# 指针数组和多重指针

一个数组，其元素都为指针型的数据 指针数组，也就是指针数组的每一个元素都存放的一个地址。相当于一个指针变量；

```c++
int *p[4];  // []优先级比*高  p先和[4]结合形成 p[4]形式，表示数组有4个元素，
			// 在和*结合，表示数组式指针类型的，每个数组元素（相当于一个指针变量）都可以指向一个整型			  // 变量
int (*p)[4] // 指向一维数组的指针变量
```

```c++
int main() {
    char *name[] = {"follow me", "great wall", "hello world"}; // 指针数组的元素存放的地址，不能存放值；
    char **p;
    print(name, 3);

    for (int i = 0; i < 3; ++i) {
        p = name + i;
        printf("%s \n", *p);
    }

    return 0;
}

void print(char *name[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s \n", name[i]);
    }
}
```

## 多维指针

<img src="C:\Users\24643\Pictures\指针.png"  />



# 指针和结构体

```c++
struct student *ptr;
strncpy(student.name, "hello world!", 10 * sizeof(char));
student.age = 10;
studentPtr = &student;

studentPtr->name, student.name;
(*studentPtr).age, student.age;  // (*studentPtr).age 和 studentPtr->age等价

//ptr = student.name; // error ptr是指向结构体类型的指针， 不加转化，ptr的地址类型不匹配
ptr = (struct student *)student.name;
```

## 结构体变量和结构体变量的指针作为函数参数三种方式

1.结构体的变量成员作为参数，类似于值传递；

2.结构体变量作为实参，将结构体变量所占的内存单元内存全部按顺序传递给形参，函数调用期间形参也要占用内容，会有内存开销

类似于值传递，如果在执行期间改变了形参，实参不会因此改变；

3.用指向结构体的变量的指针作为实参，将结构体的地址传给形参；

# 智能指针





# 重载运算符和重载函数

## 可重定义的运算符

| 运算符       | 名称                   | 类型   |
| :----------- | :--------------------- | :----- |
| **,**        | 逗号                   | 二进制 |
| **!**        | 逻辑非                 | 一元   |
| **!=**       | 不相等                 | 二进制 |
| **%**        | Modulus                | 二进制 |
| **%=**       | 取模赋值               | 二进制 |
| **&**        | 位与                   | 二进制 |
| **&**        | address-of             | 一元   |
| **&&**       | 逻辑与                 | 二进制 |
| **=**        | 按位“与”赋值           | 二进制 |
| **( )**      | 函数调用               | —      |
| **( )**      | 转换运算符             | 一元   |
| **`\*`**     | 乘法                   | 二进制 |
| **`\*`**     | 指针取消引用           | 一元   |
| **`\*=`**    | 乘法赋值               | 二进制 |
| **+**        | 加法                   | 二进制 |
| **+**        | 一元加                 | 一元   |
| **++**       | 递增 1                 | 一元   |
| **+=**       | 加法赋值               | 二进制 |
| **-**        | 减法                   | 二进制 |
| **-**        | 一元求反               | 一元   |
| **--**       | 减量 1                 | 一元   |
| **-=**       | 减法赋值               | 二进制 |
| **-**        | 成员选择               | 二进制 |
| **`->\*`**   | 指向成员的指针选定内容 | 二进制 |
| **/**        | 部门                   | 二进制 |
| **/=**       | 除法赋值               | 二进制 |
| **<**        | 小于                   | 二进制 |
| **<<**       | 左移                   | 二进制 |
| **=**        | 左移赋值               | 二进制 |
| **=**        | 小于或等于             | 二进制 |
| **=**        | 分配                   | 二进制 |
| **==**       | 相等                   | 二进制 |
| **>**        | 大于                   | 二进制 |
| **=**        | 大于等于               | 二进制 |
| **>>**       | 右移                   | 二进制 |
| **=**        | 右移赋值               | 二进制 |
| **[ ]**      | 数组下标               | —      |
| **^**        | 异或                   | 二进制 |
| **^=**       | 异或赋值               | 二进制 |
| **\|**       | 位或                   | 二进制 |
| **\|=**      | 按位“与或”赋值         | 二进制 |
| **\|\|**     | 逻辑或                 | 二进制 |
| **~**        | 二进制反码             | 一元   |
| **`delete`** | 删除                   | —      |
| **`new`**    | 新出现                 | —      |
| 转换运算符   | 转换运算符             | 一元   |

## 不可重定义的运算符

| 运算符   | 名称                   |
| :------- | :--------------------- |
| **.**    | 成员选择               |
| **`.*`** | 指向成员的指针选定内容 |
| **::**   | 范围解析               |
| **? :**  | 条件逻辑               |
| **#**    | 预处理器转换为字符串   |
| **##**   | 预处理器串联           |

尽管通常是在代码中遇到重载运算符时由编译器对其进行隐式调用，但也可以按照与调用任何成员或非成员函数相同的方式来显式调用重载运算符：

```cpp
Point pt;
pt.operator+( 3 );  // Call addition operator to add 3 to pt.
```



下面的示例重载 运算符 **+** 以添加两个复数并返回结果。

C++复制

```cpp
// operator_overloading.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

struct Complex {
   Complex( double r, double i ) : re(r), im(i) {}
   Complex operator+( Complex &other );
   void Display( ) {   cout << re << ", " << im << endl; }
private:
   double re, im;
};

// Operator overloaded using a member function
Complex Complex::operator+( Complex &other ) {
   return Complex( re + other.re, im + other.im );
}

int main() {
   Complex a = Complex( 1.2, 3.4 );
   Complex b = Complex( 5.6, 7.8 );
   Complex c = Complex( 0.0, 0.0 );
   c = a + b;
   c.Display();
}
```





最小函数 *声明* 包含返回类型、函数名称和参数列表 (可能为空) 以及向编译器提供其他指令的可选关键字。 以下示例是函数声明：

```cpp
int sum(int a, int b);
```

函数定义由声明和 *正文*组成，正文是大括号之间的所有代码：

```cpp
int sum(int a, int b)
{
    return a + b;
}
```

后接分号的函数声明可以出现在程序中的多个位置处。 它必须在每个翻译单元中对该函数的任何调用之前出现。 根据单个定义规则 (ODR)，函数定义必须仅在程序中出现一次。

函数声明的必需部分有：

1. 返回类型，指定函数返回的值的类型;如果未返回任何值， **`void`** 则返回类型。 在 C++11 中， 是有效的返回类型，指示编译器从 return **`auto`** 语句推断该类型。 在 C++14 中， `decltype(auto)` 也是允许的。 有关详细信息，请参阅下面的“返回类型中的类型推导”。
2. 函数名，必须以字母或下划线开头，不能包含空格。 一般而言，标准库函数名中的前导下划线指示私有成员函数，或不是供你的代码使用的非成员函数。
3. 参数列表（一组用大括号限定、逗号分隔的零个或多个参数），指定类型以及可以用于在函数体内访问值的可选局部变量名。

函数声明的可选部分有：

1. **`constexpr`**，指示函数的返回值是常量值，可以在编译时进行计算。

   C++复制

   ```cpp
   constexpr float exp(float x, int n)
   {
       return n == 0 ? 1 :
           n % 2 == 0 ? exp(x * x, n / 2) :
           exp(x * x, (n - 1) / 2) * x;
   };
   ```

2. 其链接规范或 **`extern`****`static`** 。

   C++复制

   ```cpp
   //Declare printf with C linkage.
   extern "C" int printf( const char *fmt, ... );
   ```

   有关详细信息，请参阅翻译 [单元和链接](https://docs.microsoft.com/zh-cn/cpp/cpp/program-and-linkage-cpp?view=msvc-170)。

3. **`inline`**，指示编译器将函数的每次调用替换为函数代码本身。 在某个函数快速执行并且在性能关键代码段中重复调用的情况下，内联可以帮助提高性能。

   C++复制

   ```cpp
   inline double Account::GetBalance()
   {
       return balance;
   }
   ```

   有关详细信息，请参阅 [内联函数](https://docs.microsoft.com/zh-cn/cpp/cpp/inline-functions-cpp?view=msvc-170)。

4. 一 **`noexcept`** 个表达式，指定函数是否可以引发异常。 在下面的示例中，如果表达式计算结果为 ， `is_pod` 则函数不会引发异常 **`true`** 。

   C++复制

   ```cpp
   #include <type_traits>
   
   template <typename T>
   T copy_object(T& obj) noexcept(std::is_pod<T>) {...}
   ```

   有关详细信息，请参阅 [`noexcept`](https://docs.microsoft.com/zh-cn/cpp/cpp/noexcept-cpp?view=msvc-170)。

5. (成员函数) cv 限定符，该限定符指定函数是 **`const`** 还是 **`volatile`** 。

6. (成员函数) **`virtual`****`override`** 、 或 。 **`final`** **`virtual`** 指定可以在派生类中重写函数。 **`override`** 表示派生类中的函数在重写虚函数。 **`final`** 表示函数不能在任何进一步的派生类中进行重写。 有关详细信息，请参阅 [虚拟函数](https://docs.microsoft.com/zh-cn/cpp/cpp/virtual-functions?view=msvc-170)。

7. (成员函数) 成员函数意味着该函数不与类的任何对象 **`static`** 实例相关联。

8. (非静态成员函数仅) ref 限定符，它向编译器指定当隐式对象参数 () 是左值引用与左值引用时要选择的函数重载。 `*this` 有关详细信息，请参阅 [函数重载](https://docs.microsoft.com/zh-cn/cpp/cpp/function-overloading?view=msvc-170#ref-qualifiers)。



const并不能代表“常量”，它仅仅是对变量的一个修饰，告诉编译器这个变量只能被初始化，且不能被直接修改（实际上可以通过堆栈溢出等方式修改）。而这个变量的值，可以在运行时也可以在编译时指定。

constexpr可以用来修饰变量、函数、构造函数。一旦以上任何元素被constexpr修饰，那么等于说是告诉编译器 “请大胆地将我看成编译时就能得出常量值的表达式去优化我”。

# template

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
int a[10], b[42];
fobj(a, b); // f(int*, int*)` 
fref(a, b); //error array type mismatch

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

# STL

vector  可变大小，支持快速随机访问，在尾部之外插入或者删除比较慢

deque  双端队列 支持快速随机访问 头尾插入删除快

list  双向链表  支持双向顺序访问 在list任意位置插入删除速度快

forward_list单向链表 单向访问   在list任意位置插入删除速度快

array 固定数组 支持随机访问  不能添加或者删除元素

string 与vector相似的容器  随机访问快 在尾部插入 删除速度快



#### STL中算法分类

操作对象 

直接改变容器的内容

将原容器的内容复制一份,修改其副本,然后传回该副本

功能: 

非可变序列算法 指不直接修改其所操作的容器内容的算法

计数算法     count、count_if

搜索算法     search、find、find_if、find_first_of、…

比较算法     equal、mismatch、lexicographical_compare

可变序列算法 指可以修改它们所操作的容器内容的算法

删除算法     remove、remove_if、remove_copy、…

修改算法     for_each、transform

排序算法     sort、stable_sort、partial_sort、

# **ASCII**

<img src="C:\Users\24643\AppData\Roaming\Typora\typora-user-images\image-20220226001153775.png" alt="image-20220226001153775" style="zoom: 50%;" />

![ascll](D:\lyh\opengrok\source\cEssence\c\data\image\ascll.png)

# 运算符和结合性

<img src="C:\Users\24643\AppData\Roaming\Typora\typora-user-images\image-20220226000939210.png" alt="image-20220226000939210" style="zoom: 80%;" />

# 术语表





