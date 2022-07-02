#ifndef __SPECIALIZATION__
#define __SPECIALIZATION__
#ifndef __SZIE_T
#define __SZIE_T
typedef unsigned int size_t;

template <class key>
struct hash {};

template <>
struct hash<char >
{
    size_t operator() (char x)const {return x;}
};

template<>
struct hash<int>
{
    size_t operator()(int x) const {return x;}
};

template<>
struct hash<long>
{
    size_t operator()(long x) const {return x;}
};

#endif
#endif