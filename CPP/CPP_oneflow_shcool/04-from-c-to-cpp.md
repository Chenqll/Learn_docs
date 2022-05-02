# C++ 开始

## 联合体、枚举

```c++
#include <stdio.h>
#include <string.h>

union MyUnion {
  double a;
  int b;
};

int main(int argc, char* argv[])
{
  MyUnion u;
  u.a = 3.14;
  u.b = 0x12345678;
  return 0;
}
```

联合体的特点：

- 所有成员共用同一块内存（首地址都一样）
- 联合体变量的大小，是成员中最大者

联合体一般可以用来做类型转换等：

```c++
#include <stdio.h>
#include <string.h>

union MyUnion {
  double a;
  unsigned char chAry[sizeof(double)];
};

int main(int argc, char* argv[])
{
  MyUnion u;
  u.a = 3.14;
  for(int i = 0; i < sizeof(double); i++){
    printf("%02X ", u.chAry[i]);
  }
  return 0;
}
```

## 从 C 到 C++

先谈简单的一些 C 到 C++ 的细节：

- 增加了 bool 类型
- 增加了 nullptr 关键字（代替 NULL）
- 支持函数重载
- 支持块作用域中定义变量
- 支持名称空间

函数重载、名称空间其实都是利用“名称粉碎”的(name dangling)技术做的。c++filt 可以复原名称。

```c++
(oneflow-dev) yaochi@7275806cee0b:~/cmake_example/build$ c++filt _Z5myfunii
myfun(int, int)
```


## C++ 中的类

面向对象编程到底是哪个范畴的东西，对等的东西是什么？

面向对象是一种“如何做抽象”范畴的东西，属于方法论，它对等的东西：面向过程编程；Actor。

使用 C 其实也是可以面向对象的。面向对象的优点在于，把事务抽象成“对象”，而对象的三大特性：继承、封装、多态和人的直觉比较吻合，大大降低了人抽象问题的门槛。

### 封装

所谓的封装，其实就是把 “数据”和“动作”打包结合在一起。在 C 中，用函数指针，也可以做到封装：

```c++
#include <stdio.h>
#include <string.h>

struct tagFile{
  FILE * m_pFile = NULL;
  FILE* (*m_fpn_open)(const char *pathname, const char *mode)=fopen;
  size_t (*m_fpn_write)(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream) = fwrite;
  int (*m_fpn_close)(FILE *stream) = fclose;
};

int main(int argc, char* argv[])
{
  struct tagFile myfile_obj;
  myfile_obj.m_pFile =  myfile_obj.m_fpn_open("xxx.tmp", "wb");
  myfile_obj.m_fpn_write("helloworkd", 10, 1, myfile_obj.m_pFile);
  myfile_obj.m_fpn_close(myfile_obj.m_pFile);
  return 0;
}
```

C++ 在语法层次提供了“封装”，可以直接在 “类中定义方法”，并直接用 `对象.方法()` 的方式调用：

```c++
#include <stdio.h>
#include <string.h>

struct tagFile{
  FILE * m_pFile = NULL;
  FILE* open(const char* path, const char* mode){
    m_pFile = fopen(path, mode);
    return m_pFile;
  }
};

int main(int argc, char* argv[])
{
  struct tagFile myfile_obj;
  myfile_obj.open("xxxx2.tmp", "wb");

  struct tagFile myfile_obj2;
  myfile_obj2.open("xxx_two.tmp", "wb");
  return 0;
}
```

所谓对象方法的调用，其实是编译偷偷做了小动作，即

`对象.方法调用(...)` 等价于 `函数调用(&对象, ..)`。

知道这个之后，很多 C++ 的上层语法是可以联系到一起的。

比如： C++ 中的 `const 方法`，其实就是传递了一个 `const * const` 类型的 `this` 指针。

再比如：`static` 方法。

回顾下 C 中 `static` 关键字的作用：

- 修饰局部变量的话，它其实得到“局部静态变量”，局部静态变量的特点：声明周期等同于全局变量，只不过作用域被限定在了函数作用域。
- 修饰函数，就得到“局部静态函数”，它其实和普通函数是一样的，只不过限定在文件作用域

C++ 中，`static` 关键字的作用：

- 修饰方法的话，得到“静态成员方法”，等于于全局函数（换言之，调用时不会传递 this 指针），只不过被限定在了类作用域。
- 修饰类成员的话，得到了“静态成员”，等同于全局函数，只不过被限定在类作用域



