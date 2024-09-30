#include "Bigint.h"
#include <utility> // For std::swap
#include <iostream>
#include <unordered_map>

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
    return BigInt(a) += b; // it will be subject to RVO
}

const BigInt operator-(const BigInt &a, const BigInt &b)
{
    return BigInt(a) -= b; // it will be subject to RVO
}

const BigInt operator*(const BigInt &a, const BigInt &b)
{
    return BigInt(a) *= b; // it will be subject to RVO
}

const BigInt operator/(const BigInt &a, const BigInt &b)
{
    return BigInt(a) /= b; // it will be subject to RVO
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

bool operator<=(const BigInt &a, const BigInt &b)
{
    return ((a == b) || (a < b));
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

bool BigInt::is_even() const
{
    return (_str.front() & 1) == 0;
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
    if (b == BigInt(0) || *this == BigInt(0))
    {
        return *this = 0;
    }

    if (b == BigInt(1))
    {
        return *this;
    }

    if (this == &b)
    {
        BigInt newB(b);
        return *this *= newB;
    }

    BigInt a(*this);
    *this = 0;

    std::size_t l1 = a._str.size();
    std::size_t l2 = b._str.size();

    bool bigger = 0;
    if (l1 < l2)
    {
        bigger = 1;
        std::swap(l1, l2);
    }

    std::unordered_map<char, std::string> memo_mul;
    for (int i = 0; i < l2; ++i)
    {
        short op1 = bigger ? a._str[i] : b._str[i];
        if (op1 == 0)
        {
            continue;
        }

        if (memo_mul.count(op1) == 0)
        {
            short carry = 0;
            std::string m;
            for (int j = 0; j < l1; ++j)
            {
                short op2 = bigger ? b._str[j] : a._str[j];
                op2 *= op1;
                op2 += carry;

                carry = (op2 / 100);
                m.push_back(op2 % 100);
            }
            if (carry)
            {
                m.push_back(carry);
            }
            memo_mul.emplace(op1, m);
        }

        BigInt x;
        x._str = std::string(i, '\0') + memo_mul[op1];
        *this += x;
    }

    _sign = a._sign != b._sign;

    return *this;
}

BigInt &BigInt::operator/=(const BigInt &b)
{
    if (b == 0)
    {
        throw std::invalid_argument("ERROR dividing by 0");
    }
    if (this == &b)
    {
        return *this = BigInt(1);
    }
    if (b == BigInt(1) || b == BigInt(-1))
    {
        _sign = b._sign;
        return *this;
    }

    BigInt b_abs = b.abs();
    BigInt this_abs = this->abs();

    if (b_abs == this_abs)
    {
        if (_sign != b._sign)
        {
            return *this = BigInt(-1);
        }
        return *this = BigInt(1);
    }

    if (this_abs < b_abs)
    {
        return *this = BigInt(0);
    }

    _str = ""; // clear this _str. I have this copy

    BigInt &divided = this_abs;
    BigInt &divisor = b_abs;

    std::size_t l2 = divisor._str.size();

    std::unordered_map<char, BigInt> memo_mul; // memorization for multiplication

    while (divisor <= divided)
    {
        std::size_t l1 = divided._str.size();

        BigInt diff;
        diff._str = divided._str.substr(l1 - l2);

        if (diff < divisor)
        {
            diff._str.insert(diff._str.begin(), divided._str[l1 - (l2 + 1)]);
        }

        std::size_t diff_size = diff._str.size();

        int low = 1;
        int high = 100;
        BigInt result = 0;

        while (low <= high) // log (100) => 7
        {
            short mid = low + (high - low) / 2;

            if (memo_mul.count(mid) == 0)
            {
                memo_mul.emplace(mid, mid * divisor);
            }

            if (memo_mul[mid] <= diff)
            {
                result = memo_mul[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        diff -= result;
        _str.insert(_str.begin(), high);

        for (auto it = diff._str.rbegin(); it != diff._str.rend() && *it == 0; ++it) // delete leading zeros
        {
            diff._str.pop_back();
        }

        int start = l1 - diff_size - 1;
        while (divided._str[start] == 0 && diff._str.empty() && start >= 0)
        {
            this->mul_base();
            --start;
        }

        BigInt new_divided;
        new_divided._str = diff._str;

        for (int i = start; i >= 0; --i)
        {
            new_divided._str.insert(new_divided._str.begin(), divided._str[i]);
            if (new_divided < divisor)
            {
                this->mul_base();
            }
        }

        divided = new_divided;
    }

    _sign = _sign != b._sign;
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

// bool operator>=(BigInt &x) const
// {
//     return ((*this == x) || (*this > x));
// }
