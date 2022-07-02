# 基本命令

```c
ls
cd
ps
open
man
```





# 基本知识

gcc编译5步骤：预处理、编译、汇编、链接

hello.c -->hello.i-->hello.s-->hello.o-->a,out

预处理：展开宏、头文件，替换条件编译，删除注释、空行、空白。gcc -E

编译：检查语法规范。（消耗时间和系统资源最多）

gcc -S

汇编：将汇编指令翻译成机器指令。

gcc -c

链接：数据段合并，地址回填

无参数 -o 是指定生成文件的名字



-I  指定头文件所在位置

-c  只做前三步。得到二进制文件

-g 编译时添加调试文件，主要支持gdb调试

```gdb
gdb 文件名

list 列出源码
b 5 //在第5行设置断点
r  //运行程序
n  //next
```

-Wall 显示所有警告信息

-D   向当前的程序中动态注册宏定义

* 静态库

ar rcs libmylib.a file1.o 命令

制作步骤： 1、将.c文件生成.o文件

​					gcc -c add.c -o add.o

​					2、使用ar工具制作静态库

​					ar    rcs  lib库名.a   add.o

​					3、编译静态库到可执行文件中

编译器只能做隐式声明

* 动态库

​		1、将.c文件生成.o文件 (生成与位置无关的代码  -fPIC)

​					gcc -c add.c -o add.o  -fPIC

​		2、使用gcc -shared工具制作静态库

​					gcc -shared lib库名.so add.o sub.o

​		3、编译可执行程序时，指定所使用的动态库。-l:指定库名 -L:指定库路径。

​					gcc test.c -o a.out -lmymath -L./lib

​		4、运行可以执行程序		

​				链接器：    工作于链接阶段，工作做时需要 -l 和	-L

​				动态链接器： 工作于程序运行阶段，工作室需要提供动态库的目录所在位置。

​	（只生效一次）	export  LD_LIBRARY_PATH(动态链接的环境变量)=

改用户bashrc文件可以一直生效。

* makefile

```makefile
makefile是用来做项目管理的
1个规则  
			目标：依赖条件
				（一个tab缩进）命令
	ALL：指定目标
2个函数：
  变量定义用 =
		src	= $(wildcard *.c)
        找到当前文件下所有后缀为.c的文件，赋值给src
        lsls
		obj =$(patsubst %.c,%.o,$(src))
		把src变量里所有后缀为.c的文件替换成.o
		
	clean:
		-rm -rf $(obj) a.out
3个自动变量：

$@:表示规则中的目标
$<:表示规则中的第一个条件.如果将该变量可以应用在模式规则中。
$^:表示规则中的所有条件，组成一个列表，以空格隔开，如果这个列表中有重复的项则消除重复项。

#模式规则
			%.o:%.c
			   gcc -c $< -o $@
#静态模式规则
			$(obj):%.o:%.c
			gcc -c $< -o $@
#伪目标
.PHONY : clean ALL
```





# 系统编程

## 常用函数

```c
#include <sys/types.h>

//open

//write

//read

//close


```





```c
#include <dirent.h>

//opendir

//readdir

//closedir
```



```c
#include <unistd.h>

//dup

//dup2
```



* open
* close
* read
* write
* fcntl
* lseek

# 进程

进程是运行起来的程序。

### 并发

​	并发，在操作系统中，一个时间段中有多个进程处于一启动运行到运行完毕之间的状态，。但，任意时刻点上仍只有一个进程在运行。

### 单道程序设计

​	所有进程一个一个排队执行。若A阻塞，B只能等待，即使

### 多道程序设计

ps aux 查pid

进程的状态：初始态，就绪态，运行态，挂起态与终止态。

初始态为进程准备阶段

# 环境变量

# 进程控制

```c
//fork

//getpid

//getppid

//getuid

//getgid
```



## 进程共享

* 父子相同之处：全局变量、data、text、栈、环境变量、用户ID、宿主目录、进程工作方式、信号处理方式...

