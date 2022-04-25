# 指针

## 指针变量归纳

```c++
int value= 10; // value: 10, &value: 000000000062fe00
int *p = nullPtr; // p是指向int类型的指针变量 空间为4个字节
p = &value; // *p: 10, p: 000000000062fe00
int m_a[10]; // a是一个数组 其中有10个元素
p = m_a; // a是一个int数组类型 p指向a的首元素
```

1. p是一个指针， 存储着变量value的地址；

2. 指针p的类型必须与变量value类型一致；int value和int *p；

3. 指针就是地址，出现指针的地方都可以用地址代替，变量的指针就是变量的地址，指针变量就是地址变量

    指针和指针变量：

    指针就是地址本身，value的地址为62fe00，62fe00就是变量的指针；

    指针变量用来存放地址的变量，指针变量的值是一个地址；

4. 指向：通过地址能找到具有该地址的对象，对于指针变量来说，把谁的地址存放在指针变量中，就说该指针指向谁；

| 变量定义     | 类型表示   | 含义                                                         |
| ------------ | ---------- | ------------------------------------------------------------ |
| int i；      | int        | 整型变量                                                     |
| int *p;      | int *      | 定义p为指向整型数据的指针变量                                |
| int m_a[10]; | int [10]   | 定义为整型数组a，有10个变量                                  |
| int *p[4];   | int *[4]   | 定义为指针数组p, 有4个指向整型数据的指针元素组成             |
| int (*P)[4]; | int (*)[4] | p指向包含4个元素的一维数组的指针变量                         |
| int f();     | int ()     | f为返回整型函数值的函数                                      |
| int *p();    | int *()    | p为返回一个指针的函数 指针指向整型数据                       |
| int  (*p)()  | int (*)()  | p为指向函数的指针  函数返回一个整数值                        |
| int **p;     | int **     | p是一个指针变量 指向一个指向整型数据的指针变量               |
| void *p;     | void *     | p是一个指针变量 该类型为void类型（空类型），不指向具体的对象 |

### 1：指针是一种数据类型   

1）指针也是一种变量，占有内存空间，用来保存内存地址

```c++
    int _int;
    char _char;
    char _str[20];
    int _intArray[20];
    char *pStr;
    int *pInt;
    int **pInt1;
    int ******pInt2;

    printf("sizeof(int))        %d\n", sizeof(int));      //sizeof(int))        4
    printf("sizeof(_int))       %d\n", sizeof(_int));     //sizeof(_int))       4
    printf("sizeof(char))       %d\n", sizeof(char));     //sizeof(char))       1
    printf("sizeof(_char))      %d\n", sizeof(_char));    //sizeof(_char))      1
    printf("sizeof(_str))       %d\n", sizeof(_str));     //sizeof(_str))       20
    printf("sizeof(_intArray))  %d\n", sizeof(_intArray));//sizeof(_intArray))  80
    printf("sizeof(char *))     %d\n", sizeof(char *));   //sizeof(char *))     8
    printf("sizeof(pStr))       %d\n", sizeof(pStr));     //sizeof(pStr))       8
    printf("sizeof(int *))      %d\n", sizeof(int *));    //sizeof(int *))      8
    printf("sizeof(pInt))       %d\n", sizeof(pInt));     //sizeof(pInt))       8
    printf("sizeof(pInt1))      %d\n", sizeof(pInt1));    //sizeof(pInt1))      8
    printf("sizeof(pInt2))      %d\n", sizeof(pInt2));    //sizeof(pInt2))      8
```

2）*p操作内存

```C++
    int m_a = 5;
    int b = 7;
    int* pInt = nullptr;
    int* pInt1 = nullptr;
    pInt = &m_a;
    pInt1 = &b;
    m_a = *pInt1; //从内存获取值
    *pInt = 8; 	// 给内存赋值

    printf("%d %d %d\n", m_a, *pInt, *pInt1); // 8 8 7
    printf("%d %d %d\n", &m_a, pInt, pInt1);  // 6422028 6422028 6422024
```

