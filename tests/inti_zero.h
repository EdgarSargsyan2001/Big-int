#include <iostream>
#include "../BigInt.h"

void test_zero()
{
    std::cout << "\033[32m" << " ==== test_zero ====" << "\033[0m \n";

    BigInt bignum = 0;
    if (bignum == 0) // test_zero_1
    {
        std::cout << "bignum == 0: inti BigInt from 0(int) value " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_zero_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    BigInt a = "0";
    if (a == 0) // test_zero_2
    {
        std::cout << "a == 0: inti BigInt from 0(const char* or std::string) value " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_zero_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    BigInt b = "+0";
    if (b == 0) // test_zero_4
    {
        std::cout << "b == 0: inti BigInt from +0 (const char* or std::string) value " << "\033[32m" << " OK " << "\033[0m \n";
    }

    else
    {
        std::cout << "test_zero_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    try // test_zero_3
    {
        BigInt b = "-0";
        std::cout << "test_zero_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }
    catch (const std::invalid_argument &e)
    {
        // std::cout << "Caught an exception: " << e.what() << std::endl;
        std::cout << "inti BigInt from -0 (const char* or std::string) value throw error" << "\033[32m" << " OK " << "\033[0m \n";
    }

    try // test_zero_5
    {
        BigInt b = "000";
        std::cout << "test_zero_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }
    catch (const std::invalid_argument &e)
    {
        // std::cout << "Caught an exception: " << e.what() << std::endl;
        std::cout << "inti BigInt from 000 (const char* or std::string) value throw error" << "\033[32m" << " OK " << "\033[0m \n";
    }
}