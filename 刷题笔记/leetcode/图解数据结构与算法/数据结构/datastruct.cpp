//常见数据结构
//线性数据结构：数组，链表，栈，队列
//非线性数据结构：树，堆，散列表，图


//数组

//初始化数组

int arry[5];

//赋值
int array[] = {2,3,1,0,2};

#include <vector>
using namespace std;

//初始化可变数组
int Array(void)
{

//vector的使用要包含std
vector<int> array1;

//向尾部添加元素
//类内函数体外只能定义全局变量和对象，不能执行语句或调用函数。
//以下语句只能再函数体内执行
array1.push_back(2);
array1.push_back(3);
array1.push_back(1);
array1.push_back(0);
array1.push_back(2);

return 0;
}
#include <stdio.h>
//链表
void list(void)
{
struct ListNode
{
    int val;            //节点值
    ListNode *next;     //后继节点
    //结构体的构造函数
    ListNode(int x): val(x),next(NULL){}//NULL值定义再stdio.h中
};

//实例化节点
ListNode *n1 = new ListNode(4); //节点head
ListNode *n2 = new ListNode(5); 
ListNode *n3 = new ListNode(1); 

//构建指向
//以下语句也需要放入函数体内
n1->next = n2;
n2->next = n3;

}
#include <stack>
void Stack(void)
{
//声明一个栈
stack<int> stk;

stk.push(2); //元素1入栈
stk.push(1); //元素2入栈
stk.pop();   //出栈->元素2
stk.pop();   //出栈->元素1

}

//队列
#include <Queue>
void queue1()
{
    
    queue<int> que;

    que.push(1);
    que.push(2);
    que.pop();
    que.pop();

}

//树
struct TreeNode
{
    int val;        //节点值
    TreeNode *left; //左节点
    TreeNode *right; //右节点
    TreeNode(int x): val(x),left(NULL),right(NULL){}

};
int Tree()
{
//初始化节点
TreeNode *n1 =new TreeNode(3);
TreeNode *n2 =new TreeNode(4);
TreeNode *n3 =new TreeNode(5);
TreeNode *n4 =new TreeNode(1);
TreeNode *n5 =new TreeNode(2);
//结构体不能用.替代->
n1->left =n2;
n1->right =n3;
n2->left =n4;
n2->right =n5;

}

//图
//邻接矩阵
int vertices[5] = {1,2,3,4,5};
int edges[5][5] = {{0,1,1,1,1},{1,0,0,1,0},{1,0,0,0,1},{1,1,0,0,1},{1,0,1,1,0}};

//邻接表
int vertices[5] = {1,2,3,4,5};
vector<vector<int>> edgs;

int edge1()
{
vector<int> edge_1 = {1,2,3,4};
vector<int> edge_2 = {0,3};
vector<int> edge_3 = {0,4};
vector<int> edge_4 = {0,1,4};
vector<int> edge_5 = {0,2,3};
edgs.push_back(edge_1);
edgs.push_back(edge_2);
edgs.push_back(edge_3);
edgs.push_back(edge_4);
edgs.push_back(edge_5);

}

//散列表
#include <unordered_map>
#include <string>
unordered_map<string,int> dic;
int map()
{
//添加key ->value键值对
dic["小力"]=10001;
dic["小特"]=10002;
dic["小扣"]=10003;

//从姓名查找学号
dic.find("小力") ->second; //-> 10001
dic.find("小特") ->second; //-> 10002
dic.find("小扣") ->second; //-> 10003

return 0;
}


//Hash函数

string names[]={"小力","小特","小扣"};

int hash1(int id)
{
    int index =(id-1)%10000;
    return index;
}


void Hash()
{
    names[hash1(10001)];
    names[hash1(10002)];
    names[hash1(10003)];


}

//堆
//初始化小顶堆
priority_queue<int,vector<int>,greater<int>> heap1;

void heap()
{
//元素入堆
heap1.push(1);
heap1.push(4);
heap1.push(2);
heap1.push(6);
heap1.push(8);
//元素出堆
heap1.pop();//->1
heap1.pop();//->2
heap1.pop();//->4
heap1.pop();//->6
heap1.pop();//->8

}
