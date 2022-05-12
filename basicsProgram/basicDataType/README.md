# 数据类型

数据类型：固定内存大小的别名，编译器在编译阶段确定分配内存空间的大小；

| char           | 1 字节      | -128 到 127 或 0 到 255                              |
| -------------- | ----------- | ---------------------------------------------------- |
| unsigned char  | 1 字节      | 0 到 255                                             |
| signed char    | 1 字节      | -128 到 127                                          |
| int            | 2 或 4 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647 |
| unsigned int   | 2 或 4 字节 | 0 到 65,535 或 0 到 4,294,967,295                    |
| short          | 2 字节      | -32,768 到 32,767                                    |
| unsigned short | 2 字节      | 0 到 65,535                                          |
| long           | 4 字节      | -2,147,483,648 到 2,147,483,647                      |
| unsigned long  | 4 字节      | 0 到 4,294,967,295                                   |
| loat           | 4 字节      | 1.2E-38 到 3.4E+38                                   |
| double         | 8 字节      | 2.3E-308 到 1.7E+308                                 |
| long double    | 16 字节     | 3.4E-4932 到 1.1E+4932                               |

# 字面值常量

```c++
20;// 十进制
024;//八进制
0x14, 0X14;//16进制
3.1415926; //浮点型
'a'; //字符字面值
"hello world!!!";//字符串字面值
// 转义字符
\t/*横向制表符*/,\v/*纵向制表符*/,\f/*换页符*/;
\n/*换行符*/,\b/*退格符*/,\r/*回车符*/;
\a/*报警符*/,\?/*问号*/;
\\/*反斜线*/,\'/*单引号*/,\"/*双引号*/;
    
L'a'; // 宽字符型字面值，类型是wcahr_t
u8"hi"; // utf-8字符串
42ULL; // 无符号整型字面值 unsigned long long
1E-3F; // 单精度浮点型字面值 float
3.1415926L; //扩展精度浮点型字面值 long double
//前缀
u  Unicode 16字符   char16_t
U  Unicode 32字符   char32_t
L  宽字符			 wchar_t
u8  UTF-8			char
//后缀
u or U  	unsigned 
l or L  	long 
ll or LL  	long long     
f or F  	float 
ld or LD  	long double     
```

# 变量

提供一个具名、可供程序操作的存储空间；c++每个变量都有数据类型，数据类型决定着变量所占的内存空间的大小和布局、该空间能存储的值的范围，以及变量参与的运算；

# 对象

指一块存储数据并且具有某种类型的内存空间；

# 初始化和赋值

初始化不是赋值，初始化时创建变量并且赋予一个初始值，而赋值是把对象的当前值擦除，并且用一个新值来替换；

```c++
//列表初始化
int a1 = 0;
int a2 = {0};
int a3 {0};
int a4(0);

long double ld = 3.14;
//int b{ld}, c = {ld}; // error 转置未执行
int d(ld), f = ld; // 转置执行 丢失部分值

//默认初始化
string str; // 非显式初始化为一个空串
obj obj1; // 被默认初始化

// 定义于函数体内的内置类型的对象如果没有被初始阿化，则其值未定义；
// 类的对象如果没有显示初始化，则其值有类确认；
```



# 定义和声明

定义：（编译器）创建一个对象，为这个对象分配一块内存，并给它取上一个名字，这个名字就是就是我们经常所说的变量名或对象名。（对于变量，编译器确定变量的大小，然后在内存中开辟空间来保存其数据；对于函数，编译器会生成代码，这些代码最终也要占用一定的内存）；

声明：声明是仅仅告诉编译器，这个名字（标识符）已经匹配到一块内存上以及“这个函数或变量在某处可找到，它长得什么样子”。

变量的声明

定义性声明（defining declaration）是需要建立存储空间的。例如：int a在声明的时候就已经建立了存储空间。

引用性声明（referncing declaration）是不需要建立存储空间的。例如：extern int a其中变量a是在别的文件中定义的。   

从广义的角度来讲声明中包含着定义，但是并非所有的声明都是定义。我们常常这么描述：把建立空间的声明称之为“定义”，而把不需要建立存储空间称之为“声明”。很明显我们在这里指的声明是范围比较窄的，也就是说非定义性质的声明。



对于函数来说，函数必须在被调用之前先声明，否则无法调用。

      void sum(int a，int b);  函数的声明是一个说明语句，必须以分号结束。函数的声明是对定义函数的返回值类型说明，以通知系统在本函数中所调用的函数是什么类型。

void sum(int a，int b){}  函数的定义，整体是一个完整的函数单元 ，包含函数类型、函数名、形参及形参类型、函数体等。

```c++
int num_tries = 0;
int num_right = 1; // assignment 运算符初始化 继承c语言 如果对象属于内置类型 或者对象可以单一值初始化就没问题
int  num_tries = 0,  num_right = 1; //多个同类型的可以放在一起
int num_tries(5); // 构造函数语法（constructor syntax）
complex<double> purei(0, 7); // 多个值初始化就需要用构造函数初始化
```

# const和define

```c++
const int m_a = 0; // a不能被修改
int const b = 0; // b不能被修改

//指针指向的对象声明为const或volatile
const char *cpch; // 修饰符修饰的指针指向的对象 不能被修改
volatile char *vpch;
// 指针的值（即指针中存储的实际地址）声明为const或volatile
char *const pchc = nullptr; // 修饰符修饰的指针的值 不能被修改
char *volatile pchv;

// 在c语言中const修饰的变量，可以通过间接赋值方式被修改
const int value = 10;
int *p = const_cast<int *>(&value);
*p = 6;

const char cch = 'A'; // cch的值不能被修改
char ch = 'B';

const char *pch1 = &cch;
//char *pch2 = &cch;   // Error
//char *const pch3 = &cch;   // Error
const char *const pch4 = &cch;

//*pch1 = 'A';  // Error: object declared const
pch1 = &ch;   // OK: pointer not declared const
char *pch2 = "aaa";  // OK: normal pointer
pch2 = &ch;   // OK: normal pointer
char *const pch3 = "bbb";  // OK: object not declared const
//pch3 = &ch;   // Error: pointer declared const
//*pch4 = "cccc";  // Error: object declared const
//pch4 = &ch;   // Error: pointer declared const

const char *pch5 = &ch;
char *pch6 = &ch;
char *const pch7 = &ch;
const char *const pch8 = &ch;
```

**`const`**可以将给定类型的指针分配给同一类型的指针。 但是，不能将非 **`const`** 的指针分配给 **`const`** 指针。 以下代码显示了正确和错误的赋值：

```cpp
int *const cpObject = 0;
int *pObject;

int main() {
pObject = cpObject;
cpObject = pObject;   // C3892
}
```

以下示例显示了当有指针指向某个指向对象的指针时如何将对象声明为 const。

```c++
struct X {
   X(int i) : m_i(i) { }
   int m_i;
};

int main() {
   const X cx(10);
   const X * pcx = &cx;
   const X ** ppcx = &pcx;

   X const cx2(20);
   X const * pcx2 = &cx2;
   X const ** ppcx2 = &pcx2;
}
```

# 数组

```c++
int a1[5] = {}; // 0 0 0 0 0 
int a2[5] = {2,5,7,0}; // 2 5 7 0 0
int a3[5] = {10}; // 10 0 0 0 0
//int a4[5] = {1, 2, -1.6}; //error
```

