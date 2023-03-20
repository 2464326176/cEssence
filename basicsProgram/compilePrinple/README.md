

# 1、**c++**

c++ 在c的基础上，融合了三种不同的编程方式：c语言过程化、c++面向对象、c++模板的泛型；

- **泛型编程**和**面向对象**的目标是相同的，使重用的代码和抽象通用的概念的技术更简单；
- **面向对象**强调的是编程的数据方面；
- 而**泛型编程**强调的是独立于特定数据类型；

## 1.1 c++关键字

```c++
//c++ keyword
const_cast      static_cast     dynamic_cast    reinterpret_cast
thread_local    new             delete          nullptr
try             throw           catch           static_assert   noexcept    asm
template        typedef         typename        typeid          export
alignof         alignas
static          extern          register        mutable         volatile
const           constexpr       decltype        inline          sizeof          namespace       using
unsigned        signed          void            bool            false           true
auto            int             short           long            float           double
char            char16_t        char32_t        wchar_t
enum            union           class           struct
public          protected       private
this            virtual         operator        explicit        default         friend
do              while           switch          for             case            break
return          else            if              continue        goto

//c++ operator signed
and         bitand      compl    not_eq     or_eq       xor_eq
and_eq      bitor       not      or         xor
```

## 1.2 数据类型

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

## 1.3 预处理



# 3. 常量变量

## 3.1 常量

****一旦初始化后不能修改的对象；

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

## 3.2 变量

变量：能读又能写的内存对象，提供一个具名、可供程序操作的存储空间；c++每个变量都有数据类型，数据类型决定着变量所占的内存空间的大小和布局、该空间能存储的值的范围，以及变量参与的运算；

变量三要素：名称、大小、作用域；

## 3.3 对象

指一块存储数据并且具有某种类型的内存空间，对象是一种特殊的变量；

## 3.4 初始化和赋值

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

## 3.5 定义和声明

为了允许把程序拆分为多个逻辑部分来编写，c++语言支持分离式编译（separate compilation）机制，该机制允许将程序分割为若干文件，每个文件可以独立编译；

如果将程序分为多个文件，则需要在文件中共享代码的方法；一个文件的代码可能需要另外一个文件中定义的变量，std::cout他们定义于标准库，可以被我们使用；

为了支持分离式编译，c++语言将声明和定义分开，声明使得名字为程序所知，一个文件如果想使用从别的地方定义的名字则必须包含那个名字的声明，而定义负责创建与名字关联的实体；

## 3.6 对于变量：

对于变量而言，主要是不需要分配内存空间的（extern int a;), 定义性声明也成为定义；

需要分配内存空间的（int a），引用性声明也成为声明；

```c++
extern int i; // 声明i而不是定义i
int i; // 定义i而不是声明i 
extern int i = 56; // 定义
//任何包含了显示初始化的声明即成为定义，我们能给extern关键字标记的变量赋一个初始值，
//但是这样也就抵消了extern的作用，extern语句如果包含了初始值就不是声明，而是定义了；

// unit.h
int a; // 定义 整型的外部变量
	
//add.cpp
int main() {
	extern int a; // 声明 声明将已经定义的外部变量a作用域拓展到此处；
	return 0;
}
```

外部变量定义和外部变量声明是不一样的，外部变量的定义只能有一次，他的位置在所有函数之外；而在同一文件内，可以有多次对同一外部变量的声明，他的位置可以在函数之内，也可以在函数之外；系统根据外部变量的定义（而不是声明）去分配内存，对于外部变量的初始化只能在定义的时候进行，而不能在声明的时候进行；所谓的声明就是一个已经定义的外部变量，仅仅是为了拓展该变量的作用范围而作的声明；

## 3.7 对于函数：

对于函数而言，由两部分：**函数声明部分**和**函数的定义部分**；

- 函数的声明部分主要是对有关的标识符（变量、函数、结构体、共用体）等属性进行声明；
- 函数的定义部分主要是函数体的主要实现；一般而言**函数声明部分**在**函数的定义部分**前；

```c++
	//函数的声明是一个说明语句，必须以分号结束。函数的声明是对定义函数的返回值类型说明，以通知系统在本函数中所调用的函数是什么类型。一般放在头文件 
	void add(int a，int b);  

 // 函数的定义，整体是一个完整的函数单元 ，包含函数类型、函数名、形参及形参类型、函数体等。一般放在cpp文件
  	void print(int a，int b){
      	return a + b;
  	}  
```