- 在指针声明时，*号表示所声明的变量为指针
- 在指针使用时，*号表示操作指针所指向的内存空间中的值
- *p相当于通过地址(p变量的值)找到一块内存, 然后操作内存
- *p放在等号的左边赋值（给内存赋值）
- *p放在等号的右边取值（从内存获取值）

3）指针变量和它指向的内存块是两个不同的概念

- 给p赋值p=0x1111; 只会改变指针变量值，不会改变所指的内容；p = p +1; //p++
- 给*p赋值* p='m_a'; 不会改变指针变量的值，只会改变所指的内存块的值 
- =左边*p 表示 给内存赋值， =右边*p 表示取值 含义不同切结！
- 保证所指的内存块能修改

4）指针是一种数据类型，是指它指向的内存空间的数据类型 

​	指针步长（p++), 根据所致内存空间的数据类型来确定

```c++
p++ = (unsigned char )p + sizeof(m_a);
```

结论：指针的步长，根据所指内存空间类型来定。

注意:  建立指针指向谁，就把把谁的地址赋值给指针。图和代码和二为一。     

​          不断的给指针变量赋值，就是不断的改变指针变量（和所指向内存空间没有任何关系）。

### 2：间接赋值是指针存在的最大意义

1）两码事：指针变量和它指向的内存块变量

2）条件反射：指针指向某个变量，就是把某个变量地址否给指针

3）*p间接赋值成立条件：3个条件 

- 2个变量（通常一个实参，一个形参）
- 建立关系，实参取地址赋给形参指针 
- *p形参去间接修改实参的值 

```c++
int iNum = 0; //实参
int *pNum = NULL;
pNum = &iNum;
iNum = 1; 	// 直接修改
*pNum =2 ; 	//通过*形参 == 间接地改变实参的值
```

**4）**引申： 函数调用时,用n指针（形参）改变n-1指针（实参）的值。

//改变0级指针（int iNum = 1）的值有2种方式

//改变1级指针（eg char *p = 0x1111 ）的值，有2种方式

//改变2级指针的（eg char **pp1 = 0x1111 ）的值，有2种方式

//函数调用时，形参传给实参，用实参取地址，传给形参，在被调用函数里面用*p，来改变实参，把运算结果传出来。

//指针作为函数参数的精髓。

### 3：理解指针必须和内存四区概念相结合 

1）主调函数 被调函数 

-  主调函数可把堆区、栈区、全局数据内存地址传给被调用函数
-  被调用函数只能返回堆区、全局数据

2）内存分配方式

- 指针做函数参数，是有输入和输出特性的。
- 指针做输出：被调用函数分配内存
    指针做输入：主调用函数 分配内存

### 4：应用指针必须和函数调用相结合

指针做函数参数，问题的实质不是指针，而是看内存块，内存块是1维、2维。

1）如果基础类int变量，不需要用指针；

2）若内存块是1维、2维。

### 5：一级指针做函数参数

```c++
// function interface
void asInput(char *input);
void asInput(char *input, int num); //一级指针做输入
void asOutput(char *input, char *output); // 一级指针做输出
```

- 主调函数还是被调用函数分配内存

- 被调用函数是在heap/stack上分配内存

### 6：二级指针做函数参数

```c++
/*内存模型*/
//1. 指针数组
char *p1[] = {"hello", "world", "!!!"};

//2. 二维数组
char p2[3][7] = {"hello", "world", "!!!"};

//3. 二维堆内存 申请
char **p3 = (char **) malloc(3 * sizeof(char *)); //int array[3];
for (int i = 0; i < 3; i++) {
    p3[i] = (char *) malloc(10 * sizeof(char)); //char buf[10]
}

// 释放内存
for (int i = 0; i < 3; i++) {
    free(p3[i]);
    p3[i] = nullptr;
}
free(p3);
p3 = nullptr;
// function interface
Int freeMemory(void **data); // 二级指针做输入 避免野指针
int main(int argc ,char *argv[]); // 二级指针做输入
int shouMatrix(int [3][4], int iLine); // 二级指针做输入
getMem(char **p1, int *len1, char **p2, int *len2) //二级指针做输出
```

