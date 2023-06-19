#include "rational.hpp"

namespace ilrd
{

    static int Gcd(int a, int b)
    {
        int result = 0;
        
        (a < b) ? result = a : result = b;

        while (result > 0)
        {
            if (((a % result) == 0) && ((b % result) == 0))
            {
                break;
            }
            result--;
        }
        return result;
    }

    static Rational Minimize(Rational &curr)
    {
        int numer = 0;
        int de_numer = 0;
        int flag = 0;

        numer = curr.Numerator();
        de_numer = curr.Denominator();

        if(numer < 0 && de_numer < 0)
        {
            numer *= -1;
            de_numer *= -1;
        }
        else if(numer < 0)
        {
            numer *= -1;
            flag = 1;
        }
        else if(de_numer < 0)
        {
            de_numer *= -1;
            flag = 2;
        }

        while (Gcd(numer, de_numer) != 1)
        {
            int res = Gcd(numer, de_numer);
            numer /= res;
            de_numer /= res;
        }

        if(flag == 1)
        {
            numer *= -1;
        }
        if (flag == 2)
        {
            de_numer *= -1;
        }
        
        Rational temp(numer, de_numer);
        return temp;
    }

    Rational::Rational(int num, int denum) : m_numerator(num), m_denominator(denum) {}

    const Rational operator+(const Rational &lhs, const Rational &rhs)
    {
        int top = 0;
        int buttom = 0;
        top = (lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator());
        buttom = (lhs.Denominator() * rhs.Denominator());
        Rational temp(top, buttom);
        // GCD()
        temp = Minimize(temp);
        return temp;
    }

    const Rational operator-(const Rational &lhs, const Rational &rhs)
    {
        int top = 0;
        int buttom = 0;
        top = (lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator());
        buttom = (lhs.Denominator() * rhs.Denominator());
        Rational temp(top, buttom);
        // GCD()
        temp = Minimize(temp);
        return temp;
    }

    const Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        int top = 0;
        int buttom = 0;
        top = (lhs.Numerator() * rhs.Numerator());
        buttom = (lhs.Denominator() * rhs.Denominator());
        Rational temp(top, buttom);
        // GCD()
        temp = Minimize(temp);
        return temp;
    }

    const Rational operator/(const Rational &lhs, const Rational &rhs)
    {
        int top = 0;
        int buttom = 0;
        top = (lhs.Numerator() * rhs.Denominator());
        buttom = (lhs.Denominator() * rhs.Numerator());
        Rational temp(top, buttom);
        // GCD()
        temp = Minimize(temp);
        return temp;
    }

    Rational &Rational::operator+=(const Rational &other)
    {
        this->m_numerator = (this->m_numerator * other.m_denominator) + (other.m_numerator * this->m_denominator);
        this->m_denominator = this->m_denominator * other.m_denominator;
        // GCD()
        *this = Minimize(*this);
        return *this;
    }

    Rational &Rational::operator-=(const Rational &other)
    {
        this->m_numerator = (this->m_numerator * other.m_denominator) - (other.m_numerator * this->m_denominator);
        this->m_denominator = this->m_denominator * other.m_denominator;
        // GCD()
        *this = Minimize(*this);
        return *this;
    }

    Rational &Rational::operator*=(const Rational &other)
    {
        this->m_numerator = this->m_numerator * other.m_numerator;
        this->m_denominator = this->m_denominator * other.m_denominator;
        // GCD()
        *this = Minimize(*this);
        return *this;
    }

    Rational &Rational::operator/=(const Rational &other)
    {
        this->m_numerator = this->m_numerator * other.Denominator();
        this->m_denominator = this->m_denominator * other.m_numerator;
        // GCD()
        *this = Minimize(*this);
        return *this;
    }

    bool operator==(const Rational &lhs, const Rational &rhs)
    {
        // GCD() both numbers
        if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()))
        {
            return true;
        }
        return false;
    }

    bool operator!=(const Rational &lhs, const Rational &rhs)
    {
        if (lhs == rhs)
        {
            return false;
        }
        return true;
    }
}