## 3.8 生命周期

| 存储           | 持续性 | 作用域 | 链接性 | 如何声明          |
| -------------- | ------ | ------ | ------ | ----------------- |
| 自动           | 自动   | 代码块 | 无     | 在代码块          |
| 寄存器         | 子自动 | 代码块 | 无     | 在代码块 register |
| 静态，无链接   | 静态   | 代码块 | 无     | 在代码块  static  |
| 静态，内部链接 | 静态   | 文件   | 内部   | 不在任函数static  |
| 静态，外部链接 | 静态   | 文件   | 外部   | 不在任何函数      |

## 3.8 单定义规则

变量只允许被定义一次，c++提供两种声明

1.定义声明（defining declaration），简称定义，给变量分配存储空间；

2.引用声明（referencing declaration）简称声明，不给变量分配空间，因为它引用已经存在的变量；

引用声明使用关键字extern，且不进行初始化，否则声明为定义，导致分配存储空间；

## 3.9 作用域

```c++
int i = 101;
int  main() {
    int j = 0;
    printf("%d %d\n", i, j);    // 101  0(全局变量 i 101， 局部变量j 0)
    int i = 5;
    printf("%d %d\n", i, j); // 5 0(局部变量 i 5， 局部变量j 0)
    printf("%d %d\n", ::i, j); // 101   0(全局变量 i 101， 局部变量j 0)
```

# 4、c++内存分配

- **栈区**：编译器自动分配和释放， 存放函数的参数值、局部变量等，操作方式类似于栈；

- **堆区**：一般有程序员分配和释放，如程序员不释放，程序结束可能有操作系统回收，操作方式类似于链表；

- **静态区**：程序结束后由操作系统来释放；

  ​        **数据段**：存放已经初始化的全局变量和静态变量；

  ​        **bss段**：存放初始化为0和未初始化的全局变量和静态变量；

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





# 5、const和constexpr

定义一种变量，它的值不能被修改；用一个变量来表示缓冲区的大小，使用变量的好处是当我们呢觉得缓冲区的大小不在合适的时候，很容易对其进行调整；另外可以加上const，限制其被修改；

## 5.1 const 限定符、引用、初始化

```c++
// const 限定符
{
    const int bufSize = 512; // 缓冲区的大小不能被修改
    //bufSize = 64; // error 编译的时候会出错

    const int i = get_size(); // 运行时初始化
    const int j = 42; // 编译时初始化
    //const int k; // 错误 k是一个未经初始化的常量
}

//初始化
{
    int i = 42;
    const int ci = i; // 正确 i的值被copy给ci
    int j = ci; // ci的值被copy给j
    // ci的常量特性 仅仅在执行修改ci的操作时才会发挥作用，
    // 当ci去初始化j 根本无需在ci常量特性 因为只是copy的值
    // copy一个对象的值并不会去改变它，一旦拷贝完成 新的对象和原来的对象就没有啥关系
}

//默认const对象尽在当前文件有效，
{
    const int bufSize = 512; // 缓冲区的大小不能被修改
    //编译器在编译过程中把用到变量的地方全部替换成为对应的值，也就是说
    //编译器会找到代码中所有用到bufSize的地方然后512替换，
    // 默认const对象尽在当前文件有效，当多个文件出现了同名的const对象时
    // 其实等于在不同文件定义了独立的变量，如果想公用一个const变量，需要用extern修饰
    // file.h
    //extern const int bufSize1 = get_size();
    {
        // file1.h
        extern const int bufSize1; //两个文件的bufSize是同一个
    }
}

{
    // const 的引用
    //可以把c引用绑定到const对象上，就像绑定到其他的对象上一样，我们称之为对常量的引用；
    // 与普通的引用不同的是 对常量的引用不能被用作修改它绑定的对象
    const int ci = 1024;
    const int &r1 = ci;
    // r1 = 42; //错误 r1是对常量的引用
    // int &r2 = ci; // 错误 试图让一个非常量引用指向一个常量对象
}

{
    // 初始化和对const的引用
    //一般来说 引用的类型必须与其所引用对象的类型一致；
    // 但是 由两个例外：
    //在初始化常量引用时允许用任意表达式作为初始值，只要该表达式的结果能转化成引用的类型即可；
    //允许一个常量引用绑定非常量的对象、字面值，甚至是个一般表达式
    int i = 42;
    const int &r1 = i; // 允许把const int &绑定到一个普通的int对象上
    const int &r2 = 42; // 正确 r1是一个常量引用
    const int &r3 = r1 * 2; // 正确 r3是一个常量引用
    //int &r4 = r1 * 2; // error r4是一个普通的非常量引用
}

{
    //对const的引用可能引用一个并非const的对象
    // 必须认识到 常量引用对引用可参与的操作做出了限定
    // 对于引用的对象本身是不是一个常量未做出限定，因此对象也可能是个非常量，所以允许通过其他的途径去改变他的值
    int i = 42;
    int &r1 = i; // 引用ri绑定对象i
    const int &r2 = i; // r2也绑定对象i，但是不允许通过r2去修改i的值
    r1 = 0; // r1并非常量
    //r2 = 0; //error r2是一个常量引用
}
```

