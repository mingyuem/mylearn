* Mysql启动

```
net start mysql80
net stop  mysql80
```

* Mysql客户端连接

```
Mysql自带的客户端命令行
mysql [-h 127.0.0.1] [-P 3306] -u root -p
```

mysql数据库模型

数据库 

表



# SQL

1. SQL语句可以单行或多行书写，以分号结尾。
2. SQL语句可以使用空格/缩进来增强语句的可读性
3. MySQL数据库的SQL语句不区分大小写，关键字建议使用大写。
4. 注释

*  单行注释：--注释内容或#注释内容（MYSQL特有）
*  多行注释：/*注释内容*/

## SQL分类

* DDL:数据定义语言，用来定义数据库对象
* DML:数据操作语言，用来对数据库表中的数据进行增删改
* DQL：数据查询语言，用来查询数据库中表的记录
* DCL：数据控制语言，用来创建数据库用户、控制数据库的访问权限

## DDL语句

### DDL-数据库操作

```sql
# 查询
   	#查询所有数据库
   	SHOW DATABASES;
   	#查询当前数据库
   	SELECT DATABASE();
#创建
CREATE DATABASE[IF NOT EXISTS]数据库名[DEFAULTCHARSET 字符集] [COLLATE 排序规则]；
#删除
DROP DATABASE[IF EXISTS]数据库名；
#使用
USE 数据库名；
```

### DDL表操作

```sql
# 查询
	#查询当前数据库的所有表
	SHOW TABLES;
	#查询表结构
	DESC 表名;
	#查询指定表的建表语句
	SHOW CREATE  TABLE 表名;
#创建
	CREATE TABLE 表名
	（
		字段1 字段1类型[COMMENT 字段1注释]；
		字段2 字段2类型[COMMENT 字段2注释]；
		字段3 字段3类型[COMMENT 字段3注释]；
		....
		字段n 字段n类型[COMMENT 字段n注释]；
	）[COMMENT 注释]；	
#修改
	#添加字段
	ALTER TABLE 表名 ADD 字段名 类型(长度)[comment 注释][约束];
	#修改数据类型
	ALTER TABLE 表名 MODIFY 字段名 新数据类型(长度);
	#修改字段名和字段类型
	ALTER TABLE表名 CHANGE 旧字段名 新字段名 类型(长度)[COMMENT 注释][约束];  
	#修改表名
	ALTER TABLE 表名(改前) RENAME TO 表名（改后）
#删除
	#删除表
	DROP TABLE [IF EXISTS]表名;
	#删除指定表，并重新创建该表
	TRUNCATE TABLE 表名;
```

##  DML语句

数据操作语言

```sql	
#添加数据（INSERT）
	#给指定字段添加数据
	INSERT INTO 表名（字段1，字段2，...）VALUES（值1，值2，...）;
	#给全部字段添加数据
	INSERT INTO 表名 VALUES(值1，值2，...);
	#批量添加数据
	INSERT INTO 表名(字段1，字段2,...)VALUES(值1，值2，...),（值1，值2，...）,(值1，值2，...);
	INSERT INTO 表名 VALUES (值1，值2，...),(值1，值2，...);
#修改数据
	 #修改指定字段的数据
		UPDATE 表名 SET 字段名1-值1，字段2-值2，...[WHERE 条件];
		--如果不带where条件将执行到表中所有的数据上。	
#删除数据
	DELETE FROM 表名 [WHERE 条件];

```

## DQL

​	#查询语句

​	查询关键字 select

```sql
#编写顺序   #执行顺序
SELECT 	
		字段列表    #4    
FROM	
		表名列表     #1
WHERE 	
		条件列表     #2
GROUP BY
		分组字段列表   #3
HAVING
		分组后条件列表  #5
ORDER BY
		排序字段列表	  #6
LIMIT
		分页参数

```

### 基本查询

