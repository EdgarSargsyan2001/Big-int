#include <iostream>
#include <random>
#include "../BigInt.h"

void test_get_num()
{
    std::cout << "\033[32m" << " ==== test_get_num ====" << "\033[0m \n";
    int faild_count = 0;

    BigInt a = 0;
    if (a.get_num() == "0") // test_addition_1
    {
        std::cout << "a.get_num() == \"0\": " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -123;
    std::string r = a.get_num();
    std::cout << "size = " << r.size() << "  " << r << '\n';
    if (r == "-123") // test_addition_2
    {
        std::cout << "a.get_num() == \"-123\": " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -1234;
    if (a.get_num() == "-1234") // test_addition_3
    {
        std::cout << "a.get_num() == \"-1234\": " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "1234567897895489";
    if (a.get_num() == "1234567897895489") // test_addition_4
    {
        std::cout << "a.get_num() == \"1234567897895489\": " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "-1234567897895489";
    if (a.get_num() == "-1234567897895489") // test_addition_5
    {
        std::cout << "a.get_num() == \"-1234567897895489\": " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    if (faild_count)
    {
        std::cout << "\033[31m" << "faild count is " << faild_count << "\033[0m\n";
    }
}

void test_get_num_random(int start, int end, int count = 10)
{
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(start, end);
    int faild_count = 0;

    for (int i = 0; i < count; ++i)
    {
        int num1 = distr(gen);
        BigInt a = num1;
        std::string r = a.get_num();
        if (r != std::to_string(num1))
        {
            std::cout << "\033[31m" << "test_get_num_random Faild" << "\033[0m\n";
            std::cout << "real num1: " << num1 << "\n";
            std::cout << " ans: " << std::to_string(num1) << '\n';
            std::cout << "BigInt a: " << a << "\n";
            std::cout << "" << r << '\n';
            faild_count++;
        }
    }

    if (faild_count)
    {
        std::cout << "addition random test passed " << count << "/" << count - faild_count << '\n';
    }
    else
    {
        std::cout << "\033[32m" << "addition random test passed " << count << "/" << count << "\033[0m \n";
    }
}