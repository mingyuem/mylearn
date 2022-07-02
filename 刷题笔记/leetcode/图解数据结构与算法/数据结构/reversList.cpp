#include<stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
//迭代
class Solution
{
    public:
        ListNode* reverseList(ListNode* head)
        {
            ListNode *cur=head, *pre=nullptr;
            while(cur != nullptr)
            {
                ListNode* tmp =cur->next;
                cur->next=pre;
                pre=cur;
                cur=tmp;
            }
        }
};

//递归
class Solution
{
    public:
        ListNode* reverseList(ListNode* head)
        {
            return recur(head,nullptr);
        }
    private:
        ListNode* recur(ListNode* cur,ListNode* pre)
        {
            if(cur ==nullptr)
            return pre;
            ListNode* res=recur(cur->next,cur);
            cur->next =pre;
            return res;
        }
};
