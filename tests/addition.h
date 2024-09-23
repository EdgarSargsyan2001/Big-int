#include <iostream>
#include "../BigInt.h"
#include <cassert>
#include <random>

void test_2();
void test_3(int &);

void test_addition()
{
    std::cout << "\033[32m" << " ==== test_addition ====" << "\033[0m \n";
    int faild_count = 0;

    BigInt a = 0;
    BigInt b = 0;

    if (a + b == 0) // test_addition_1
    {
        std::cout << "a + b == 0: addition 0 + 0 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 44;
    b = "9999999";
    if (a + b == 10000043) // test_addition_2
    {
        std::cout << "a + b == 10000043: addition \"9999999\" + 44 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 999;
    b = "999";
    if (a + b == 1998) // test_addition_3
    {
        std::cout << "a + b == 1998: addition \"999\" + 999 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -999;
    b = "-999";
    if (a + b == -1998) // test_addition_4
    {
        std::cout << "a + b == -1998: addition \"-999\" + -999 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    BigInt c("-123456789012345678901234");
    BigInt d("-9876543210987654");
    BigInt result = c + d;
    if (result == "-123456798888888889888888") // test_addition_5
    {
        std::cout << "a + b == -123456798888888889888888: addition " << c << " + " << d << "\033[32m" << " OK " << "\033[0m\n";
        // (d + c).print();
    }
    else
    {
        std::cout << "test_addition_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 44;
    a += a;      // a.operator+=(a)
    if (a == 88) // test_addition_98
    {
        std::cout << "a += a == 88: addition 44 + 44 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_98 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 44;
    (a += a) += a; // ( a.operator+=(a) ).operator+=(a)
    if (a == 176)  // test_addition_98
    {
        std::cout << "(a += a) += a == 176: addition 44 + 44 + 44 + 44 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_99 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    //
    a = -47;
    b = 47;
    BigInt r = a + b;
    // std::cout << r << '\n';
    if (r == 0) // test_addition_6
    {
        std::cout << "a + b == 0: addition -47 + 47 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_6 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "47";
    b = -47;
    r = a + b;
    if (r == 0) // test_addition_7
    {
        std::cout << "a + b == 0: addition 47 + (-47) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_7 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "7777";
    b = -77;
    if (a + b == 7700) // test_addition_8
    {
        std::cout << "a + b == 7700: addition 7777 + (-77) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_8 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "-7777";
    b = 77;
    if (a + b == -7700) // test_addition_9
    {
        std::cout << "a + b == -7700: addition -7777 + 77 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_9 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "-57";
    b = 9876543;
    if (a + b == 9876486) // test_addition_10
    {
        std::cout << "a + b == 9876486: addition -57 + 9876543 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_10 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a + b == 9876486) // test_addition_11
    {
        std::cout << "a + b == -7700: addition 9876543 + (-57) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_11 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -10000000;
    b = 5;
    if (a + b == -9999995) // test_addition_12
    {
        std::cout << "a + b == -9999995: addition -10000000 + 5 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_12 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a + b == -9999995) // test_addition_13
    {
        std::cout << "a + b == -9999995: addition 5 + (-10000000) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_13 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    // test_2();
    test_3(faild_count);

    if (faild_count)
    {
        std::cout << "\033[31m" << "faild count is " << faild_count << "\033[0m\n";
    }
}

void test_3(int &faild_count)
{
    std::tuple<int, int> tests[] = {
        // test_addition_77

        {3, 1234567},
        {-57, 9876543},
        {-2, 12345678},
        {9, 3456789},
        {-846, 234567},
        {1, 7654321},
        {-10234, 9876543},
        {789, 54321},
        {-123, 4567890},
        {5, -10000000}};

    for (const auto &test : tests)
    {
        int firstNum = std::get<0>(test);
        int secondNum = std::get<1>(test);

        BigInt a = firstNum;
        BigInt b = secondNum;

        if ((a + b) != (firstNum + secondNum))
        {
            std::cout << "real num1: " << firstNum << '\n';
            std::cout << "real num2: " << secondNum << '\n';
            std::cout << "BigInt num1: " << a << '\n';
            std::cout << "BigInt num2: " << b << '\n';

            std::cout << "a+b = " << a + b << "  " << " test_addition_77 " << "\033[31m" << " FAILD " << "\033[0m\n";
            faild_count++;
        }
    }
}

void test_2()
{
    // Addition test with 1-digit numbers
    std::cout << "Addition with 1-digit numbers:\n";
    assert((BigInt(5) + BigInt(3)) == BigInt(8));
    assert((BigInt(-5) + BigInt(-3)) == BigInt(-8));
    assert((BigInt(0) + BigInt(7)) == BigInt(7));

    // Addition test with 2-digit numbers
    std::cout << "\nAddition with 2-digit numbers:\n";
    assert((BigInt(15) + BigInt(12)) == BigInt(27));
    assert((BigInt(-27) + BigInt(14)) == BigInt(-13));
    assert((BigInt(45) + BigInt(0)) == BigInt(45));

    // Addition test with 5-digit numbers
    std::cout << "\nAddition with 5-digit numbers:\n";
    assert((BigInt(12345) + BigInt(6789)) == BigInt(19134));
    assert((BigInt(-98765) + BigInt(43210)) == BigInt(-55555));
    assert((BigInt(11111) + BigInt(99999)) == BigInt(111110));

    // Addition test with 20-digit numbers
    std::cout << "\nAddition with 20-digit numbers:\n";
    assert((BigInt("12345678901234567890") + BigInt("9876543210987654321")) == BigInt("22222222112222222211"));
    assert((BigInt("-98765432101234567890") + BigInt("12345678901234567890")) == BigInt("-86419753200000000000"));
    assert((BigInt("10000000000000000000") + BigInt("9999999999999999999")) == BigInt("19999999999999999999"));

    std::cout << "All tests passed!" << std::endl;
}

void test_addition_random(int start, int end, int count = 10)
{
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(start, end);
    int faild_count = 0;

    for (int i = 0; i < count; ++i)
    {
        int num1 = distr(gen);
        int num2 = distr(gen);
        BigInt a = num1;
        BigInt b = num2;
        BigInt r = (a + b);
        if (r != (num1 + num2))
        {
            std::cout << "\033[31m" << "test_addition_random Faild" << "\033[0m\n";
            std::cout << "real num1: " << num1 << "\n";
            std::cout << "real num2: " << num2 << "\n";
            std::cout << "num1 + num2 = " << num1 + num2 << '\n';
            std::cout << "BigInt a: " << a << "\n";
            std::cout << "BigInt b: " << b << "\n";
            std::cout << "a + b = " << r << '\n';
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