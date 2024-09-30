#ifndef BigInt_H
#define BigInt_H
#include <iostream>
#include <string>
#include <algorithm>

class BigInt;

void swap(BigInt &a, BigInt &b); // O(1) // global swap

// =========== global operator ===========
std::ostream &operator<<(std::ostream &os, const BigInt &a); // O(N)

// =========== global arithmetic operation ===========
const BigInt operator+(const BigInt &a, const BigInt &b); // O(max(N, M))
const BigInt operator-(const BigInt &a, const BigInt &b); // O(max(N, M))
const BigInt operator*(const BigInt &a, const BigInt &b); // O(N * M)
const BigInt operator/(const BigInt &a, const BigInt &b); // ??

class BigInt
{
public:
    // =========== friend conditional operation ===========
    friend bool operator==(const BigInt &a, const BigInt &b); // O(N)
    friend bool operator!=(const BigInt &a, const BigInt &b); // O(N)
    friend bool operator<(const BigInt &a, const BigInt &b);  // O(N) // Best-case-> O(1)
    friend bool operator<=(const BigInt &a, const BigInt &b); // O(N) // Best-case-> O(1)

public:
    BigInt(int num = 0);            // O(N) where N is the size of the member string (_str)
    BigInt(const std::string &str); // O(N)
    BigInt(const char *str);        // O(N)
    BigInt(char ch) = delete;

    // ===========  methods ===========
    const BigInt abs() const;          // O(N)
    const std::string get_num() const; // O(N)
    bool is_even() const;              // O(1)
    void swap(BigInt &b);              // O(1)
    void mul_base();                   // O(N) // base is 100
    void print() const;

    // =========== arithmetic operation ===========
    BigInt &operator+=(const BigInt &b); // O(max(N, M))
    BigInt &operator-=(const BigInt &b); // O(max(N, M))
    BigInt &operator++();                // O(N) prefix increment
    BigInt &operator--();                // O(N) prefix decrement
    BigInt &operator*=(const BigInt &b); // O(N * M)
    BigInt &operator/=(const BigInt &b); //

private:
    // =========== helpers ===========
    struct ABS_tag // for copying abs
    {
    };
    BigInt(const BigInt &a, BigInt::ABS_tag); // O(N) //  for copying abs

    bool is_num(char ch) const;            // O(1)
    void parse(const std::string &strNum); // O(K)  where K is the size of the string passed

private:
    std::string _str;
    bool _sign = 0; // 0 is positive
};

#endif