#include <iostream>
#include "../BigInt.h"
#include <cassert>
#include <random>

void test_multiplication()
{
    std::cout << "\033[32m" << " ==== test_multiplication ====" << "\033[0m \n";
    int faild_count = 0;

    BigInt a = 17194311;
    BigInt b = 1042;
    BigInt r = a * b;

    if (r == "17916472062") // test_1
    {
        std::cout << "a * b == 17916472062: 17194311 * 1042 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a.swap(b);
    r = a * b;
    if (r == "17916472062")
    {
        std::cout << "a * b == 17916472062: 1042 * 17194311 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 14789;
    b = 787889;
    r = a * b;
    if (r == "11652090421")
    {
        std::cout << "a * b == 11652090421: 14789 * 787889 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    

    a = -14789;
    b = 787889;
    r = a * b;

    if (r == "-11652090421")
    {
        std::cout << "a * b == 11652090421: -14789 * 787889 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a.swap(b);
    r = a * b;
    if (r == "-11652090421")
    {
        std::cout << "a * b == 11652090421: 787889 * -14789" << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }
    

    a = -14789;
    b = -787889;
    r = a * b;

    if (r == "11652090421")
    {
        std::cout << "a * b == 11652090421: -787889 * -14789" << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_6 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }
    

    a = 0;
    r = a * b;
    if (r == "0")
    {
        std::cout << "a * b == 11652090421: 0 * -14789" << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_7 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }
    
    a.swap(b);
    r = a * b;
    if (r == "0")
    {
        std::cout << "a * b == 11652090421: -14789 * 0" << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_8 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }
    
    a = 55;
    a *= a;
    if (a == "3025")
    {
        std::cout << "a *= a == 3025: 55 * 55 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_9 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }
   
    a *= a;
    if (a == "9150625")
    {
        std::cout << "a *= a == 9150625: 3025 * 3025 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_10 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    if (faild_count)
    {
        std::cout << "\033[31m" << "faild count is " << faild_count << "\033[0m\n";
    }
}

void test_multiplication_random(int start, int end, int count = 10)
{
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(start, end);
    int faild_count = 0;

    for (int i = 0; i < count; ++i)
    {
        int num1 = distr(gen);
        int num2 = distr(gen);
        BigInt a = num1;
        BigInt b = num2;
        BigInt r = (a * b);
        if (r != (num1 * num2))
        {
            std::cout << "\033[31m" << "test_multiplication_random Faild" << "\033[0m\n";
            std::cout << "real num1: " << num1 << "\n";
            std::cout << "real num2: " << num2 << "\n";
            std::cout << "num1 * num2 = " << num1 * num2 << '\n';
            std::cout << "BigInt a: " << a << "\n";
            std::cout << "BigInt b: " << b << "\n";
            std::cout << "a * b = " << r << '\n';
            faild_count++;
        }
    }

    if (faild_count)
    {
        std::cout << "multiplication random test passed " << count << "/" << count - faild_count << '\n';
    }
    else
    {
        std::cout << "\033[32m" << "multiplication random test passed " << count << "/" << count << "\033[0m \n";
    }
}