## 5.2 顶层const和底层const

- 顶层const （top-level const）表示指针本身是一个常量；
- 底层const （low-level const）表示所指向的对象是一个常量；

```c++
{
    int i = 0;
    int *const p1 = &i; // 不能改p1的值 这是一个顶层const
    const int ci = 42; // 不能改ci的值 这是一个顶层const
    const int *p2 = &ci; // 允许改变p2的值 这是一个底层的const
    const int *const p3 = p2; // 靠右边的const 顶层const， 靠左边的const 是底层const
    const int &r = ci; // 用于声明引用的const都是底层const

    //当执行对象的copy操作，常量是顶层const还是底层的const区别明显 顶层的const不受什么影响
    // 执行拷贝的操作并不会改变拷贝对象的值 因此拷贝前后的对象是否是常量不受什么影响
    i = ci; // 正确 拷贝ci的值 ci是一个顶层的const
    p2 = p3; // 正确 p2 p3 指向对象的类型相同 p3顶层的const的部分不受影响
    

    // 另一方面 底层的const限制不可以忽略，当执行对象的拷贝操作时，拷贝前后的对象必须具有相同的底层const
    // 或者说两个对象的数据类型必须能够转化，一般来说 非常量可以换成常量 反之不行
    //int *p = p3; // error p3由底层的const p没有
    p2 = p3; // 正确 p2和p3都是底层的const
    p2 = &i; // 正确 int* 可以转化为const int*
    //int &r = ci; // 错误 普通的int & 不可以绑定到int常量上
    const int &r2 = i; // 正确 const int& 可以绑定到一个普通的int上
}
```

## 5.3 const指针

-
指针是对象，而引用不是，因此就像其他的对象类型一样，允许把指针本身定位常量；
- 常量指针必须初始化，而且一旦初始化完成，他的值也急速hi存放在指针中的那个地址就不能改变；
- 把*放在const关键字之前可以说明指针是一个常量，不变的是指针本身的值而不是指向的那个值；

```c++
{
    int errNumb = 0;
    int *const curErr = &errNumb; // curErr将一直指向errNumb 不能在被改
    const double pi = 3.141596; //
    const double *const pip = &pi; // pip 是一个指向常量对象的常量指针
    //*pip = 2.72; // error pip是一个指向常量的指针
    if(*curErr) {
        // errorHandler();
        *curErr = 0;
    }
}

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

**`const`**可以将给定类型的指针分配给同一类型的指针。 但是，不能将非 **`const`** 的指针分配给 **`const`** 指针。 以下代码显示了正确和错误的赋值：

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
   const X *pcx = &cx;
   const X **ppcx = &pcx;

   X const cx2(20);
   X const *pcx2 = &cx2;
   X const **ppcx2 = &pcx2;
}
```

# 6、typedef，auto，decltype

类型别名（type alias）某种类型的同义词，易于理解；

```c++
{
    // c 语言传统方法
    typedef double wages; // wages 是double的别名 同义词
    typedef wages base, *p; // base是 double的别名 *p是double *别名

    // c++新的方法
    using db = double; // db 是double的别名

    wages wages1 = 3145.5;
    db wages2 = 6589.9;
    printf("%f %f ", wages1, wages2);
}

{
    //指针 常量 类型别名
    typedef char *pString; // pString 是char *别名
    const pString cstr = 0; // cstrr是指向char *的常量指针
    const pString *ps; // ps是一个常量指针 它的对象是指向char的常量指针
}
```

