---
typora-root-url: ..\..\staticFile\data\image
---

# Container

6大组件，容器（Container），算法（Algorithm），迭代器（Iterator），仿函数（Function object），适配器（Adaptor）,空间配制器（allocator）；

# 一、容器分类

## 1 顺序容器（Sequence Containers）

顺序容器实现能按顺序访问的数据结构，不依赖元素的值，而是和元素加入容器的位置相对应.

- vector  可变大小，支持快速随机访问，在尾部之外插入或者删除比较慢；
- deque  双端队列 支持快速随机访问 头尾插入删除快；
- list  双向链表  支持双向顺序访问 在list任意位置插入删除速度快；
- forward_list 单向链表 单向访问   在list任意位置插入删除速度快；
- array 固定数组 支持随机访问  不能添加或者删除元素 ；
- string 与vector相似的容器  随机访问快 在尾部插入 删除速度快；

### 1.1 array

数组是固定大小的序列容器:它们以严格的线性序列保存特定数量的元素。
		在内部，数组除了它所包含的元素之外不保留任何数据(甚至不保留它的大小，这是一个模板参数，在编译时固定)。就存储大小而言，它与使用语言的方括号语法([])声明的普通数组一样高效。这个类只添加了一层成员和全局函数，这样数组就可以用作标准容器。

数组容器的另一个独特特性是，它们可以被视为元组对象:<array>头文件重载get函数，以访问数组的元素，就像它是元组一样，以及特定的tuple_size和tuple_element类型。

容器中的元素按严格的线性顺序排列。单个元素可以通过它们在序列中的位置来访问。

这些元素存储在连续的内存位置，允许常量时间随机访问元素。指向一个元素的指针可以进行偏移以访问其他元素。

容器使用隐式构造函数和析构函数静态地分配所需的空间。它的大小是编译时常数。没有内存或时间开销。

### 1.2 vector





### 1.3 deque



### 1.4 forward list



### 1.5 list



### 1.6 string





## 2 关联容器（Associative Containers）

关联容器实现能快速查找（ O(log n) 复杂度）的数据结构.

- set唯一键的集合，按照键排序；
- map键值对的集合，按照键排序，键是唯一的；
- multiset键的集合，按照键排序；
- multimap键值对的集合，按照键排序；

### 2.1 set

Set (class template )

#### 2.2 multi set

Multiple-key set (class template )

#### 2.3 map

Map (class template )

#### 2.4 multi map

Multiple-key map (class template )

## 3 无序关联容器（Unordered associative Containers）

无序关联容器提供能快速查找（均摊 O(1) ，最坏情况 O(n) 的复杂度）的无序（哈希）数据结构。

- unordered_set唯一键的集合，按照键生成散列；
- unordered_map键值对的集合，按照键生成散列，键是唯一的；
- unordered_multiset键的集合，按照键生成散列；
- unordered_multimap键值对的集合，按照键生成散列；

#### [**1.unordered_set** ](https://www.cplusplus.com/reference/unordered_set/unordered_set/)

Unordered Set (class template )

#### [**2.unordered_multiset** ](https://www.cplusplus.com/reference/unordered_set/unordered_multiset/)

Unordered Multiset (class template )

#### [**3.unordered_map** ](https://www.cplusplus.com/reference/unordered_map/unordered_map/)

Unordered Map (class template )

#### [**4.unordered_multimap** ](https://www.cplusplus.com/reference/unordered_map/unordered_multimap/)

Unordered Multimap (class template )

## 4 容器适配器

容器适配器提供顺序容器的不同接口。

- ### stack 适配一个容器以提供栈（LIFO 数据结构）
- ### queue 适配一个容器以提供队列（FIFO 数据结构）
- ### priority_queue 适配一个容器以提供优先级队列	    

## 5 容器的选择

1.一般来说尽量选择vector，除非有更好的选择；

2.如果你的程序很少的元素，且空间的额外的开销很重要，不要使用list和forward_list;

3.如果要支持随机访问，应该使用vector或者deque；

4.如果程序要求在容器的中间插入或者删除元素，应该使用list或者forward_list；

5.如果程序需要在头尾插入或者删除元素，但是不会再中间插入或者删除元素，使用deque；

6.如果程序在读取输入时才需要在容器中间位置插入元素，随后需要在随机访问元素;

​	首先确认是不是需要在容器中间位置插入元素，当处理输入数据时通常可以向vec添加数据，然后调用sort排序，避免在中间插入元素；必须在中间插入元素，先使用list，在使用vectorcopy一次；



### 2、容器适配器（Containers adaptors）

#### 1.queue （FIFO queue）



#### 2. priority_queue

```c++
template <class T, class Container = vector<T>,
class Compare = less<typename Container::value_type> > class priority_queue;
```


优先级队列是一种容器适配器，根据一些严格的弱排序标准，专门设计为其第一个元素始终是其包含的最大元素。此上下文类似于**堆**，其中可以随时插入元素，并且只能检索最大堆元素（优先级队列中位于顶部的元素）。

优先级队列被实现为容器适配器，它们是使用特定容器类的封装对象作为其底层容器的类，提供一组特定的成员函数来访问其元素。元素从特定容器的“后部”弹出，称为优先级队列的顶部。

底层容器可以是任何标准容器类模板或其他一些专门设计的容器类。容器应可通过随机访问迭代器访问，并支持以下操作：

标准容器类 vector 和 deque 满足这些要求。默认情况下，如果没有为特定的 priority_queue 类实例指定容器类，则使用标准容器向量。

需要支持随机访问迭代器以始终在内部保持堆结构。这是由容器适配器通过在需要时自动调用算法函数 make_heap、push_heap 和 pop_heap 自动完成的。

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

## 容器归纳图

![](associativeContainers.png)

![sequenceContainers](sequenceContainers.png)