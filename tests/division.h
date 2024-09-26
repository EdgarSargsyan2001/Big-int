
#include <iostream>
#include "../BigInt.h"
#include <random>

void test_division()
{
    std::cout << "\033[32m" << " ==== test_multiplication ====" << "\033[0m \n";
    int faild_count = 0;

    BigInt a = 40040;
    BigInt b = 4;
    BigInt r = a / b;
    if (r == 10010)
    {
        std::cout << "a / b == 10010: 40040 / 4 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 400004;
    b = 4;
    r = a / b;
    if (r == 100001)
    {
        std::cout << "a / b == 100001: 400004 / 4 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 44;
    b = 100;
    r = a / b;
    // std::cout << "r= " << r << '\n';
    if (r == 0)
    {
        std::cout << "a / b == 0: 44 / 100 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -44;
    b = 100;
    r = a / b;
    if (r == 0)
    {
        std::cout << "a / b == 0: -44 / 100 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -44;
    b = -100;
    r = a / b;
    if (r == 0)
    {
        std::cout << "a / b == 0: -44 / -100 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 44;
    b = -100;
    r = a / b;
    if (r == 0)
    {
        std::cout << "a / b == 0: 44 / -100 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_6 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -4488;
    b = 4488;
    r = a / b;
    if (r == -1)
    {
        std::cout << "a / b == -1: -4488 / 4488 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_7 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -4488;
    b = -4488;
    r = a / b;
    if (r == 1)
    {
        std::cout << "a / b == 1: -4488 / -4488 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_8 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 192769459;
    b = 412;
    r = a / b;
    if (r == 467887)
    {
        std::cout << "a / b == 467887: 192769459 / 412 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_9 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -4737;
    b = -3614;
    r = a / b;
    if (r == 1)
    {
        std::cout << "a / b == 1: -4737 / -3614 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_10 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -7346;
    b = 4638;
    r = a / b;
    if (r == -1)
    {
        std::cout << "a / b == -1: -7346 / 4638 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_11 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -3741;
    b = 972;
    r = a / b;
    if (r == -3)
    {
        std::cout << "a / b == -3: -3741 / 972 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_12 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 9767;
    b = 84;
    r = a / b;
    std::cout << "r= " << r << '\n';
    if (r == 116)
    {
        std::cout << "a / b == 116: 9767 / 84 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_13 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 6406;
    b = -16;
    r = a / b;
    if (r == -400)
    {
        std::cout << "a / b == -400: 6406 / -16 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_14 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 7290;
    b = 1215;
    r = a / b;
    if (r == 6)
    {
        std::cout << "a / b == 6: 7290 / 1215 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_15 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    if (faild_count)
    {
        std::cout << "\033[31m" << "faild count is " << faild_count << "\033[0m\n";
    }
}

void test_division_random(int start, int end, int count = 10)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(start, end);
    int faild_count = 0;

    for (int i = 0; i < count; ++i)
    {
        int num1 = distr(gen);
        int num2 = distr(gen);
        if (num2 == 0)
        {
            continue;
        }
        BigInt a = num1;
        BigInt b = num2;
        BigInt r;
        try
        {
            r = (a / b);
        }
        catch (std::error_code)
        {
        }
        if (r != (num1 / num2))
        {
            std::cout << "\033[31m" << "test_division_random Faild" << "\033[0m\n";
            std::cout << "real num1: " << num1 << "\n";
            std::cout << "real num2: " << num2 << "\n";
            std::cout << "num1 / num2 = " << num1 / num2 << '\n';
            std::cout << "BigInt a: " << a << "\n";
            std::cout << "BigInt b: " << b << "\n";
            std::cout << "a / b = " << r << '\n';
            faild_count++;
        }
    }

    if (faild_count)
    {
        std::cout << "division random test passed " << count << "/" << count - faild_count << '\n';
    }
    else
    {
        std::cout << "\033[32m" << "division random test passed " << count << "/" << count << "\033[0m \n";
    }
}
