#include<stack>
using namespace std;
//两个栈实现队列

class CQueue
{
    public:
        stack<int> A,B;
        CQueue(){}
        void appedTail(int value)
        {
            A.push(value);
        }
        int deleteHead()
        {
            if(!B.empty())
            {
                int tmp=B.top();
                B.pop();
                return tmp;
            }
            if(A.empty())
            return -1;
            while(!A.empty())
            {
                int tmp =A.top();
                A.pop();
                B.push(tmp);
            }
            int tmp=B.top();
            B.top();
            return tmp;
        }

};

