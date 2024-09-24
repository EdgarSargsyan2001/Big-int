#ifndef BigInt_H
#define BigInt_H
#include <iostream>
#include <string>
#include <algorithm>

class BigInt;

void swap(BigInt &a, BigInt &b); // global swap

// =========== global operator ===========
std::ostream &operator<<(std::ostream &os, const BigInt &a);

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

public:
    BigInt(int num = 0);
    BigInt(const std::string &str);
    BigInt(const char *str);
    BigInt(char ch) = delete;

    // ===========  methods ===========
    const BigInt abs() const;
    const std::string get_num() const;
    void print() const;
    void swap(BigInt &b);

    // =========== arithmetic operation ===========
    BigInt &operator+=(const BigInt &b);
    BigInt &operator-=(const BigInt &b);
    BigInt &operator++(); // prefix increment
    BigInt &operator--(); // prefix decrement

private:
    // =========== helpers ===========
    struct ABS_tag // for copying abs
    {
    };
    BigInt(const BigInt &a, BigInt::ABS_tag); //  for copying abs

    bool is_num(char ch) const;
    void parse(const std::string &strNum);

private:
    std::string _str;
    bool _sign = 0; // 0 is positive
};

#endif