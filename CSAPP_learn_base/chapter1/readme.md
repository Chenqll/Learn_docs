# 1.计算机系统漫游
## 1.1 信息
- 源文件由bit（位0,1）表示，8bit=1字节，用1字节表示1字符，32位系统4字节=1字长，64位系统8字节=1字长
- 信息是由`bit和上下文信息`表示的，同样的字节序列在不同的解释方式下可以表达不同的信息
## 1.2 编译系统
- 源文件(文本文件.c)--[`预处理器`(cp,导包，修改源文件)]--->
- 源文件(被修改的源.i)---[`编译器`(ccl,修改为汇编语言)]-->
- 汇编程序(汇编文本文件.s)---[`汇编器`(as)]-->
- 机器语言指令(二进制文件.o)---[`连接器`(ld,合并调用的标准库函数的.o文件)]--->
- 可执行程序
## 1.3 硬件组成
- .c文件储存在磁盘
- io系统输入-->外壳shell接收输入-->将命令存入寄存器-->将命令存入主存-->命令结束./hello
- 磁盘将编译好的数据和code复制到主存，主存再将其复制到寄存器，寄存器再将其复制到io显示设备
- 上述过程复制过程冗余，高速缓存出现。存储器结构层次可以帮助加快执行效率--`上一层的存储器作为下一层存储器的高速缓存`。传统中，寄存器就是主存的高速缓存，寄存器容量下，所以读取速度快。新型的存储器结构是在寄存器下多了三层`L1，L2，L3`的高速缓存
- 网络可以看成一个特殊的io设备
## 1.4 操作系统
- 操作系统是软件与硬件的中间件，通过一系列软件对硬件的抽象表示，提供有效简单的管理硬件的方法。其中包括`将io设备抽象为文件，将io设备和主存抽象为虚拟存储器，将io设备、主存、处理器cpu抽象为进程`。
## 1.5 进程，并发，并行
- 一个系统可以同时运行多个进程，这是通过操作系统对多个进程指令进行`交错执行`实现的
- 虚拟存储器-为每个进程提供存储唯一的假象。包括了程序代码和数据、堆（标准函数库）、共享库、用户栈（运行时用户定义的函数）
