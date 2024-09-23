#include <iostream>
#include "../BigInt.h"

void operator_small_test()
{
    std::cout << "\033[32m" << " ==== operator_small_test ====" << "\033[0m \n";

    BigInt a = 5;
    BigInt b = 999;
    if (a < b) // operator_small_test_1
    {
        std::cout << "a < b == true: operator< 5 < 9 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::swap(a, b);
    if (a < b == 0) // operator_small_test_2
    {
        std::cout << "a < b == false: operator< 9 < 5 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = -5;
    b = -111;
    if (a < b == 0) // operator_small_test_3
    {
        std::cout << "a < b == false: operator< -9 < -111 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::swap(a, b);
    if (a < b) // operator_small_test_4
    {
        std::cout << "a < b == true: operator< -111 < -9 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 5;
    b = -111;
    if (a < b == 0) // operator_small_test_5
    {
        std::cout << "a < b == false: operator< 5 < -111 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::swap(a, b);
    if (a < b) // operator_small_test_6
    {
        std::cout << "a < b == true: operator< -111 < 5 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_6 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 44;
    b = 45;
    if (a < b) // operator_small_test_7
    {
        std::cout << "a < b == true: operator< 44 < 45 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_7 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::swap(a, b);
    if (a < b == 0) // operator_small_test_8
    {
        std::cout << "a < b == false: operator< 45 < 44 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_8 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = -44;
    b = -45;
    if (a < b == 0) // operator_small_test_9
    {
        std::cout << "a < b == false: operator< -44 < -45 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_9 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    std::swap(a, b);
    if (a < b) // operator_small_test_10
    {
        std::cout << "a < b == true: operator< -45 < -44 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_10 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 44;
    b = 44;
    if (a < b == 0) // operator_small_test_11
    {
        std::cout << "a < b == false: operator< 44 < 44 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_11 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 0;
    b = 0;
    if (a < b == 0) // operator_small_test_12
    {
        std::cout << "a < b == false: operator< 0 < 0 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_12 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 994477;
    b = 994577;
    if (a < b) // operator_small_test_13
    {
        std::cout << "a < b == true: operator< 994477 < 994577 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_13 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }

    a = 9845774;
    b = 9945774;
    if (a < b) // operator_small_test_14
    {
        std::cout << "a < b == true: operator< 9845774 < 9945774 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "operator_small_test_14 " << "\033[31m" << " FAILD " << "\033[0m\n";
    }
}