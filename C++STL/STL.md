# 使用标准库

* 标准库是以头文件呈现

## STL六大部件

### 容器

容器前闭后开

```c++
Container<T> c;

Container<T>::iterator ite =  c.begin();
for(;ite != c.end(); ++ite)
{}
/*c++11
std::vector<double> vec;

for (auto elem :vec)
{

}

*/

```

#### 容器的结构分类

##### (Sequence Containers)顺序容器

```c++
// Array 数组
#include <array>
array<,>

// Vector 向量



//Deque  队列

 

// List  双向链表

 
// Forward-List 单向列表
```



* (Associative Containers)关联容器 

1. set/Multiset



2. Map/Multimap



* (Unordered Contaner)无须容器

1. Unordered set/Multiset
2. Uordered Map/Multimap



### 分配器

#### allocator

allocator底层是调用的malloc()

dallocator底层调用的时free()

#### alloc



### 算法

### 迭代器

### 适配器

### 仿函式



# 认识标准库



# 良好使用标准库



# 扩充标准库

