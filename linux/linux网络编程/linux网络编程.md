# 网络基础

## 分层模型

* OSI七层模型：物理层、数据 层、网络层、传输层、会话层、表示层、应用层。
* TCP/IP（4层模型）：应用层、传输层、网络层、网络接口层

 应用层：http、ftp、nfs、ssh、telnet

传输层：tcp、udp

网络层：IP、ICMP、IGMP

链路层：以太网帧协议、ARP

* 以太网帧

根据ip地址获取mac地址

mac地址：获取网卡编号

ARP请求：获取目标地址（0806   ）

* C/S模型：client-server,可以缓存大量数据， 协议选择灵活、速度快、应用程序迭代更新方便。k
* B/S模型：browser-server，不能缓存大量数据、严格遵守http、安全性较好 、跨平台、开发工作量较小

​	

## IP协议

IPv4,IPv6

TTL:time to leave.设置数据包在路由节点中的跳转上限。

源IP:32位---4字节  192.168.1.108---点分10进制（string）--二进制

目的IP：32位--4字节

## UDP协议

16位：源端口号				2^16=65536

16位：目的端口号

端口号：可以在网络的一台主机上，唯一标识一个进程

## TCP协议

16位：源端口号				2^16=65536

16位：目的端口号

32位序号：

32位确认序号：

6个标志位

16个窗口大小

### TCP通信时序（三次握手，四次挥手）

* 三次握手

大多数由客户端发起连接，

发送 SYN标志位建立连接        mms最大(1460)

​      三次握手发生在内核空间

*  数据传输

数据传输可以批量应答

* 四次挥手

半关闭

FIN信号      

* 滑动窗口

win信号显示缓存区剩余大小 

### TCP状态转换

* 主动发起连接 ：CLOSE --STN--SEND_SYN--接受ACK,SYN--发送ACK--ESTABLISH
* 主动关闭连接请求：ESTABLISHED（数据通信态） --发送FIN--FIN_WAIT_1--会接受ACK--FIN_WAIT_2(半关闭)--接收对端发送FIN--FIN_WAIT2--回发ACK--TIME_WAIT（只有主动关闭的一方等待）--等2msl时长
*  被动接受连接请求端:CLOSE--LISTEN--接受SYN--LISTEN--发送ACK、STN--SYN_RCVD--ESTABLISHED
* 被动接受关闭连接请求:ESTABLISHED--接受FIN--ESTABLISHED--发送ACK--CLOSE_WAIT（说明对端处于版关闭状态）--发送FIN--LAST_ACK--接受ACK--CLOSE

### 2msl时长：

一定出现在主动关闭请求端--

保证最后一个ACK能被对端接受。（等待期间，对端没收到我发送的）

### 端口复用

```c
// setsocketopt
```



## 通信过程

  数据没有封装之前，是不能够在网络中传输的。

# Socket编程

## 网络套接字： 在通信过程中，套接字一定是成对出现的。

一个文件描述符指向一个套接字（该套接字符借助两个缓冲区实现。）

## 网络字节序

​	小端法：高位存在高地址，地位存低地址。 int a=0x12345678

​	大端法：高位存低地址，低位存低地址。

网络使用大端法，计算机使用小端法。

```c
#include <arpa/inet.h>
//uint32_t htonl(uint32_t hostlong);
//uint16_t htons(uint16_t hostshort);
//uint32_t ntohl(uint32_t netlong);
//uint16_t ntohs(uint16_t netshort);

//大小端转换
//htonl()
//htons()
//ntohl()
//ntohs()

//IP地址转换函数 
//inet_pton
//inet_ntop


//bind()

sockaddr_in
INADDR_ANY
  
```

## 流程

在一次连接中会产生三个套接字

* 服务器端

```c
//socker()
//bind()
//listen()   //设置监听上限
//accept

//toupper()

//connect()
//如果不使用bind绑定可不短地址结构，采用“隐式绑定”

//   
```

## 多进程并发服务器

* 父子进程并发

```c
1. Socket()   创建监听套接字1fd
2. Bind()
3. Listen()
4. while(1)
{
    cfd =Accpet();    接受客户端请求
    pid=fork();		
    if(pid ==0)
    {
        close(1fd)      关闭用于建立连接的套接字
    }else if(pid>0)
    {
        close(cfd); 关闭用于与客户端通信的套接字cfd
        waitpid();
        continue;
        
    }
}
```

## 多进程并发



# 高并发服务器

