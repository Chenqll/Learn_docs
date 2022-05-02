# 函数调用过程、内存的分区、指针 II

## 指针相关的运算

- 指针加法
- 指针减法
- `*`
- `->`

所谓的指针加减法，其实不是数学意义上的加减。

```c++
int main(int argc, char* argv[])
{
  int nValue = 0x12345678;
  int* p1 = &nValue;
  double* p2 = (double*)&nValue;
  char* p3 = (char*)&nValue;

  printf("%p\n", &nValue);
  getchar();
  printf("%p\n", p1 + 1);
  getchar();
  printf("%p\n", p2 + 1);
  getchar();
  printf("%p\n", p3 + 1);
  getchar();
  return 0;
}
```

它是包含解释方式的，如果从纯数值公式上看，其实是这样的，如果有一个指向 `T` 类型数据的指针 `p`：

`p + i`，其中 `i` 是一个数字，那么得到的数字上的结果：

```c++
p + i * sizeof(T)
```

指针减去一个数值的运算法则，与加法类似，不再重复说明。如果有两个同类型指针相减，最后的值：

```c++
(p2 - p1)/sieof(T)
```

## 数组和指针

实际上，数值和指针有非常紧密的联系，体现：

- 数组的名字，是数组的首地址（带解释方式）
- 所谓的 `ary[i]` 实际上 `[]` 是一个 **运算符**，它的运算规则分两步：第一步，通过 **标志符 + i** 的公式，找到地址；第二步：根据解释方式，把那块地址的内容取出来。

```c++
int main(int argc, char* argv[])
{
  int nValueAry[10] = {0x12345678, 0x55667788};

  int *p = (int*) ( (long long)nValueAry + 2 );
  printf("%p, %p\n", nValueAry, p);
  getchar();
  printf("%08X\n", *p); // 34 12 88 77 
  return 0;
}
```

```c++
printf("%08X", 1[nValueAry] /* nValueAry[1]*/);
```

**数组在传参过程中，会退化为指针**：

- 变成指针了，所以更灵活（可以改变值）
- 变成指针了，丢失了信息（不知道数组的大小）

```c++
int main(int argc, char* argv[])
{
  int nValueAry[15];

  for(int i = 0; i < sizeof(nValueAry)/sizeof(nValueAry[0]); i++){
    printf("%d\n", i);
  }
  return 0;
}
```

数组退化为指针的例子：

```c++
void myfun(int* nValueAry){
  nValueAry = nValueAry + 1;
  for(int i = 0; i < sizeof(nValueAry)/sizeof(nValueAry[0]); i++){
    printf("%d\n", i);
  }
}

int main(int argc, char* argv[])
{
  int nValueAry[15];
  //nValueAry = nValueAry + 1;
  myfun(nValueAry);
  return 0;
}
```

## 函数的调用过程

函数在高级层次，帮助我们更多的复用代码。

在底层其实也是一样的，编译器只需要将函数编译一次（为机器码），之后调用函数时，都是复用的那一份函数代码。

对同一个函数做不同的调用，参数、返回值都可能不同，那到底是如何实现的呢。

我们需要了解下函数的调用过程。函数调用其实会经历以下几个步骤：

1. 传参
2. 进行流程转移（call 指令），转移的同时，会保存返回地址
3. （新函数中），申请局部变量的空间
4. 执行函数流程
5. 释放局部变量的空间
6. 从内存中取出第 2 步保存的地址，并返回到该地址

rbp 与 rsp 之间的空间，就是当前函数的 “栈帧”。
栈帧中包含了：

- 局部变量
- 参数
- 返回地址
- 上一层栈帧的 rbp
- 其它的内容（寄存器什么的）

当函数返回时，过程基本与上面所述相反，主要是释放栈帧。

## 作业

（不借助标准库的宏）实现一个可变参函数，用于计算任意多个整数的总和。