- 主调函数还是被调用函数分配内存

- 被调用函数是在heap/stack上分配内存


### 7： 三级指针输出典型用法

三级指针做输出

int getFileAllLine(char ***content, int *pLine); 

int getFileAllLine_Free(char ***content, int *pLine);

- 主调函数还是被调用函数分配内存

- 被调用函数是在heap/stack上分配内存


### 8：杂项，指针用法几点扩充

1）野指针 2种free形式

int getData(char **data, int *dataLen); 

int getData_Free(void *data);

int getData_Free2(void **data);

2）2次调用

主调函数第一次调用被调用函数求长度；根据长度，分配内存，调用被调用函数。

3）返回值char */int/char **

4）C程序书写结构

商业软件，每一个出错的地方都要有日志，日志级别

### 9：一般应用禁用malloc/new



### 函数指针和指针函数

// Declare pointer to any function that... 

// ...accepts m_a string and returns m_a string 

string (*g)(string m_a); *

*// has no return value and no parameters void (*x)(); 

// ...returns an int and takes three parameters 

// of the specified types 

int (*i)(int i, string s, double d);



void (*f)()

void *f()

const int*;

int *cont

# 指针和数组

## 数组概念

- 元素类型来看：数组是相同类型的变量的有序集合；

- 内存角度：联系的一大片内存空间；

    ```c++
    int array[200] = {0}; //编译的时间 确定所有的值为0
    memset(c, 0, sizeof(c)); //显示的 重置内存块
    //C规定一维数组
    //array是数组首元素的地址 c+1 步长 4个字节
    //&array 是整个数组的地址 //&c+1 步长 200*4 
    ```

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

## 多维数组刨析

```c++
// 一维数组刨析
char m_a[10];
printfArray(m_a, num);
void printfArray(char m_a[10], size_t num);
void printfArray(char m_a[], size_t num);
void printfArray(char *m_a, size_t num);
// 一维数组作为函数的实参，传入函数a[10]，C语言在处理a[10]的时候，并不会把所有的元素copy一次
// 只会把数组的首元素的地址拿过来 m_a=>&m_a[0], 这是c语言高效的地方；

// 二维数组刨析
char m_a[3][10];
printfArray(m_a, num);
void printfArray(char m_a[3][10], size_t num);
void printfArray(char m_a[][10], size_t num);
void printfArray(char **m_a, size_t num);
// 二维数组在内存中也是线性排布的，类似于一维数组，唯一不同的地方 一维数组的a 和二维数组的a步长不一样；
// 在二维数组也存在数组退化为指针的形式
void func(char m_a[10])->void func(char m_a[])->void func(char *m_a);
void func(char char m_a[3][10])->void func(char m_a[][10])->void func(char (*m_a)[10]);
void func(char char *m_a[10])->void func(char **m_a);
```

# 数组指针

```c++
int m_a[4]; // a有4个元素， 每个元素都是整型
int m_a[4][4]; // 二维数组
int (*p)[4]; // (*p)有4个元素，每个元素都为整型，p所指的对象有4个整型元素的数组，p是指向一维数组的			  // 指针，p只能指向一个包含4个元素的一位数组，不能指向一维数组中的某一个元素；p的值就是			 // 该一维数组的起始地址
```

二维数组元素是整型的，相当于整型变量，可以用int *来指向它，二维数组的元素在内存中是线性的，按行顺序存放的，一行一行地存放元素，可以使用一个指向整型元素的指针变量，依次指向各个元素；

```c++
int m_a[][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
int *p;
for(p = m_a[0];  p < m_a[0] + 12; ++p ) {
    if((p - m_a[0])%4 == 0) {
        printf("\n");
    }
    printf("%d ", *p);
}
printf("\n");
```

# 函数指针

在程序中定义一个函数，在编译的时候 编译系统为函数代码分配一段存储空间，被称为存储空间的起始地址（入口地址），也被称为函数的指针；

