#include<string>
using namespace std;

//替换空格


//逆序遍历
class Solution{
 public:
    string replaceSpace(string s)
    {
        int count =0;
        int len = s.size();
        //统计空格数量
        for(char c:s)
        {
            if(c=' ')
            count++;
        }
        //修改s长度
        s.resize(len + 2*count);
        //倒序遍历修改
        for(int i=len-1,j=s.size() -1;i<j;i--,j--)
        {
            if(s[i] !=' ')
                s[j]=s[i];
            else
            {
                s[j-2] ='&';
                s[j-1] ='2';
                s[j] = '0';
                j-=2;
            }
        }
        return s;
    }

};
//容器更新
class Solution{
 public:
    string replaceSpace(string s)
    {
        string res;
        for(int i =0;i<s.size();++i)
        {
            if(s[i] != ' ')
                res +=s[i];
            else
            {
                res +='%';
                res +='2';
                res +='0';

            }
        }
    }

};


