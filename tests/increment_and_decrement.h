#include <iostream>
#include "../BigInt.h"

void increment_and_decrement(int num1 = -100, int num2 = -100, int count = 201)
{
    std::cout << "\033[32m" << " ==== increment_and_decrement ====" << "\033[0m \n";
    int faild_count = 0;

    BigInt a = num1;
    for (int i = 0; i < count; ++i)
    {
        if (++a != ++num1)
        {
            std::cout << "\033[31m" << "increment test Faild" << "\033[0m\n";
            std::cout << "real num1: " << num1 << "\n";
            std::cout << "BigInt a: " << a << "\n";
            faild_count++;
        }
    }

    if (faild_count)
    {
        std::cout << "increment test passed " << count << "/" << count - faild_count << '\n';
    }
    else
    {
        std::cout << "\033[32m" << "increment test passed " << count << "/" << count << "\033[0m \n";
    }

    faild_count = 0;
    a = num2;
    for (int i = 0; i < count; ++i)
    {
        if (--a != --num2)
        {
            std::cout << "\033[31m" << "decrement test Faild" << "\033[0m\n";
            std::cout << "real num1: " << num2 << "\n";
            std::cout << "BigInt a: " << a << "\n";
            faild_count++;
        }
    }

    if (faild_count)
    {
        std::cout << "decrement test passed " << count << "/" << count - faild_count << '\n';
    }
    else
    {
        std::cout << "\033[32m" << "decrement test passed " << count << "/" << count << "\033[0m \n";
    }
}