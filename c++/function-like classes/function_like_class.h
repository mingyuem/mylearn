//将类模拟函数————仿函数
 
#ifndef __FUNCTION__LIKE_CLASS__
#define __FUNCTION__LIKE_CLASS__

template <class T> 
struct identity
{
    const T& 
    operator()(const T& x) const{return x;}
};

template <class Pair>
struct selectlist
{
    const typname Pair::first_type&
    operator()(const Pair& x)
    cosnt {return x.first;}
};

template <class Pair>
struct selectlist2nd
{
    const typname Pair::second_type&
    operator()(const Pair& x) const
    {return x.second;}
};
#endif