#ifndef __FRACTION_
#define __FRACTION_

class  Fraction
{
    public:
        explicit Fraction(int num, int den =1)
        : m_numerator(num), m_denominator(den){}//non_explicit-one-argument ctor// 转换函数
         
        // operator double() const
        // {
        //     return (double)(m_numerator / m_denominator);
        // }//转换函数

        Fraction operator + (const Fraction& f)
        {
            return Fraction(m_numerator + f.m_numer);
        }
    

    private:
        int m_numerator; //分子
        int m_denominator;//分母

};



#endif