#include <iostream>
#include "../BigInt.h"

void test_creation()
{
    std::cout << "\033[32m" << " ==== test_creation ====" << "\033[0m \n";

    BigInt bignum;
    if (bignum == 0) // test_creation_1
    {
        std::cout << "bignum == 0: default valuse is 0 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_creation_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    BigInt a = "47"; // a("47")     // create BigInt from char is deleted
    if (a == 47)     // test_creation_2
    {
        std::cout << "a == 47: create bigint from const cahr * " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_creation_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::string n = "447";
    BigInt b = n;
    if (b == 447) // test_creation_3
    {
        std::cout << "b == 447: create bigint from std::string " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_creation_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    BigInt c = -777;
    if (c == -777) // test_creation_4
    {
        std::cout << "c == -777: create bigint from negative int " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_creation_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }
}