* 父子不同之处：1.进程ID 2.fork返回值 3.父进程id 4进程运行时间  5.闹钟（定时器）6.未决信号集。

读时共享写时复制。



## gdb

set follow-fork-mode child(parent) 命令设置gdb在fork后跟踪子(父)进程。

```c
//exec函数族:调用其他可执行文件
execl
   
execlp
```

## 孤儿进程与僵尸进程

* 孤儿进程：父进程先于子进程结束，则子进程成为孤儿进程，子进程的父进程成为init进程，称为init进程领养孤儿进程。
* 僵尸进程：子进程终止，父进程尚未回收，子进程残留资源（PCB）存放于内核中，变成僵尸进程。

僵尸进程不是用kill回收。kill是用来杀死进程，不是回收。

## wait函数与waitpid函数

父进程掉用wait函数回收子进程终止信息。

* 阻塞等待子进程退出。
* 回收子进程残留资源。
* 获取子进程结束状态（推出原因）。

# 进程间通信

* 管道（使用简单）
* 信号（开销最小）
* 共享映射区（无血缘关系）
* 本地套接字（最稳定）

## 管道

  管道是一种基本的IPC关系，内核借助环形队列机制，使用内核缓冲区实现。

1. 本质是一个伪文件（实为内核缓冲区）

2. 由两个文件描述符引用，一个表示读端，一个表示写端。
3. 规定数据从管道的写端流入管道，从读端流出管道。

* 管道的局限性：

1. 数据自己写不能自己自己读，管道中的数据不可反复读取。一旦读走，管道中不再存在。
2. 采取半双工通信方式，数据只能在单方向上流动。

```c
//pipe()函数:创建并打开通道
int pipe(int fd[2])
    参数： fd[0]:读端
    	  fd[1]:写端
    返回值 ： 成功 0
    	   失败 -1
//管道的读写行为
    读管道：
    	1.管道有数据，read返回实际读到的字节数
    	2.管道无数据，1）无写端，read返回0（类似读到文件尾）
    				2）有写端,read阻塞等待。
    写管道：
    	1.无读端，异常终止。（SIGPIPE导致的）
    	2.有读端： 1）管道已满，阻塞等待
    			 2）管道未满，返回写出的字节个数。
```

* 管道缓存区大小

```c
ulimit -a命令来查看当前系统创建管道文件对应的内核缓存区大小。
也可以使用fpathconf函数，借助函数选项来查看。
```

## FIFO

进程间通信

```c
//m
```



FIFO常称为命名管道。管道(pipe)只能进行血缘进程间的通信。FIFO可以进行非血缘进程之间的通信。

## 存储映射

存储映射使一个磁盘文件与存储空间中的一缓冲区相映射。于是当从缓冲区中取出数据，就相当于读文件中的相应字节。 与此类似，将数据存入缓冲区，则相应的字节就自动写入文件。这样，就可以在不适用read和write函数的情况下，使用地址（指针）完成I/O菜操作。

```c
//mmap


//munmap
```

mmap使用注意事项：

* 用于创建内存映射区的文件大小为0，实际指定非0大小创建映射区，出“总线错误”。
* 用于创建映射区的文件大小为0，实际指定0大小创建映射区，出“无效参数”。
* 用于创建映射区的文件读写属性为只读，映射区属性为读写，出“无效参数”。
* 创建映射区，需要read权限。mmap的读写权限，应该<=文件的open权限。  只写不行。
* 文件描述符fd，在mmap创建映射区完成即可关闭。后续访问文件，用地址访问。
* offset必须是4096的整数倍.
* 对申请的映射区内存，不能越界访问。
* munmap用于释放的地址，必须是mmap申请返回的地址。
* 映射区访问权限为“私有”MAP_PRIVATE，对内存所做的所有修改，只在内存有效，不会反应到物理磁盘上。
* 映射区访问权限为”私有“MAP_PRIVATE，只需要open文件时，有读权限，用于创建映射区即可。

