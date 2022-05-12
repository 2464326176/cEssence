# 编译原理



c++ 在c的基础上，融合了三种不同的编程方式：c语言过程化、c++面向对象、c++模板的泛型；

- **泛型编程**和**面向对象**的目标是相同的，使重用的代码和抽象通用的概念的技术更简单；
- **面向对象**强调的是编程的数据方面；
- 而**泛型编程**强调的是独立于特定数据类型；

# 数据类型

**数据类型**：固定内存大小的别名，编译器在编译阶段确定分配内存空间的大小；

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

# 常量

**常量：**一旦初始化后不能修改的对象；

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

变量：能读又能写的内存对象，提供一个具名、可供程序操作的存储空间；c++每个变量都有数据类型，数据类型决定着变量所占的内存空间的大小和布局、该空间能存储的值的范围，以及变量参与的运算；

变量三要素：名称、大小、作用域；

# 对象

指一块存储数据并且具有某种类型的内存空间，对象是一种特殊的变量；

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

## 对于变量：

对于变量而言，主要是不需要分配内存空间的（extern int a;), 定义性声明也成为定义；

需要分配内存空间的（int a），引用性声明也成为声明；

```c++
// unit.h
int a; // 定义 整型的外部变量
	
//add.cpp
int main() {
	extern int a; // 声明 声明将已经定义的外部变量a作用域拓展到此处；
	return 0;
}
```

外部变量定义和外部变量声明是不一样的，外部变量的定义只能有一次，他的位置在所有函数之外；而在同一文件内，可以有多次对同一外部变量的声明，他的位置可以在函数之内，也可以在函数之外；系统根据外部变量的定义（而不是声明）去分配内存，对于外部变量的初始化只能在定义的时候进行，而不能在声明的时候进行；所谓的声明就是一个已经定义的外部变量，仅仅是为了拓展该变量的作用范围而作的声明；

## 对于函数：

对于函数而言，由两部分：**函数声明部分**和**函数的定义部分**；

- 函数的声明部分主要是对有关的标识符（变量、函数、结构体、共用体）等属性进行声明；
- 函数的定义部分主要是函数体的主要实现；一般而言**函数声明部分**在**函数的定义部分**前；

```c++
	//函数的声明是一个说明语句，必须以分号结束。函数的声明是对定义函数的返回值类型说明，以通知系统在本函数中所调用的函数是什么类型。一般放在头文件 
	void add(int a，int b);  

 // 函数的定义，整体是一个完整的函数单元 ，包含函数类型、函数名、形参及形参类型、函数体等。一般放在cpp文件
  	void sum(int a，int b){
      	return a + b;
  	}  
```

# c++内存分配

- **栈区**：编译器自动分配和释放， 存放函数的参数值、局部变量等，操作方式类似于栈；

- **堆区**：一般有程序员分配和释放，如程序员不释放，程序结束可能有操作系统回收，操作方式类似于链表；

- **静态区**：程序结束后由操作系统来释放；

    ​		**数据段**：存放已经初始化的全局变量和静态变量；

    ​		**bss段**：存放初始化为0和未初始化的全局变量和静态变量；

- **常量段**：常量字符串，程序结束后由操作系统来释放；

- **程序代码区**：存放函数体的二进制代码；

    ![内存四区](../../staticFile/data/image/%E5%86%85%E5%AD%98%E5%9B%9B%E5%8C%BA.png)

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

# const

```c++
const int m_a = 0; // a不能被修改
int const b = 0; // b不能被修改

//指针指向的对象声明为const或volatile
const char *cpch; // 修饰符修饰的指针指向的对象 不能被修改
volatile char *vpch;
// 指针的值（即指针中存储的实际地址）声明为const或volatile
char *const pchc = nullptr; // 修饰符修饰的指针的值 不能被修改
char *volatile pchv;

// vc6.0环境下 在c语言中const修饰的变量，可以通过间接赋值方式被修改
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

**`const`**可以将给定类型的指针分配给同一类型的指针。 

但是，不能将非 **`const`** 的指针分配给 **`const`** 指针。 以下代码显示了正确和错误的赋值：

```cpp
int *const cpObject = 0;
int *pObject;

int main() {
pObject = cpObject;
cpObject = pObject;   // error C3892
}
```

当有指针指向某个指向对象的指针时如何将对象声明为 const。

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

