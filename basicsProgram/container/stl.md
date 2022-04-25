# Container

## 容器分类

### Sequence Containers

#### [**1.array** ](https://www.cplusplus.com/reference/array/array/)

##### 特性

数组是固定大小的序列容器:它们以严格的线性序列保存特定数量的元素。
		在内部，数组除了它所包含的元素之外不保留任何数据(甚至不保留它的大小，这是一个模板参数，在编译时固定)。就存储大小而言，它与使用语言的方括号语法([])声明的普通数组一样高效。这个类只添加了一层成员和全局函数，这样数组就可以用作标准容器。

数组容器的另一个独特特性是，它们可以被视为元组对象:<array>头文件重载get函数，以访问数组的元素，就像它是元组一样，以及特定的tuple_size和tuple_element类型。

容器中的元素按严格的线性顺序排列。单个元素可以通过它们在序列中的位置来访问。

这些元素存储在连续的内存位置，允许常量时间随机访问元素。指向一个元素的指针可以进行偏移以访问其他元素。

容器使用隐式构造函数和析构函数静态地分配所需的空间。它的大小是编译时常数。没有内存或时间开销。

##### 函数

```c++
/*Member functions
    Iterators
    begin Return iterator to beginning (public member function )
    end Return iterator to end (public member function )
    rbegin Return reverse iterator to reverse beginning (public member function )
    rend Return reverse iterator to reverse end (public member function )
    cbegin Return const_iterator to beginning (public member function )
    cend Return const_iterator to end (public member function )
    crbegin Return const_reverse_iterator to reverse beginning (public member function )
    crend Return const_reverse_iterator to reverse end (public member function )
    
    Capacity
    size Return size (public member function )
    max_size Return maximum size (public member function )
    empty Test whether array is empty (public member function )
    
    Element access
    operator[] Access element (public member function )
    at Access element (public member function )
    front Access first element (public member function )
    back Access last element (public member function )
    data Get pointer to data (public member function )
Modifiers
fill Fill array with value (public member function )
swap Swap content (public member function )
Non-member function overloads
get (array) Get element (tuple interface) (function template )
relational operators (array) Relational operators for array (function template )
Non-member class specializations
tuple_element<array> Tuple element type for array (class template specialization )
tuple_size<array> Tuple size traits for array (class template specialization )*/
```



#### [**2.vector**](https://www.cplusplus.com/reference/vector/vector/)

Vector (class template )

#### [**3.deque**](https://www.cplusplus.com/reference/deque/deque/)

Double ended queue (class template )

#### [**4.forward_list** ](https://www.cplusplus.com/reference/forward_list/forward_list/)

Forward list (class template )

#### [**5.list**](https://www.cplusplus.com/reference/list/list/)

List (class template )



### Containers adaptors

#### [**1.queue**](https://www.cplusplus.com/reference/queue/queue/)

FIFO queue (class template )

#### 2.[**priority_queue**](https://www.cplusplus.com/reference/queue/priority_queue/)

Priority queue (class template )



### Associative Containers

#### [**1.set**](https://www.cplusplus.com/reference/set/set/)

Set (class template )

#### [**2.multiset**](https://www.cplusplus.com/reference/set/multiset/)

Multiple-key set (class template )

#### [**3.map**](https://www.cplusplus.com/reference/map/map/)

Map (class template )

#### [**4.multimap**](https://www.cplusplus.com/reference/map/multimap/)

Multiple-key map (class template )

### Unordered associative Containers

#### [**1.unordered_set** ](https://www.cplusplus.com/reference/unordered_set/unordered_set/)

Unordered Set (class template )

#### [**2.unordered_multiset** ](https://www.cplusplus.com/reference/unordered_set/unordered_multiset/)

Unordered Multiset (class template )

#### [**3.unordered_map** ](https://www.cplusplus.com/reference/unordered_map/unordered_map/)

Unordered Map (class template )

#### [**4.unordered_multimap** ](https://www.cplusplus.com/reference/unordered_map/unordered_multimap/)

Unordered Multimap (class template )









## 容器归类

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

## 容器图

![](D:/lyh/opengrok/source/cEssence/objectOrientedProgram/data/image/associativeContainers.png)

![sequenceContainers](D:/lyh/opengrok/source/cEssence/objectOrientedProgram/data/image/sequenceContainers.png)