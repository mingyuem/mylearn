# 用户管理

```shell
#增加用户
 sudo useradd  用户名
 sudo 
```

# 链接

```
1.通过 ip addr show 命令查看linux的网络ip信息

centos 7 的ip地址为192.168.145.129

2.windows用xshell软件通过ssh协议进行管理
```

# 常用命令

ls 列出文件夹   -a  （列出所有文件包括隐藏文件）-l（列出文件的详细信息）    文件名 （不写文件名默认当前文件）

whoami   当前用户名

hostname 显示当前机器的主机名

pwd 显示当前所来文件路径



cd命令

```

```



# 重要文件







#linux练习题

```
1.linux命令格式是什么样的
    Linux命令 	 可选参数    你要操作的对象
    #显示根目录下的文件内容
    ls  /
    #显示根目录下文件内容的详细信息，以及文件大小
    ls  -l -h  /
    #显示当前目录下的文件大小
     ls  #其实这个命令后面有一个文件夹   ls .
2. linux命令必须添加参数才能执行吗
	不是 ，参数可选
3. 解释linux的命令提示符，如何用linux命令解析
	whoami  #显示当前机器登录的用户
	hostname  #查看当前主机的名字
	hostnamectl  set-hostname  新的主机名   #更改主机名
    ~ 代表用户加目录   pwd   打印当前目录
    # 代表超级用户
    $ 代表普通用户
4.linux的目录分隔符是？
是正斜杠    /
/  在开头就是根目录，除了开头都是目录分隔符

5.简述linux的目录结构
liux的目录结构是一颗倒状的树
以   / 根目录为起点
linux类似windows中只有一个c盘

6.切换到上一级目录
.  当前工作目录
..  上一级的工作目录
-    上一次的工作目录

7.如何永久设置linux环境变量
$PATH 代表linux环境变量的名
echo $PATH  #获取PATH变量的值


PATH="新的环境变量"   #执行一次，是临时生效
#永久生效还得修改linux的全局环境变量文件 /etc/profile
PATH=“新的环境变量”


23.linux的常见配置文件目录
/etc/nginx.config  #web服务器配置文件
/etc/my.cnf       #是mysql配置文件

24.sort
```

