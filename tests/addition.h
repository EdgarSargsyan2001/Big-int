#include <iostream>
#include "../BigInt.h"

void test_addition()
{
    std::cout << "\033[32m" << " ==== test_addition ====" << "\033[0m \n";

    BigInt a = 0;
    BigInt b = 0;

    if (a + b == 0) // test_addition_1
    {
        std::cout << "a + b == 0: addition 0 + 0 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
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
    }

    a = "777";
    b = -77;
    if (a + b == 700) // test_addition_8
    {
        std::cout << "a + b == 0: addition 777 + (-77) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_8 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = "-777";
    b = 77;
    if (a + b == -700) // test_addition_9
    {
        std::cout << "a + b == 0: addition -777 + 77 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_addition_9 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }
}