mmap函数的保险调用方式

​	1.open(O_RDWR)

2. mmap(NULL,有效文件大小，PRO_READ|PROT_WRITE,MAP_SHARED,fd,0);

### 父子进程使用mmap

父进程先创建映射区。open() mmap();

指定MAP_SHARED 权限

fork()创建子进程。

一个进程读一个进程写。

### 无血缘关系进程间mmap通信

两个进程 打开同一个文件，创建映射区。

指定flags为MAP_SHARED.

一个进程写入，另外一个进程读出。

​		无血缘关系进程间通信。mmap：数据可以重复读取。

​													fifo:数据只能一次读取。

## 匿名映射

非血缘进程不能用匿名映射区进行通信。

# 信号

信号共性：简单、不能携带大量信息、满足条件才发送。

信号的特质：信号时软件层面上的”中断“。一旦信号产生，无论程序执行到什么位置，必须立即停止运行，处理信号，处理结束，再执行后续指令。所有信号的产生及处理全部都是由[内核]完成的。



## 信号产生方式

1. 按键产生

2. 系统调用产生
3. 软件条件产生
4. 硬件异常产生
5. 命令产生

信号状态：产生，未决、递达

信号处理方式：1.执行默认动作

​							2.忽略（丢弃）

​							3.捕捉（调用用户处理函数）

 Linux内核的进程控制块PCB时一个结构体，task_struct，除了包含进程id,状态，工作目录，用户id，组id,文件描述符表，还包含了信号相关的信息，主要指阻塞信号集和未决信号集。

阻塞信号集（信号屏蔽字）：将某些

未决信号集：

```c
//kill -l
1~31 常规信号
34~64 实时信号
```

## 信号四要素

1. 编号
2. 名称
3. 事件
4. 默认处理动作

man 7 signal     :查看信号

## Kill函数与kill命令

```c
//kill

```

## alarm函数

alarm():使用自然计时法

每个进程有且只有一个定时器，指定second之后发SIGALARM信号。取消定时器alarm（0），返回旧闹钟余下的时间。

实际时间=系统时间+用户时间+等待时间

setitime()：可以指定计时法

1. 自然定时
2. 虚拟空间计时:ITIMER_VIRTUAL,只计算进程占用CPU的时间。
3. 

## 信号集操作函数

```c
//sigset_t set;//自定义信号集
//sigemptyset//清空信号集
//sigfillset//全部置1
//sigaddset//将一个信号添加到信号集中 
//sigdelset//将一个信号从集合中移除
//sigismember//查看信号，判断一个信号是否集合中

//sigprocmask//设置信号屏蔽字和解除屏蔽

//sig
```

## 信号捕捉函数

```c
// signal

//sigaction
```

信号捕捉特性：

​    1.捕捉函数执行期间，信号屏蔽字由mask-->sa_mask,捕捉函数执行结束。恢复回mask

2. 捕捉函数执行期间，本信号自动被屏蔽(sa_flgs=0)
3. 捕捉函数执行期间，被屏蔽信号多次发送，解除屏蔽后只处理一次。



## SIGCHILD信号

产生条件：子进程终止时，子进程接收到SIGSTOP信号停止时，子进程处在停止态，接受到SIGCONT后唤醒时。 

## 中断系统调用

sa_flag

# 进程组与会话

 ## 建立会话

1. 调用进程不能是进程组组长，该进程编程新会话首进程
2. 该进程陈伟一个新进程组的组长
3. 需要root权限(ubantu不需要)
4. 新会话丢弃原有的控制终端，该会话没有控制终端
5. 该调用进程是组长进程，则出错返回
6. 建立新会话时，先调用fork，父进程终止，子进程调用setsid().





```c
//getsid

//setsid
```

## 守护进程

Daemon进程，是linux中的后台服务进程，通常独立于控制终端.一般不予用户名直接交互。周期性的等待某个时间发生或周期执行某一动作。

```c
// chdir
```

创建守护进程步骤：