```SQL
#查询多个字段
SELECT 字段1，字段2，字段3...FROM 表名;
SELECT FROM 表名;
#设置别名
SELECT 字段1[AS 别名1]，字段2[AS 别名2]....FROM 表名;
#去除重复记录
SELECT DISTINCT 字段列表 FROM 表名;
```

### 条件查询

```sql
SELECT 字段列表 FROM 表名 WHERE 条件列表;
#SELECT* 表示查询表里的全部字段
```

### 聚合查询

```sql
聚合函数
count  统计数量
max		最大值
min		最小值
avg		平均值
sum		求和

SELECT 聚合函数(字段列表) FROM 表名;
#NULL值不参与聚合函数的运算。
```

### 分组查询

```sql
SELECT 字段列表 FROM 表名 [WHERE 条件]GROUP BY 分组字段名[HAVING 分组后过滤条件];
#where与having区别
#执行时机不同：where是分组值钱进行过滤，不满足where条件，不参与分组；而having是分组之后对结果进行过滤。
#判断条件不同：where不能对聚合函数进行判断，而having可以。

selec

```

### 排序查询

```sql
SELECT 字段列表  FROM 表名 ORDER BY 字段1 排序方式1，字段2 排序方式2;


#排序方式
  #ASC:升序（默认值）
  #DESC:降序  
```

### 分页查询

```sql
SELECT 字段列表 FROM 表名 LIMIT 起始索引,查询记录数;
```



## DCL

DCL   数据控制语言 用来管理数据库用户，控制数据库的访问权限。

## 用户管理 

```sql
# 查询用户
 USE mysql;
 SELECT * FROM user；
 
#创建用户
CREATE USER '用户名'@'主机名'	IDENTIFIED BY '密码';
# localhost 本机
# %       任意机器
#修改用户密码
ALTER USER '用户名'@'主机名' IDENTIFIED WITH mysql_natibe_password BY '新密码';
#删除用户
DROP USER '用户名'@'主机名';
```

### 权限控制

```sql
#常用权限
ALL,ALL PRIVILEGES 所有权限
SELECT 			   查询权限
INSERT				插入权限
UPDATE				修改权限
DELETE				删除权限
ALTER				修改表
DROP				删除数据库/表/视图
CREATE				创建数据库/表
```

```sql
#查询权限
	SHOW GRANTS FOR '用户名'@'主机名';
#授予权限
	GRANT 权限列表 	ON	 数据库名.表名 TO '用户名'@'主机名';
#撤销权限
	REVOKE 权限列表 ON   数据库名.表名 FROM '用户名'@'主机名';
```



## MySQL中的数据类型

# 函数

## 字符串函数

```sql
#常用字符串函数
CONCAT(S1,S2...Sn)   字符串拼接,S1,S2,...SN拼接成一个字符串。
LOWER(str)			  将字符串str全部转为小写
UPPER(str)				将字符串str全部转为大写
LPAD(str,n,pad)			左填充,将字符串pad对str的左边进行填充,达到n个字符串长度
RPAD(str,n,pad)			右填充,用字符串pad对str的右边进行填充,达到n个字符串长度.
TRIM(str)				去掉字符串头部和尾部的空格。
SUBSTRING(str,start,len)  返回从字符串str从start位置起的的len个长度的字符串。
```



## 数值函数

```SQL
#常见数值函数
	CEIL(x)					向上取整
	FLOOR(x)				向下取整
	MOD（x,y）			   返回x/y的模
	RAND()					返回0~1的随机数
	ROUND（x,y）			   求参数x的四舍五入的值,保留y位小数。
```



## 日期函数

```sql
#常见日期函数
	CURDATE()   			 返回当前日期
	CURTIME()			 	 返回当前时间
	NOW()					 返回当前时间和日期
	YEAR（date）				获取指定date的年份
	MONTH（date）				获取指定date的月份
	DAY（date）				获取指定date的日期
	DATE_ADD(date,INTERVAL expr type)
							返回一个日期/时间值加上								一个时间间隔
	DATEIFF（date1,date2）   返回起始时间date1和结束时间							    date2之间的天数
```



