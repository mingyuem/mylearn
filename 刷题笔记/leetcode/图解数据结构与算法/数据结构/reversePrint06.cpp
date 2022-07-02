#include<stdio.h>
#include<vector>
using namespace std;

//从尾到头打印链表
//定义链表节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


//递归法
class Solution
{
    public:
        vector<int>reversePrint(ListNode* head)
        {
            recur(head);
            return(res);
        }

        private:
            vector<int>res;
            void recur(ListNode* head)
            {
                //链表尾指针
                if(head ==nullptr)
                return;
                //递归进入下一节点
                recur(head->next);
                res.push_back(head->val);
            }
};

//辅助栈
//先进后出适合栈
#include<stack>
class Solution
{
    public:
        vector<int> reversePrint(ListNode* head)
        {
            stack<int> stk;
            while(head != nullptr)
            {
                stk.push(head->val);
                head =head->next;
            }
            vector<int> res;
            while(!stk.empty())
            {
                res.push_back(stk.top());
                stk.pop();
            }
        }
};

#include <algorithm>
class Solution
{
    public:
        vector<int> reversePrint(ListNode* head)
        {
            vector<int> s;
            while(head !=NULL)
            {
                s.push_back(head->val);
                head= head->next;
            }
            reverse(s.begin(),s.end());//反转函数
        }
};

