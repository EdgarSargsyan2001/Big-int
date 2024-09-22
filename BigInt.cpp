#include "Bigint.h"
#include <utility> // For std::swap
#include <iostream>

BigInt::BigInt(int num)
{
    parse(std::to_string(num));
}

BigInt::BigInt(const std::string &str)
{
    // std::cout << "string ctor\n";
    parse(str);
}
BigInt::BigInt(const char *str)
{
    // std::cout << "char* ctor\n";
    parse(str);
}

// =========== arithmetic operation ===========

BigInt &BigInt::operator+=(const BigInt &b)
{

    if (this == &b)
    {
        BigInt newB(b);
        return *this += newB;
    }
    // if (*this < 0 && x >= 0)
    // {
    //     tmp = *this;
    //     tmp.sign = 0;
    //     return (x - tmp);
    // }
    // if (x < 0 && *this >= 0)
    // {
    //     tmp = x;
    //     tmp.sign = 0;
    //     return (*this - tmp);
    // }

    // BigInt tmp;
    if (_sign == b._sign)
    {
        _sign = _sign; // or b._sign
    }
    std::string tmpNum = _str;
    _str = "";

    int s1 = tmpNum.size();
    int s2 = b._str.size();
    int i = 0;

    short num = 0;
    short carry = 0;

    while (i < s1 && i < s2)
    {
        num = (tmpNum[i] + b._str[i]) + carry;
        carry = (num / 100);
        _str.push_back((num % 100));
        ++i;
    }

    while (i < s1)
    {
        num = tmpNum[i++] + carry;
        carry = (num / 100);
        _str.push_back((num % 100));
    }

    while (i < s2)
    {
        num = b._str[i++] + carry;
        carry = (num / 100);
        _str.push_back((num % 100));
    }

    if (carry)
        _str.push_back(carry);

    return *this;
}

const BigInt operator+(const BigInt &a, const BigInt &b)
{
    return BigInt(a) += b;
}

const BigInt operator-(const BigInt &a, const BigInt &b)
{
    if (a._sign == 1 && b._sign == 0)
    {
        BigInt tmp(a);
        tmp._sign = 0;
        tmp += b;
        tmp._sign = 1;
        return tmp;
    }

    if (a._sign == 0 && b._sign == 1)
    {
        BigInt tmp(b);
        tmp._sign = 0;
        tmp += a;
        return tmp;
    }

    BigInt tmp;

    if (a < b)
    {
        a.swap(b);
    }

    short borrow = 0;
    for (short i = 0, j = 0; i < s1.size() || j < s2.size();)
    {
        short op1 = i < s1.size() ? (s1[i++] - borrow) : (0 - borrow);
        short op2 = j < s2.size() ? (s2[j++]) : 0;
        borrow = (op1 < op2) ? 1 : 0;
        short num = op1 - op2 + 100 * borrow;
        tmp._str.push_back((num % 100));
    }

    while (*(tmp._str.end() - 1) == '\0' && !tmp._str.empty())
        tmp._str.pop_back();

    if (tmp._str.empty())
        tmp = 0;

    return tmp;
}

// =========== conditional operation ===========
bool operator==(const BigInt &a, const BigInt &b)
{
    return (a._sign == b._sign && a._str == b._str);
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return (a._sign != b._sign || a._str != b._str);
}

bool operator<(const BigInt &a, const BigInt &b)
{
    std::size_t s1 = a._str.size();
    std::size_t s2 = b._str.size();

    if (a._sign == b._sign)
    {
        if (s1 == s2)
        {
            std::size_t end = s1 - 1;
            if (a._sign == 1)
            {
                return a._str[end] > b._str[end];
            }
            else
            {
                return a._str[end] < b._str[end];
            }
        }
        else
        {
            if (a._sign == 1)
            {
                return s1 > s2;
            }
            else
            {
                return s1 < s2;
            }
        }
    }

    return a._sign; //  (a._sign == 1) ? true : false
}

std::ostream &operator<<(std::ostream &os, const BigInt &a)
{
    if (a._sign)
        os << '-';

    int end = a._str.size() - 1;

    os << (short)a._str[end];
    for (int i = end - 1; i >= 0; i--)
    {
        if (a._str[i] < 10)
            os << '0';

        os << (short)a._str[i];
    }

    return os;
}

void BigInt::print() const
{
    std::cout << "size: " << _str.size() << ":  ";
    if (_sign)
        std::cout << '-';
    int end = _str.size() - 1;

    std::cout << (short)_str[end];
    for (int i = end - 1; i >= 0; i--)
    {
        if (_str[i] < 10)
            std::cout << '0';

        std::cout << (short)_str[i];
    }
    std::cout << std::endl;
}

void BigInt::parse(const std::string &strNum)
{
    int s = 0; // start
    int size = strNum.length();

    if (strNum[s] == '-' || strNum[s] == '+')
    {
        _sign = (strNum[s++] == '-') ? 1 : 0;

        if (s == size)
        {
            // std::cout << "Error: isn't digit:\t";
            throw std::invalid_argument("ERROR isn't digit");
        }

        if (_sign == 1 && strNum[s] == '0')
        {
            throw std::invalid_argument("ERROR zero cannot be negative");
        }
    }

    if (s == size)
    {
        // std::cout << "Error: isn't digit:\t";
        throw std::invalid_argument("ERROR isn't digit");
    }

    if (strNum[s] == '0' && strNum[s + 1] == '0')
    {
        throw std::invalid_argument("ERROR 00* isn't digit");
    }

    int j = s;
    while (j < size)
    {
        if (!is_num(strNum[j++]))
        {
            std::cout << "Error: isn't digit:\t";
            throw("ERROR isn't digit");
        }
    }

    bool flag = 0;
    if ((j - s) % 2 == 1)
    {
        flag = 1; // in this case the number of digits is odd and the first digit must be considered separately
        ++s;
    }

    for (int i = j - 1; i >= s; i -= 2)
    {
        _str.push_back((strNum[i] - '0') + 10 * (strNum[i - 1] - '0'));
    }

    if (flag)
    {
        _str.push_back((strNum[--s] - '0')); // consider separately
    }
}

bool BigInt::is_num(char ch) const
{
    return (ch >= '0' && ch <= '9');
}

namespace std
{
    void swap(BigInt &a, BigInt &b)
    {
        a.swap(b);
    }
}
