# cEssence

# point

```c++
int value= 10；
int *p = nullPtr；
p  = &value;
```

1.  p是一个指针， 存储着变量value的地址；

2.  指针p的类型必须与变量value类型一致；

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

# pointFunction and functionPoint

// Declare pointer to any function that... 

// ...accepts a string and returns a string 

string (*g)(string a); *

*// has no return value and no parameters void (*x)(); 

// ...returns an int and takes three parameters 

// of the specified types 

int (*i)(int i, string s, double d);

# smartPoint



### 可重定义的运算符

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

1 存在两个版本的一元增量和减量运算符：预递增和后递增。

有关详细信息 [，请参阅运算符重载的](https://docs.microsoft.com/zh-cn/cpp/cpp/general-rules-for-operator-overloading?view=msvc-170) 常规规则。 以下主题对各种类别的重载运算符的约束进行了介绍：

- [一元运算符](https://docs.microsoft.com/zh-cn/cpp/cpp/overloading-unary-operators?view=msvc-170)
- [二元运算符](https://docs.microsoft.com/zh-cn/cpp/cpp/binary-operators?view=msvc-170)
- [分配](https://docs.microsoft.com/zh-cn/cpp/cpp/assignment?view=msvc-170)
- [函数调用](https://docs.microsoft.com/zh-cn/cpp/cpp/function-call-cpp?view=msvc-170)
- [下标](https://docs.microsoft.com/zh-cn/cpp/cpp/subscripting?view=msvc-170)
- [类成员访问](https://docs.microsoft.com/zh-cn/cpp/cpp/member-access?view=msvc-170)
- [递增和减量](https://docs.microsoft.com/zh-cn/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170)。
- [用户定义类型转换](https://docs.microsoft.com/zh-cn/cpp/cpp/user-defined-type-conversions-cpp?view=msvc-170)

无法重载下表中显示的运算符。 该表包括预处理器符号 **#** 和 **##** 。

### 不可重定义的运算符

| 运算符   | 名称                   |
| :------- | :--------------------- |
| **.**    | 成员选择               |
| **`.*`** | 指向成员的指针选定内容 |
| **::**   | 范围解析               |
| **? :**  | 条件逻辑               |
| **#**    | 预处理器转换为字符串   |
| **##**   | 预处理器串联           |

尽管通常是在代码中遇到重载运算符时由编译器对其进行隐式调用，但也可以按照与调用任何成员或非成员函数相同的方式来显式调用重载运算符：

C++复制

```cpp
Point pt;
pt.operator+( 3 );  // Call addition operator to add 3 to pt.
```

## 示例

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



# 函数声明的各个部分

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