## 流程函数

```sql
#常用流程控制函数
IF(value,t,f)	  		如果value为true，则返回t，否则返回f
IFNULL(value1,value2)	如果value1不为空,返回value1,否则返回value2
CASE WHEN [val1] THEN[res1]...ELSE[default]END
					如果val1为true,返回res1,...否则返回default默认值。
	CASE[expr]WHEN[val1]THEN[res1]...ELSE[default]END
					如果expr的值等于val1，则返回res1,...否则返回default默认值。
```

# 约束

```sql
#常见约束
	#非空约束
	限制改字段的数据不能为NULL， 关键字NOT NULL
	#唯一约束
	保证该字段的所有数据都是唯一的、不重复的。关键字UNIQUE
	#主键约束
  主键是一行数据的唯一标识，要求非空且唯一  关键字PRIMARY KEY
    #默认约束
   保存数据时，如果未指定该字段的值，则采用默认值 关键字DEFAULT
   	#检查约束
   	保证字段值满足某一个条件		关键字CHECK
    #外键约束
    用来让两张表的数据之间建立连接，保证数据的一致性和完整性
    						关键字	FOREI
```

## 外键

```sql
NO ACTION 
RESTRICT
CASCADE
SET NULL
SET DEFAULT
```



# 多表查询

 ## 多表关系

     ```sql
     #一对多
     部门与员工，在多的一方建立外键，指向一的一方主键。
     #多对多
     学生与课程，建立第三张中间表，中间表至少包含两个外键，分别关联两方主键。
     #一对一
     用户与用户详情的关系，多用于单表拆分，将一张表的基础字段放在一张表中，其他详情字段放在另一张表中，以提升操作效率。
     在任意一方加入外键，关联另外一方的主键，并且设置外键为唯一的(unique)
     ```
    
     ## 多表查询    

​     笛卡尔积

```sql
#多表查询分类
 #连接查询
 	内连接：相当于查询A,B交集部分数据
 	外连接：
 		左外连接：查询左表所有数据，以及两张表交集部分数据
 		右外连接：查询右表所有数据，以及两张表交集部分数据
 	自连接：当前表与自身的连接查询，自连接必须使用表别名。
 #子查询
```

​                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

 ### 内连接

```sql
#隐式内连接
  SELECT 字段列表 FROM 表1，表2 WHERE 条件...
 #显式内连接
 SELECT 字段列表 FROM 表1[INNER]JOIN表2 ON 连接条件...;
```

## 外连接

```sql
#左外连接
SELECT 字段列表 FROM 表1 LEFT[OUTER]JOIN 表2 ON 条件..;
#右外连接
SELECT 字段列表 FROM 表1 RIGHT[OUTER]JOIN表2 ON 条件..;
```

## 自连接

```sql
SELECT 字段列表 FROM 表A 别名A JOIN 表A 别名B ON 条件..;
```

## 联合查询

```sql
SELECT 字段列表 FROM 表A...
UNION[ALL]
SELECT 字段列表 FROM 表B...

#联合查询的多张列表必须保持一致，字段类型也需要保持一致。
#union all 会将全部的数据直接合并在一起，union会对合并之后的数据去重。
```



## 子查询

```sql
# SQL语句中嵌套SELECT语句，称为嵌套语句，又称子查询。
SELECT *FROM t1 WHERE columnl = (SELECT columnl FROM t2);
  
#标量子查询（子查询结果为单个值）
#列子查询（子查询结果为一列）
#行子查询（子查询结果为一行）
#表子查询（子查询结果为多行多列）
```

# 事务

事务是一组操作的集合，它是一个不可分割的工作单位，事务会把所有的操作作为一个整体像系统提交或撤销操作请求，即这些操作要么同时成功，要么同时失败。

 ## 事务操作