类型名 （* 指针变量名）（函数参数表列）

```c++
int (*p)(int, int); // p是一个指向函数的指针变量，它可以指向函数的类型为整型且有两个整型参数的函数
					// p 的类型用int(*)(int, int)表示， p先和*结合 指针变量 在和()结合表示一个函					// 数，该指针变量不是指向一般的变量，而是指向函数
p = max(m_a, b); 		// 把max函数返回值返回给p
p = max;			// 把max函数的入口地址返回给p
c = (*P)(m_a, b);		// 调用p指向的函数
```

# 返回指针值的函数

类型名 *函数名（参数表列）

```c++
int *m_a(int x, int y);  // a函数名字 调用a可以返回一个int*型（指向整型数据）的指针，得到整型数据的地址
```



# 指针数组

一个数组，其元素都为指针型的数据 指针数组，也就是指针数组的每一个元素都存放的一个地址。相当于一个指针变量；

```c++
int *p[4];  // []优先级比*高  p先和[4]结合形成 p[4]形式，表示数组有4个元素，
			// 在和*结合，表示数组式指针类型的，每个数组元素（相当于一个指针变量）都可以指向一个整型			  // 变量
int (*p)[4] // 指向一维数组的指针变量
```

```c++
int m_a[][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
int *p;
int (*pArray)[4];

for(p = m_a[0];  p < m_a[0] + 12; ++p ) {
    if((p - m_a[0])%4 == 0) {
        printf("\n");
    }
    printf("%d ", *p);
}
printf("\n");

pArray = m_a;

for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 4; ++j) {
        printf("%d ", *(*(pArray + i) + j));
    }
    printf("\n");
}
```

# 多重指针

![](D:/lyh/opengrok/source/cEssence/cPlusPlus/data/image/%E6%8C%87%E9%92%88.png)

# 指针和结构体

## 结构体

```c++
// 1.先声明结构体类型，在定义该类型的变量
/*struct 结构体名
{
    成员列表
};*/
struct Student1 {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
}; // 最后一个分号

struct Student1 stu1, stu2;

// 2. 在声明的同时定义变量
/*struct 结构体名
{
    成员列表
} 变量名表列;*/
struct Student2 {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
} stu3, stu4;

// 3.不指定类型名直接定义结构体变量
/*struct
{
    成员列表
} 变量名表列;*/
struct {
    int num;
    char name[20];
    char sex;
    int age;
    float socre;
    char addr[30];
} stu5, stu6;

//定义了一个数据类型 。固定大小内存块的别名 还没有分配内存
typedef struct Teacher {
    char name[64];
    int age;
} Teacher1;

//初始化变量的三种方法
Teacher1 t1 = {"aaaa", 31, 01};

struct Teacher2 {
    char name[64];
    int aga;
} t2 = {"names", 21};

struct {
    char name[64];
    int aga;
} t3 = {"names", 21};
```

- 结构体类型和结构体变量是是不同的概念，只能对变量赋值、存取或者运算，而不能对一个类型赋值、存取或运算。在编译的时候，对类型是不分配内存空间的，只对变量分配空间；
- 结构体类型中的成员名字和程序中的变量名字可以相同，二者不代表同意对象；
- 对结构体变量中的成员（即域），可以单独使用，他的作用与地位相当于普通变量；

```c++
struct Student s = {.name = "lyh"}， s1; // 定义初始化，.name代表s.name，其余的数值型变量为0，字符型为'\0'，指针型为NULL;
s.age = 15; // 结构体变量名.成员名 
s.score = s1.socre; // 赋值运算
sum = s.score + s1.socre; // 加法运算
s1.age++; // 自加运算
s1 = s2; // 同类的结构体变量可以互相赋值
printf("%d ", &s1.age); // s1.age的地址
printf("%d ", &s1);	 // 结构体变量s1的首地址
```

## 结构体数组

