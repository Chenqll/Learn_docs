# 结构体的内存布局

## 指针 III

```c++
int main(int argc, char* argv[])
{
  int (__cdecl *pfn)(int nCount, ...) = myadd;
  pfn(10, 20, 30);

  int ary[10][10];
  int (*p)[10] = ary;
  printf("%p, %p, %p\n", ary, p, p+1);
  return 0;
}
```

## 内存的分区

一个程序启动后，进程中的内存是“分区管理”的。

- 栈，随着函数调用被自动分配和回收的一块区域，配合函数栈帧的一块内存
- 全局，生命周期开始早于 main，结束要晚于 main。全局变量、静态局部变量（static），函数机器码
- 堆，需要手工管理（malloc、free）

全局区的空间比较大。栈的空间比较狭隘。


## 结构体及其内存布局

结构体其实就是各种基本数据类型的组合。组合时内存布局的规律：

- 最开始的成员，出现在结构体的头部（首地址）
- 先定义的成员出现在低地址，后定义的依次出现在高地址。如果没有特殊情况，是“紧密”连接的
- 特殊情况是：“对齐”


### 对齐

```c++
#include <stdio.h>
#include <string.h>

struct tagOneFlow{
  char chValue;
  char chValue2;
  int nId1;
  double nId0;
};

int main(int argc, char* argv[])
{
  printf("%lu\r\n", sizeof(tagOneFlow));
  return 0;
}
```

对齐 trick：

```c++
struct tagOneFlow{// offset
  char chValue;  //  0
  char chValue2; //  1
  int nId1;      //  4
  double nId0;   //  8
};

struct tagOneFlow2{// offset
  char chValue;  //  0
  int nId1;      //  4
  char chValue2; //  8
  double nId0;   //  16
};

int main(int argc, char* argv[])
{
  printf("%lu\r\n", sizeof(tagOneFlow2));
  return 0;
}
```

参阅：

- `gcc __attribute__((aligned(64)))`
- http://www.catb.org/esr/structure-packing/

## 结构体指针

`->` 工作是分两步的：

- 获取结构体的首地址
- 根据首地址和成员的偏移，得到成员的内存地址
- 按照解释方式，把内存中的内容取出来


**可否设计一个宏，可以计算结构体成员的偏移？**

```c++
#define offset_tag(s, m)  ((long int)(&(((tagOneFlow*)(0))->m)))
```