```sql
#查看/设置事务提交方式
SELECT@@autocommit;
SET @@autocommit = 0;//将自动提交改为手动提交


#开启事务
START TRANSACTION 或 BEGIN #手动提交事务

#提交事务
COMMIT;

#回滚事务
ROLLBACK;
```

## 事务的特性（ACID）

```sql
#原子性
	事务是不可分割的最小操作单元，要么全部成功，要么全部失败。
#一致性
	事务完成时，必须使所有的数据都保持一致状态
#隔离性
	数据库系统提供的隔离机制，保证事务在不受外部并发操作影响下的独立环境运行。
#持久性
	事务一旦提交或回滚，它对数据库中的数据改变就是永久的。
```

## 并发事务问题

```sql
#常见问题
 	#脏读
 		一个事务读到另一个事务还没有提交的数据
 	#不可重复读
 		一个事务先后读取同一条记录，但两次读取的数据不同，称之为不可重复读。
 	#幻读
 	一个事务按照田间查询数据时，没有对应的数据行，但是在插入数据时，又发现了这行数据已经存在，好像出现了"幻影"。
 		
```

## 事务的隔离级别

| 隔离级别                   | 脏读 | 不可重复度 | 幻读 |
| -------------------------- | ---- | ---------- | ---- |
| Read uncommitted           | 1    | 1          | 1    |
| Read committed             | 0    | 1          | 1    |
| Repeatable Read(mysql默认) | 0    | 0          | 1    |
| Serializable               | 0    | 0          | 0    |

```SQL
#查看事务的隔离级别
SELECT @@TRANSACTION_ISOLATION;

#设置事务隔离级别
SET [SESSION|GLOBAL]TRANSACTION ISOLATION LEVEL
{READ UNCOMMITTED|READ COMMITTED|REPEATABLE READ|SERIALIZAB}
```



# 存储引擎

 存储引擎就是存储数据、建立索引、更新/查询数据等技术的实现方式。存储引擎是基于表的，而不是基于库的，所以存储引擎也可被成为表类型。

Mysql默认引擎是InnoDB，

* InnoDB的特点

事务，外键，行级 锁

## InnoDB逻辑存储结构

相关文件：xx.ibd

* TableSpace:表空间（）

* Segment:段（）

* Extent:区(1M)

* Page:页(16K)

* Row:行

# 索引（index）

索引是帮助mysql高效获取数据的数据结构（ 有序）。在数据之外，数据库系统还维护者满足特定查找算法的数据结构，这些数据结构以某种方式引用（指向）数据，这样就可以在这些数据结构上实现高级查找算法，这种数据结构就是索引。

**优点**

索引提高了数据检索的效率，降低了数据库的io成本。通过索引列对数据进行排序，降低数据排序的成本，降低CPU的消耗。

**缺点**

索引列也是需要占用空间的，索引大大提高了查询效率，同时却也降低更新表的速度。

## 索引的结构

MYSQL的索引是在存储引擎层实现的，不同的存储引擎有不同的结构。主要有

* B+tree 索引：最常见的索引类型，大部分引擎都支持B+树索引
* Hash索引：底层数据结构是用Hash表实现的，只有精确匹配索引列的查询才有效，不支持范围查询。
* R-tree（空间索引）：空间索引是MyISAM引擎的一个特殊索引类型，主要用于地理空间数据类型，通常使用较少
* Full-text(全文索引)：是一种通过建立倒排索引，快速匹配文档的方式。类似于Lucene，Solr,ES.

二叉树缺点：顺序插入时，会形成一个链表，查询性能大大降低。大数据情况下，层次较深，检索速度慢。

红黑树：大数据量情况下，层级较深，检索速度慢。

### B树与B+树 

* B树



* B+树



### Hash

* Hash结构

1. Hash索引只能用来对等比较（=，in）,不支持范围查询
2. 无法利用索引完成排序操作
3. 查询效率高，通常只需要一次检索就可以了，效率通常要高于B+tree索引。

在MySQL中innoDB,支持Hash索引的时Memory引擎，而innoDB具有自适应hash功能，hash索引时存储引擎根据B+tree索引在指定条件下自动构建的。