## 6.1 auto类型说明符

```c++
{
    int m = 6;
    double n = 3.15;
    auto item1 = m + n; //乱码
    auto item2 = n + m;
    printf("%d %f ", item1, item2);
    auto i = 0, *p = &i; // i是整数 p是整型指针
    // auto sz = 0, pi = 3.145; // 错误 sz和pi 类型不一致
}

{
    int i = 0, &r = i;
    auto a = r; // a是一个整数 r是i的别名 而i是一个整数

    // auto会忽略顶层const 底层const会保留下来
    const int ci = i, &cr = ci;
    auto b = ci; // b是一个整数 （ci的顶层const特性被忽略了）
    auto c = cr; // c是一个整数（cr是ci的别名 ci本身就是一个顶层const）
    auto d = &i; // d是一个整型指针 （整数的地址就是指向整数的指针）
    auto e = &ci; // e是一个指向整数常量的指针（对常量对象取地址是一种底层的const）

    //如果希望推断出来的auto类型是一个顶层的const
    const auto f = ci; // ci是int f是const int

    //将引用类型设未auto
    auto &g = ci; // g是一个整型常量引用 绑定到ci
    //auto &h = 42; // error 不能为非常量引用绑定字面值
    const auto &j = 42; // 可以为常量引用绑定字面值


    auto k = ci, &l = i; // k是整数 l是整型引用
    auto &m = ci, *p = &ci; // m是对整型常量的引用 p是指向整型常量的指针
    //auto &n = i, *p2 = &ci; // error i的类型是int ci的类型是const int
}
```

## decltype类型说明符

从表达式类型推断出来定义的变量的类型，但是不想用该表达式的值的初始值变量，decltype选择并且返回操作数的数据类型，编译器分析表达式并且得到他的类型，不去计算表达式的值；

```c++
decltype(f())  print = x; // sum的类型就是函数f的返回类型
// 编译器并不实际调用f，而是使用当调用发生时f的返回类型作为sum的类型

//decltype 处理顶层const和引用的方式和auto有些不一样 如果decltype使用的表达式时一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）；
const int ci = 0, &cj = ci;
decltype(ci)  x = 0; // x的类型时const int
decltype(cj)  y = x; // y的类型时const int &，y绑定到变量x
//decltype(cj)  z; //error z是一个引用 必须初始化
```

## decltype 和引用

如果decltype使用的是表达式不是一个变量，则decltype返回表达式结果对应的类型；有些表达式将向decltype返回一个引用类型，一般当这种情况发生时，意味着该表达式的结果能作为一条赋值语句的左值；

```c++
int i = 42, *p = &i, &r = i;
decltype(r + 0) b; // 正确 加法是int
decltype(*p) c; //error c是int & 必须初始化
```

## decltype和auto

decltype的结果类型与表达式密切相关，对于decltype所用的表达式来说，如果变量名加上了一堆括号，则得到的类型与不加括号会不一样；如果decltype使用的是一个不加括号的变量，则得到的结果就是该变量的类型；如果给变量加了一层或者多层括号，编译器会把它当作一个表达式，变量是一种可以作为赋值语句左值的特殊的表达式，所以这样的decltype就会得到引用类型；

```
//decltype((i)) d; // error d是一个int &，必须初始化
decltype(i)	e; //正确 e是一个（未初始化的）int
```

decltype((variable))的结果永远是引用，而decltype(variable) 结果只有当variable本身是一个引用的时候才是引用；

# 7、函数话题

## 7.1 函数

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

## 7.2  实参和形参

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

## 7.3  局部对象

在c++中，名字有作用域，对象有声明周期（lifetime）；

- 名字的作用域是程序文本的一部分，名字在其中可见；
- 对象的生命周期是程序执行过程中该对象存在的一段时间；

## 7.4 自动对象

只存在与执行期间的对象成为自动对象（automatic object），当块的执行结束后，快中创建的自动对象的值就变成未定义的了；

形参是一种自动对象，函数开始为形参盛情存储空间，因为形参定义在函数体作用域之外，所以一旦函数终止，形参会被销毁；

