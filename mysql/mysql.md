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



