#ifndef BigInt_H
#define BigInt_H

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

    friend const BigInt operator+(const BigInt &a, const BigInt &b);
    friend const BigInt operator-(const BigInt &a, const BigInt &b);

    void swap(BigInt &b) 
    {
        using std::swap;
        swap(_str, b._str);
        swap(_sign, b._sign);
    }

public:
    BigInt(int num = 0);
    BigInt(const std::string &str);
    BigInt(const char *str);

    BigInt(char ch) = delete;

    // =========== arithmetic operation ===========
    BigInt &operator+=(const BigInt &b);

    // =========== conditional operation ===========
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);

    // =========== operators ===========
    friend std::ostream &operator<<(std::ostream &os, const BigInt &a);

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
    bool _sign = 0; // 0 is positive
};

#endif