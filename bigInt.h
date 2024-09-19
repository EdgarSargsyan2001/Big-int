#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInt
{
public:
    // friend BigInt operator*(BigInt &x, long long y)
    // {
    //     BigInt k = y;
    //     return x * k;
    // }

    // friend BigInt operator+(BigInt x, const int y)
    // {
    //     BigInt k = y;
    //     return x + k;
    // }
    // friend BigInt operator+(const int y, BigInt x)
    // {
    //     BigInt k = y;
    //     return x + k;
    // }
    // friend BigInt operator-(BigInt &x, const int y)
    // {
    //     BigInt k = y;
    //     return x - k;
    // }
    // friend BigInt operator-(const int y, BigInt &x)
    // {
    //     BigInt k = y;
    //     return k - x;
    // }
    // friend bool operator<=(const BigInt &x, const long long y)
    // {
    //     BigInt k = y;
    //     return x <= k;
    // }
    // friend bool operator>(const BigInt &x, const long long y)
    // {
    //     BigInt k = y;
    //     return x > k;
    // }
    // friend bool operator<(const BigInt &x, const long long y)
    // {
    //     BigInt k = y;
    //     return x < k;
    // }
    // friend bool operator<(const long long y, const BigInt &x)
    // {
    //     BigInt k = y;
    //     return x > k;
    // }
    // friend bool operator>=(const BigInt &x, const long long y)
    // {
    //     BigInt k = y;
    //     return x >= k;
    // }

public:
    BigInt(int num = 0);
    BigInt(const std::string &str);
    BigInt(const char *str);

    // operators

    friend std::ostream &operator<<(std::ostream &os, const BigInt &a);

    friend const BigInt operator+(const BigInt &a, const BigInt &b);

    // operator conditional
    bool operator==(const BigInt &x) const
    {
        return (_sign == x._sign && _str == x._str);
    }
    bool operator!=(const BigInt &x) const
    {
        return (_sign != x._sign || _str != x._str);
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

    // operator arithmetic operation
    // BigInt operator+(BigInt &x)
    // {
    //     BigInt tmp;
    //     if (*this < 0 && x >= 0)
    //     {
    //         tmp = *this;
    //         tmp.sign = 0;
    //         return (x - tmp);
    //     }
    //     if (x < 0 && *this >= 0)
    //     {
    //         tmp = x;
    //         tmp.sign = 0;
    //         return (*this - tmp);
    //     }

    //     if (sign == x.sign)
    //         tmp.sign = sign;

    //     short carry = 0;
    //     for (short i = 0, j = 0; i < str.size() || j < x.str.size();)
    //     {
    //         short op1 = i < str.size() ? (str[i++]) : 0;
    //         short op2 = j < x.str.size() ? (x.str[j++]) : 0;
    //         short num = (op1 + op2) + carry;
    //         carry = (num / 100);
    //         tmp.str.push_back((num % 100));
    //     }
    //     if (carry)
    //         tmp.str.push_back(carry);

    //     return tmp;
    // }

    // BigInt operator-(BigInt &x)
    // {
    //     BigInt tmp;
    //     if (*this <= 0 && x <= 0)
    //     {
    //         tmp = x;
    //         tmp.sign = 0;
    //         return tmp + *this;
    //     }
    //     if (*this <= 0 && x >= 0)
    //     {
    //         tmp = *this;
    //         tmp.sign = 0;
    //         tmp = tmp + x;
    //         tmp.sign = 1;
    //         return tmp;
    //     }
    //     if (*this >= 0 && x <= 0)
    //     {
    //         tmp = x;
    //         tmp.sign = 0;
    //         return tmp + *this;
    //     }
    //     std::string s1 = str, s2 = x.str;
    //     if (*this < x)
    //         s1.swap(s2), tmp.sign = 1;

    //     short borrow = 0;
    //     for (short i = 0, j = 0; i < s1.size() || j < s2.size();)
    //     {
    //         short op1 = i < s1.size() ? (s1[i++] - borrow) : (0 - borrow);
    //         short op2 = j < s2.size() ? (s2[j++]) : 0;
    //         borrow = (op1 < op2) ? 1 : 0;
    //         short num = op1 - op2 + 100 * borrow;
    //         tmp.str.push_back((num % 100));
    //     }

    //     while (*(tmp.str.end() - 1) == '\0' && !tmp.str.empty())
    //         tmp.str.pop_back();

    //     if (tmp.str.empty())
    //         tmp = 0;

    //     return tmp;
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

    // void operator<<(int y)
    // {
    //     if (y == 0)
    //         return;

    //     std::reverse(str.begin(), str.end());
    //     for (int i = 0; i < y; i++)
    //     {
    //         str.push_back(0);
    //     }
    //     std::reverse(str.begin(), str.end());
    // }

    void print() const;

private:
    bool is_num(char ch) const;
    void parse(const std::string &strNum);

private:
    std::string _str;
    bool _sign = 0;
};

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

// operator arithmetic operation
const BigInt operator+(const BigInt &a, const BigInt &b)
{
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

    BigInt tmp;
    tmp._str = "";
    if (a._sign == b._sign)
    {
        tmp._sign = a._sign; // or b._sign
    }

    int s1 = a._str.size();
    int s2 = b._str.size();
    int i = 0;

    short num = 0;
    short carry = 0;

    while (i < s1 && i < s2)
    {
        num = (a._str[i] + b._str[i]) + carry;
        carry = (num / 100);
        tmp._str.push_back((num % 100));
        ++i;
    }

    while (i < s1)
    {
        num = a._str[i++] + carry;
        carry = (num / 100);
        tmp._str.push_back((num % 100));
    }

    while (i < s2)
    {
        num = b._str[i++] + carry;
        carry = (num / 100);
        tmp._str.push_back((num % 100));
    }

    if (carry)
        tmp._str.push_back(carry);

    return tmp;
}

bool operator==(const BigInt &x, int y)
{
    return x == BigInt(y);
}

bool operator==(const BigInt &x,  BigInt &y)
{
    return x == y;
}

bool operator!=(const BigInt &x, int y)
{
    return x != BigInt(y);
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
    if (strNum[s] == '-' || strNum[s] == '+')
    {
        _sign = (strNum[s++] == '-') ? 1 : 0;
    }

    int size = strNum.length();
    if (s == size)
    {
        std::cout << "Error: isn't digit:\t";
        throw("ERROR isn't digit");
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