## 索引分类

* 主键索引
* 唯一索引
* 常规索引
* 全文索引

在InnoDB存储引擎中，根据索引的存储形式可分为

* 聚集索引
* 二级索引

聚集索引的选取规则：

如果存在主键，主键索引就是聚集索引

* 回表查询

## 索引的语法

```sql
	CREATE [UNIQUE][FULLTEXT]INDEX index_name ON table_name(index_col_name,...);
#查看索引
SHOW INDEX FROM table_name；
#删除索引
DROP INDEX index_name ON table_name;


```

## 索引性能分析

```sql
#执行频率
#查看服务器状态信息
SHOW [session|global] status;
#查看当前数据库的insert,update,delete,select的访问频次
SHOW GLOBAL STATUS like'Com__';

#慢查询日志   /var/lib/mysql/localhost-slow.log
# 开启MySQL慢日志查询开关
slow_query_log =1;
#设置慢日志的时间为2秒
long_query_time=2；

#profile详情
#查询数据库是否支持profile
select @@have_profiling;
#查询数据库是否开启profile
select @@profiling;
#在session/global级别开启profiling
set profiling =1;
#查看当前会话中的sql语句的执行情况
show profiles; 
#查看指定query_id的SQL语句各个阶段的耗时情况
show profile for query query_id;
#查看query语句的cpu耗费情况
show profile cpu for query query_id;

#explain执行计划
在select语句前加explain或者desc
id 表示select查询的序列号，值越大，越先执行
type 表示连接类型，性能由好到差的连接类型时NULL，system,const,eq_ref,ref,range,index,all。
```

## 索引的使用

*  最左前缀法则：如果索引了多列，要遵守最左前缀法则。最左前缀法则指的是查询从索引的最左列开始，并且不跳过索引中的列。如果跳跃某一列，索引将部分失效。
* 范围查询：联合索引中，出现范围查询时（<,>）,范围查询右侧的列索引失效。在业务允许的情况下使用>= 或<=。
* 索引列运算： 不要再索引列上进行运算操作，索引将失效。
* 字符串不加引号：字符串不加引号会导致索引失效。
* 模糊查询：如果仅仅是尾部模糊匹配，索引不会失效。如果时头部模糊匹配，索引失效。
* or连接的条件：用or分割开的条件，如果or前的条件中的列有索引，而后面的列中没有索引，那么设计到的索引都不会被用到。
* 数据分布情况：
* SQL提示：SQL提示是优化数据库的一个重要手段，简单来说，就是再SQL语句中加入一些认为的提示来达到优化操作的目的。

```sql
use index

ignore index

force index
```

* 覆盖索引: 二级索引下面挂的是主键，当要查询的信息中有其他数据是会出现回表查询。
* 前缀索引:为了对大文件前缀节约磁盘空间。
* 单列索引与联合索引：优先使用联合索引

## 索引设计原则

* 针对数据量较大，且查询比较频繁的表建立索引。
* 针对常作为查询条件（where）、排序(order by)、分组(group by)操作的字段建立索引。
* 尽量选择区分度高的列作为索引，尽量建立唯一索引，区分度越高，使用索引的效率越高。
* 如果字符串类型的字段，字段的长度较长，可以针对于字段的特点，建立前缀索引
* 尽量使用联合索引，减少单列索引，查询时，联合索引很多时候可以使用覆盖索引，节约存储空间。避免回表。
* 要控制索引的数量，索引并不是多多益善，索引越多，维护索引结构的代价也就越大，会影响增删改的效率。
* 如果索引列不饿能存储NULL值，请再创建表时使用NOT NULL约束它。当优化器知道是否包含NULL值时，它可以更好地确定哪个索引最有效地用于查询。

# SQL优化

## 插入数据

  **insert优化**

* 批量插入
* 手动事务提交
* 主键顺序插入

