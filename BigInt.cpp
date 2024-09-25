#include "Bigint.h"
#include <utility> // For std::swap
#include <iostream>

void swap(BigInt &a, BigInt &b)
{
    // std::cout << "swap\n";
    a.swap(b);
}

// =========== global operator ===========
std::ostream &operator<<(std::ostream &os, const BigInt &a)
{
    os << a.get_num();
    return os;
}

// =========== global arithmetic operation ===========
const BigInt operator+(const BigInt &a, const BigInt &b)
{
    return BigInt(a) += b;
}

const BigInt operator-(const BigInt &a, const BigInt &b)
{
    return BigInt(a) -= b;
}

const BigInt operator*(const BigInt &a, const BigInt &b)
{
    return BigInt(a) *= b;
}

// =========== ctors ===========
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

BigInt::BigInt(const BigInt &a, BigInt::ABS_tag)
{
    // std::cout << "copy abs ctor\n";
    _str = a._str;
}

// =========== friend conditional operation ===========
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
    if (a._sign == b._sign)
    {
        std::size_t s1 = a._str.size();
        std::size_t s2 = b._str.size();
        if (s1 == s2)
        {
            for (int i = s1 - 1; i >= 0; --i)
            {
                if (a._str[i] != b._str[i])
                {
                    return a._sign ? a._str[i] > b._str[i] : a._str[i] < b._str[i];
                }
            }
        }
        else
        {
            return a._sign ? s1 > s2 : s1 < s2;
        }
    }

    return a._sign; //  (a._sign == 1) ? true : false
}

// =========== const methods ===========
const BigInt BigInt::abs() const
{
    return BigInt(*this, BigInt::ABS_tag()); // abs copy
}

const std::string BigInt::get_num() const
{
    std::string str;
    if (_sign)
    {
        str.push_back('-');
    }

    int len = _str.size();
    str.reserve(len * 2 + 1);

    str += std::to_string(_str[len - 1]);
    for (int i = len - 2; i >= 0; i--)
    {

        if (_str[i] < 10)
        {
            str += "0";
        }
        str += std::to_string(_str[i]);
    }
    return str;
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

// =========== methods ===========
void BigInt::swap(BigInt &b)
{
    using std::swap;
    _str.swap(b._str);
    swap(_sign, b._sign);
}

void BigInt::mul_base() // base is 100
{
    if (_str[0] != 0 || _str.size() != 1)
    {
        _str.insert(_str.begin(), 0);
    }
}

// =========== arithmetic operation ===========
BigInt &BigInt::operator+=(const BigInt &b)
{

    if (this == &b)
    {
        BigInt newB(b);
        return *this += newB;
    }

    if (_sign == 1 && b._sign == 0)
    {
        BigInt tmp(this->abs());
        *this = b;
        *this -= tmp;
        return *this;
    }

    if (_sign == 0 && b._sign == 1)
    {
        *this -= b.abs();
        return *this;
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
    {
        _str.push_back(carry);
    }

    return *this;
}

BigInt &BigInt::operator-=(const BigInt &b)
{
    if (this == &b)
    {
        BigInt newB(b);
        return *this -= newB;
    }

    if (_sign == 1 && b._sign == 0)
    {
        _sign = 0;
        *this += b;
        _sign = 1;
        return *this;
    }

    if (_sign == 0 && b._sign == 1)
    {
        BigInt tmp(b);
        tmp._sign = 0;
        *this += tmp;
        return *this;
    }

    std::string s1_bigger = _str;
    std::string s2_smoller = b._str;

    if (this->abs() < b.abs())
    {
        _sign = !b._sign;
        std::swap(s1_bigger, s2_smoller);
    }

    _str = "";
    std::size_t l1 = s1_bigger.size();
    std::size_t l2 = s2_smoller.size();

    short borrow = 0;
    int i = 0;
    while (i < l1 && i < l2)
    {
        short op1 = s1_bigger[i] - borrow;
        short op2 = s2_smoller[i];

        borrow = (op1 < op2) ? 1 : 0;
        short num = op1 - op2 + 100 * borrow;
        _str.push_back((num % 100));
        ++i;
    }

    while (i < l1)
    {
        short op1 = s1_bigger[i++] - borrow;
        borrow = (op1 < 0) ? 1 : 0;
        _str.push_back(((op1 + 100 * borrow) % 100));
    }

    _str.erase(_str.find_last_not_of('\0') + 1); // remove leading zeroes

    if (_str.empty())
    {
        *this = 0;
    }
    return *this;
}

BigInt &BigInt::operator++()
{
    *this += BigInt("1");
    return *this;
}
BigInt &BigInt::operator--()
{
    *this -= BigInt("1");
    return *this;
}

BigInt &BigInt::operator*=(const BigInt &b)
{
    if (b == 0 || *this == 0)
    {
        return *this = 0;
    }

    if (this == &b)
    {
        BigInt newB(b);
        return *this *= newB;
    }

    BigInt a(*this);
    _str = "";

    std::size_t l1 = a._str.size();
    std::size_t l2 = b._str.size();

    bool bigger = 0;
    if (l1 < l2)
    {
        bigger = 1;
        std::swap(l1, l2);
    }

    for (int i = 0; i < l2; ++i)
    {
        short op1 = bigger ? a._str[i] : b._str[i];

        BigInt x;
        x._str = "";

        short carry = 0;
        for (int l = 0; l < i; ++l)
        {
            x._str += '\0'; // increase by degrees of the base
        }

        for (int j = 0; j < l1; ++j)
        {
            short op2 = bigger ? b._str[j] : a._str[j];
            op2 *= op1;
            op2 += carry;

            carry = (op2 / 100);
            x._str.push_back(op2 % 100);
        }
        if (carry)
        {
            x._str.push_back(carry);
        }

        *this += x;
    }

    _sign = a._sign != b._sign;

    return *this;
}

// =========== helpers ===========
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

// bool operator>(BigInt &x) const
// {
//     if (sign != x.sign)
//         return sign < x.sign;

//     if (sign == 0)
//         return str.size() == x.str.size() ? (str > x.str) : (str.size() > x.str.size());

//     return str.size() == x.str.size() ? (str < x.str) : (str.size() < x.str.size());
// }
// bool operator<(BigInt &x) const
// {
//     return (!(*this == x) && !(*this > x));
// }
// bool operator>=(BigInt &x) const
// {
//     return ((*this == x) || (*this > x));
// }
// bool operator<=(BigInt &x) const
// {
//     return ((*this == x) || (*this < x));
// }

// BigInt operator*(BigInt &x)
// {
//     BigInt tmp = 0;
//     // x = tmp;
//     if (*this == 0 || x == 0)
//         return tmp;

//     BigInt k = 0;
//     BigInt op1 = x <= *this ? *this : x;
//     std::string st = x < *this ? x.str : str;
//     for (int i = 0; i < st.length(); i++)
//     {
//         for (int j = 0; j < st[i]; j++)
//             k = k + op1;
//         k << i;
//         // k.print();
//         tmp = tmp + k;
//         k = 0;
//     }
//     if (*this < 0 || x < 0)
//         tmp.sign = 1;
//     if (*this < 0 && x < 0)
//         tmp.sign = 0;

//     return tmp;
// }