用传递给函数的实参初始化形参对象的自动对象；对于局部变量对应的自动对象来说，变量定义含有初始值，就用这个初始值进行初始化；否则执行默认初始化；

## 7.5  局部静态对象

local static object：在程序的执行路径第一次经过对象定义语句时初始化，直到程序结束销毁；如果静态局部变量没有显示初始化，他将被执行值初始化，内置类型的局部变量初始化为0；

## 7.6  形参、局部变量、局部静态变量

**local variable**: 在块内定义的变量；

**parameter**: 在函数参数列表中声明的局部变量

**local static variable**: 在第一次执行通过对象的定义之前初始化局部静态变量（对象）。函数结束时不会破坏局部静态；当程序终止时，它们将被销毁。

## 7.7  分离式编程参数传递



形参的类型决定了形参和实参交互的方式，如果形参是引用类型，它将绑定到对应的实参上；否则，将实参的值copy后赋值给形参；

当形参是引用类型时，对应的实参被引用传递（passed by reference）或者被引用调用（called by reference）；引用形参是它绑定的对象的别名；也就是说引用形参就是它对应的实参的别名；

当实参的值被copy赋值给形参，实参和形参是两个相互对立的对象；这样的实参被值传递（passed by value）或者函数被传值调用（called by value）；

## 7.8 指针形参

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

## 7.9 函数返回类型

return；

return expresssion；

返回一个值方式和初始化一个变量或者形参的方式完全一样；返回的值用于初始化调用点的一个临时值，该临时值就是函数调用的结果；函数返回值返回的是变量的引用，并不会真正的copy数据；函数完成后所占的存储空间会被释放掉，函数结束意味着局部变量的引用将指向不在有效的内存区域；

## 7.10 函数匹配

1.函数匹配第一步先选定本次调用对应的重载函数集，集合中的函数称为候选函数（candidate  function ），候选函数（与调用的函数同名， 声明在调用点可见）；

2.第二步本次调用提供的实参，然后从候选函数中选出能被这组实参调用的函数，这些新选出的函数为可行函数（viable function），可行函数（形参的数量和本次调用提供的实参数量相同，每个实参的类型和对应的形参类型相同，或者能转成形参的类型）；

3.第三步是从可行函数中选择与本次调用的最匹配的函数，在这一过程中，注意检查函数调用提供的实参，寻找形参类型与实参类型最匹配的那个可行的函数；

# 8、IO

![](../../../../staticFile/data/image/io.png)

iostream  处理完成控制台的IO

fstream 处理命名文件的IO

stringstream完成内存string的IO

```c++
ifstream in(ifile); // 调用ifstream的构造函数并打开给定文件  调用open
				    // 对象的作用域结束会调用析构函数 调用close 
ofstream out; // 输出文件流
```

## 文件的模式：

in 	   		以读的方式打开

out 			以写的方式打开 

app			每次写操作前均定位到文件末尾 

ate			  打开文件后立即定位到文件末尾 all

trunc	      截断文件 

binary	     以二进制方式进行io all

只有针对 ofstream和fstream才可以设置out模式；

只有针对 ifstream和fstream才可以设置in模式；

只有当out也被设定时才可以设定trunc模式；

只要trunc没被设定 就可以设定app，在app模式下即便没有显示指定out模式，文件也总是以输出方式被打开；

默认情况下，即便我们没有指定trunc，以out模式打开的文件也总会被截断，为了保护以out模式打开的文件的内容，我们必须同时指定app模式，这样只会把数据追加到文件末尾；

```c++
// 以out模式打开文件会丢弃已有数据
ofstream out("file1"); // 隐式以输出模式打开文件并截断文件
ofstream out1("file1", ofstream::out); // 隐式截断文件
ofstream out2("file2", ofstream::out | ofstream::trunc); // 显示
// 为了保留文件内容，我们必须用显示指定app模式
ofstream out2("file2", ofstream::app); // 显示
ofstream out2("file2", ofstream::out | ofstream::app); // 显示

// 每次调用open时都会确认文件模式
ofstream out；
out.open("1.txt"); // 隐式输出和截断模式
out.close(); // 关闭out模式
out.open("3.txt"， ofstream::app); // 输出和追加
```









































































































