#include <iostream>
#include "../BigInt.h"

void test_subtraction()
{
    std::cout << "\033[32m" << " ==== test_subtraction ====" << "\033[0m \n";

    BigInt a = -88;
    BigInt b = 99;
    if (a - b == -187) // test_subtraction_1
    {
        std::cout << "a + b == -187: subtraction -88 - 99 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 88;
    b = -99;
    if (a - b == 187) // test_subtraction_2
    {
        std::cout << "a + b == 187: subtraction 88 - (-99) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 99;
    b = -88;

    if (a - b == 187) // test_subtraction_3
    {
        std::cout << "a + b == 187: subtraction 99 - (-88) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::swap(a, b);
    if (a - b == -187) // test_subtraction_4
    {
        std::cout << "a + b == 187: subtraction -99 - 88 :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }
}
