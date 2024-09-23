#ifndef BigInt_H
#define BigInt_H
#include <iostream>
#include <string>
#include <algorithm>

class BigInt;
void swap(BigInt &a, BigInt &b); // global swap

// =========== global arithmetic operation ===========
const BigInt operator+(const BigInt &a, const BigInt &b);
const BigInt operator-(const BigInt &a, const BigInt &b);

class BigInt
{
public:
    // =========== friend conditional operation ===========
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);

    // =========== friend log operator ===========
    friend std::ostream &operator<<(std::ostream &os, const BigInt &a);

public:
    struct ABS_tag // for copying abs
    {
    };

public:
    BigInt(int num = 0);
    BigInt(const std::string &str);
    BigInt(const char *str);
    BigInt(const BigInt &a, BigInt::ABS_tag);
    BigInt(char ch) = delete;

    // ===========  methods ===========
    const BigInt abs() const;
    void print() const;
    void swap(BigInt &b);

    // =========== arithmetic operation ===========
    BigInt &operator+=(const BigInt &b);
    BigInt &operator-=(const BigInt &b);

private:
    // =========== helpers ===========
    bool is_num(char ch) const;
    void parse(const std::string &strNum);

private:
    std::string _str;
    bool _sign = 0; // 0 is positive
};

#endif