```sql
#大批量插入数据用load语句
#客户端连接服务器端时，加上参数 --local-infile
mysql --local-infile -u root -p
#设置全局参数local_infile为1，开启本地加载文件导入数据的开关
set global local_infile=1;
#执行load指令将准备好的数据，加载到表结构中
load data local infile '/root/sql.log'into table 'tb_user' fields terminated by ',' lines terminated by '\n';
```

## 主键优化

在innoDB存储引擎中，表数据都是根据主键顺序组织存放的，这种存储方式的表成为索引组织表。

* 页分裂
* 页合并

主键设计原则

* 满足业务需求的情况下，尽量降低主键的长度
* 插入数据时，尽量选择顺序插入，选择使用AUTO_INCREMENT自增主键。
* 尽量不要使用UUID做主键或者是其他自然主键，如身份证号。
* 业务操作时，避免对主键的修改。

## oderby优化

Using filesort：通过表的索引或全表扫描，读取满足条件的数据行，然后在排序缓存区sort buffer中完成排序操作，所有不是通过索引直接返回排序结果的排序都叫filesort排序。

Using index：通过有序索引顺序三秒返回有序数据，这种情况即为using index，不需要额外排序，操作效率高。

设计原则：

* 根据排序字段建立合适的索引

* 多字段排序遵循最左前缀法则

  

## group by 优化



## limit 优化

limit在大数据情况下时间长。

覆盖索引加子查询

## count 优化

* MyISAM引擎把一个表的总数存在磁盘上
* InnoDB一个一个数据写入磁盘

count(主键)：InnoDB引擎会遍历整张表，把每一行的主键ID值都拿出来，返回服务层。服务层拿到主键后，直接按行进行累加（主键值不可能为NULL）。

count(字段)：

没有not null 约束，InnoDB引擎会遍历整张表把每一行的字段值都取出来，返回给服务层，服务层判断是否为null，不为null，计数累加。

有not null约束：引擎会遍历整张表把么一一行的字段都取出来，返回给服务层，直接进行累加。

count(1)：InnoDB引擎遍历整张表，但不取值。服务层对于返回的每一行，放一个数字"1"进去，直接按行进行累加。

## update 优化

InnoDB的行锁是针对索引加的锁，并且该索引不能失效，否则会从行锁升级为表锁。

# 视图/存储过程/触发器

 ## 视图

视图是一种虚拟存在的表,

```sql
//创建视图
CREATE [OR REPLACE] VIEW 视图名[(列表名)] AS SELECT语句
[WITH[CASCADED|LOCAL]CHECK OPTION];
WITH CHECK OPTION选项。
//查询视图
//查看创建试图语句：
SELECT CREATE VIEW 视图名;
//查询视图数据
SELECT *FROM 视图名称;


//修改
CREATE [OR REPLACE] VIEW 视图名称[(列名列表)] AS 	SELECT语句 [WITH[CASCADED|LOACL]CHECK OPTION]

//删除
DROP VIEW [IF EXISTS] 视图名称...

//插入
INSERT INTO 视图名 value()


```

MySQL允许基于另一个视图创建视图，它还会检查依赖视图中的规则以保持一致性。为了确定检查的范围，mysql提供了两个选项：cascaded与local，默认值为cascaded。

### 视图的更新

要使视图可更新，视图中的行与基础表中的行之间必须存在一对一的关系。如果视图包含以下任一项，则该视图不可更新：

1. 聚合函数或窗口函数（sum()、min()、max()、count()等）
2. distinct
3. group by
4. having
5. union 或者union all

### 视图的作用

* 简单：视图不仅可以简化用户对数据的理解，也可以简化他们的操作。那些被经常使用的查询可以被定义为视图，从而使得用户不必为以后的操作每次指定全部的条件
* 安全：数据库可以授权，但不能授权到数据库特定行和特定列上。通过视图用户只能查询和修改他们所能见到的数据
* 数据独立：视图可帮助用户屏蔽真实表结构变化带来的影响。

## 存储过程



## 存储函数

## 触发器