* fork子进程，让父进程关闭
* 子进程调用setsid()创建新会话
* 通常根据需要，改变工作目录位置chdir()
* 通常根据需要，重设umask文件权限掩码
* 通常根据需要，关闭/重定向文件描述符
* 守护进程 业务逻辑。while()

# 线程

LWP：轻量级进程

进程：有PCB，有独立的进程地址空间

线程：有PCB，没有独立的地址空间

Linux下： 线程：最小的执行单位

​					进程：最小分配资源单位，可看出只有一个线程的进程。

ps -Lf 进程id



* 三级映射

* 线程共享资源：

文件描述符，每个信号的处理方式，当前工作目录，用户ID和组ID，内存地址空间

* 线程非共享资源

线程ID,处理器现场和栈指针（内核栈），独立的栈空间（用户空间栈），errno变量（全局变量），信号屏蔽字，调度优先级

线程优点:1.提高程序并发性2.开销小3.数据通信，共享数据方便

缺点：1.库函数不稳定 2.调试、编写苦难3、对信号支持不好

```c
//pthread_self

//pthread_create

//pthread_exit

//pthread_join

//pthread_detach

//pthread_cancel
```

## 线程属性

设置分离属性： 

* 线程分离

```c
//pthread_attr_t attr 创建一个线程属性结构体变量
//pthread_attr_init(&attr)
//pthread_attr_setdatachstate(&attr,PTHREAD_CREATE_DETACHED)
//pthread_create(&tid,&attr,tfn,NULL);
//pthread_attr_init(&attr)
```

## 线程使用现象

1. 主线程退出其他线程不退出，主线程应调用pthread_exit
2. 避免僵尸线程

​	pthread_join

​	pthread_detach

​	pthread_create指定分离属性

​	被join线程可能在join函数返回前就释放完自己的所有内存资源，所有不应当返回被回收线程栈中的值。

3. malloc和mmap申请的内存可以被其他线程释放

4. 应避免再多线程模型中调用fork，除非马上exec，子进程中只有调用fork的线程存在，其他线程再子进程中均pthread_exit
5. 信号的复杂语义很难和多线程共存，应避免再多线程引入信号机制

# 线程同步

线程同步：指以个线程发出某一功能调用时，再没有得到结果值钱，该调用不返回。同时其他线程为保证数据一致性，不能调用该功能。

建议锁：对公共数据进行保护。所有进程再访问公共数据前先拿到锁再访问。但，建议锁不强制。

## 互斥量（mutex）

```c
//pthread_mutex_t

//pthread_mutex_init

//pthread_mutex_lock

//pthread_mutex_unluck

//pthread_mutex_destroy 

//pthread_mutex_trylock
```

注意事项：锁的粒度越小越好。（访问数据前加锁，访问数据后立即解锁）

lock阻塞，trylock直接返回

## 读写锁

锁只有一把。以读的方式是给数据加锁。以写的方式给数据加锁

读共享，写独占

写锁优先级高

相较于互斥量而言，当读线程多时，提高效率。

```c
//pthread_rwlock_t

//pthread_rwlock_init

//pthread_rwlock_destroy

//pthread_rwlock_rdlock

//pthread_rwlock_wrlock

//pthread_rwlock_tryrdlock

//pthread_rwlock_trywrlock

//pthread_rwlock_unlock

```

* 死锁

使用锁不恰当的现象

1. 线程试图对一个锁反复lock
2. 两个线程，各自持有一把锁，请求另一把锁。

## 条件变量

条件变量本身不是锁，于与锁结合使用

```c
//pthread_cond_t

//pthread_cond_init
 
//pthread_cond_destroy

//pthread_cond_wait

//pthread_cond_timedwait

//pthread_cond_signal

//pthread_cond_broadcast

```

## 信号量semaphore

应用于线程、进程间同步

 ```c
 //sem_init
 
 //sem_destroy
 
 //sem_wait
 
 //sem_post
 
 //sem_trywait
 
 //sem_timewait
 ```