```c++
// 1.定义结构体类型 并且初始化
/*struct 结构体名
{
    成员列表
}数组名[数组长度];*/

/*struct 结构体名
{
    成员列表
}数组名[数组长度] = {初始值};*/
// 2.先定义一个结构体类型 再去定义结构体数组
// 结构体类型 数组名[数组长度]

//对结构体数组初始化 在定义数组后面加上 = {初始值};
#define NUM 5
struct Student {
    int num;
    char name[20];
    int socre;
};

int main() {
    struct Student std[NUM] = {
            {10101, "zhang", 78},
            {10102, "wang", 56},
            {10103, "li", 34},
            {10104, "zhao", 79},
            {10105, "liu", 12},
    };
    struct Student temp;
    // bubble sort
    for(int i = NUM - 1; i > 0; --i) {
        bool flag = false;
        for(int j = 1; j <= i; ++j) {
            if(std[j].socre < std[j - 1].socre) {
                temp = std[j - 1];
                std[j - 1] = std[j];
                std[j] = temp;
                flag = true;
            }
        }
        if(!flag) {
            break;
        }
    }

    for(auto s : std) {
        printf("%d, %s, %d\n", s.num, s.name, s.socre);
    }
    return 0;
}
```

## 结构体指针

结构体指针：指向结构体变量的指针，一个结构体变量起始地址就是这个结构体变量的指针；如果把一个结构体变量的起始地址放在一个指针变量中，这个指针变量就指向该结构体变量；

```c++
struct Student {
    char name[10];
    int age;
};

int main() {

    {
        struct Student student = {"lyh", 18}, *studentPtr;
        student.age = 10;
        printf("name: %s, age: %d\n", student.name, student.age);
        studentPtr = &student;
        printf("%s %s %s\n", student.name, (*studentPtr).name, studentPtr->name); // (*studentPtr).age 和 studentPtr->age等价
    }

    struct Student std[4] = {
            {"wang", 58},
            {"liu", 45},
            {"li", 32},
            {"wen", 78},
    }, *p;
    p = std;

    for(; p < std + 4; ++p) {
        printf("name: %s, age: %d\n", p->name, p->age);
    }

    //ptr = student.name; // error ptr是指向结构体类型的指针， 不加转化，ptr的地址类型不匹配
    //ptr = (struct student *)std[1].name;
    //printf("name: %s\n", ptr);
    return 0;
}
```



## 结构体变量和结构体变量的指针作为函数参数三种方式

```c++
#define NUM 3

struct Student {
    int num;
    char name[20];
    float score[3];
    float aver;
};

void input(struct Student *stu) {
    struct Student *p = stu;
    for(; p < stu + NUM; ++p) {
        scanf("%d %s %f %f %f", &p->num, &p->name, &p->score[0], &p->score[1], &p->score[2]);
        p->aver = (p->score[0] + p->score[1] + p->score[2]) / 3.0;
    }

    /*for(int i = 0; i < NUM; ++i) {
        scanf("%d %s %f %f %f", &stu[i].num, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3.0;
    }*/
}

struct Student max(struct Student stu[]) {
    struct Student *p = stu + 1, *q = stu;

    for(; p < stu + NUM; ++p) {
        if(p->aver > q->aver) {
            q = p;
        }
    }
    return *q;
    /*int m = 0;
    for(int i = 1; i < NUM; ++i) {
        if(stu[i].aver > stu[i - 1].aver) {
            m = i;
        }
    }
    return stu[m];*/
}

void printfStruct(struct Student stu) {
    printf("%d %s %f %f %f %f", stu.num, stu.name, stu.score[0], stu.score[1], stu.score[2], stu.aver);
}

int main() {
    struct Student stu[NUM];
    input(stu);
    printfStruct(max(stu));
    return 0;
}
```

1.结构体的变量成员作为参数，类似于值传递；

2.结构体变量作为实参，将结构体变量所占的内存单元内存全部按顺序传递给形参，函数调用期间形参也要占用内容，会有内存开销

类似于值传递，如果在执行期间改变了形参，实参不会因此改变；

3.用指向结构体的变量的指针作为实参，将结构体的地址传给形参；

# 智能指针

# 指针总结