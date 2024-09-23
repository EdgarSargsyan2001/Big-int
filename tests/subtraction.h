#include <iostream>
#include "../BigInt.h"
#include <cassert>

void testBigIntSubtraction();

void test_subtraction()
{
    std::cout << "\033[32m" << " ==== test_subtraction ====" << "\033[0m \n";
    int faild_count = 0;
    BigInt a = -88;
    BigInt b = 99;
    if (a - b == -187) // test_subtraction_1
    {
        std::cout << "a - b == -187: subtraction -88 - 99 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_1 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 88;
    b = -99;
    if (a - b == 187) // test_subtraction_2
    {
        std::cout << "a - b == 187: subtraction 88 - (-99) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_2 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 99;
    b = -88;

    if (a - b == 187) // test_subtraction_3
    {
        std::cout << "a - b == 187: subtraction 99 - (-88) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_3 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a - b == -187) // test_subtraction_4
    {
        std::cout << "a - b == 187: subtraction -99 - 88 :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_4 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 9;
    b = -888;
    if (a - b == 897) // test_subtraction_5
    {
        std::cout << "a - b == 897: subtraction 9 - (-888) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_5 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a - b == -897) // test_subtraction_6
    {
        std::cout << "a - b == -897: subtraction -888 - 9 :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_6 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 77;
    a -= a;
    // std::cout << a << '\n';
    if (a == 0) // test_subtraction_7
    {
        std::cout << "a - a == 0: subtraction 77 - 77 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_7 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a -= a;
    if (a == 0) // test_subtraction_8
    {
        std::cout << "a - a == 0: subtraction 0 - 0 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_8 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 88;
    b = 9999;
    if (a - b == -9911) // test_subtraction_9
    {
        std::cout << "a - b == -9911: subtraction 88 - 9999 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_9 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a - b == 9911) // test_subtraction_10
    {
        std::cout << "a - b == 9911: subtraction 9999 - 88 :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_10 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = -88;
    b = -9999;
    if (a - b == 9911) // test_subtraction_11
    {
        std::cout << "a - b == 9911: subtraction -88 - (-9999) " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_11 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a - b == -9911) // test_subtraction_12
    {
        std::cout << "a - b == -9911: subtraction -9999 - (-88) :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_12 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = 888;
    b = 0;
    if (a - b == 888) // test_subtraction_13
    {
        std::cout << "a - b == 888: subtraction 888 - 0 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_13 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a - b == -888) // test_subtraction_14
    {
        std::cout << "a - b == -888: subtraction 0 - 888 :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_14 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    a = "-98765432101234567890";
    b = "12345678901234567890";
    if (a - b == "-111111111002469135780") // test_subtraction_14
    {
        std::cout << "a - b == -111111111002469135780: subtraction -98765432101234567890 - 12345678901234567890 " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_14 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    swap(a, b);
    if (a - b == "111111111002469135780") // test_subtraction_15
    {
        std::cout << "a - b == 111111111002469135780: subtraction 12345678901234567890 - (-98765432101234567890) :: and use swap " << "\033[32m" << " OK " << "\033[0m \n";
    }
    else
    {
        std::cout << "test_subtraction_15 " << "\033[31m" << " FAILD " << "\033[0m\n";
        faild_count++;
    }

    const int N = 15;
    BigInt x[N] = {0, 10, -10, 999, -9999, 565, 545, 4, 7, 8, -88, -1, -88, -9, -4};
    BigInt y[N] = {0, 10, -10, 999, -9999, 565, 545, 4, 7, 8, -88, -1, -88, -9, -4};
    int x1[N] = {0, 10, -10, 999, -9999, 565, 545, 4, 7, 8, -88, -1, -88, -9, -4};
    int y1[N] = {0, 10, -10, 999, -9999, 565, 545, 4, 7, 8, -88, -1, -88, -9, -4};

    for (int i = 0; i < N; ++i) // test_subtraction_99 zero_test
    {
        // std::cout << x[i] - y[i] << "  real is " << x1[i] - y1[i] << "\n";
        if (x[i] - y[i] != x1[i] - y1[i])
        {
            std::cout << "test_subtraction_99 zero_test : " << "\033[31m" << " FAILD " << "\033[0m\n";
            faild_count++;
        }
    }

    if (faild_count)
    {
        std::cout << "\033[31m" << "faild count is " << faild_count << "\033[0m\n";
    }

    // testBigIntSubtraction();
}

void testBigIntSubtraction()
{
    /// Subtraction test with 1-digit numbers
    std::cout << "Subtraction with 1-digit numbers:\n";
    assert((BigInt(5) - BigInt(3)) == BigInt(2));
    assert((BigInt(-5) - BigInt(-3)) == BigInt(-2));
    assert((BigInt(0) - BigInt(7)) == BigInt(-7));

    // Subtraction test with 2 and more -digit numbers
    std::cout << "\nSubtraction with 2-digit numbers:\n";
    assert((BigInt(15) - BigInt(1200)) == BigInt(-1185));
    assert((BigInt(-27077) - BigInt(14)) == BigInt(-27091));
    assert((BigInt(45) - BigInt(-444)) == BigInt(489));
    assert((BigInt(11) - BigInt(-7777777)) == BigInt(7777788));
    assert((BigInt(-7777777) - BigInt(-11)) == BigInt(-7777766));

    // Subtraction test with 5-digit numbers
    std::cout << "\nSubtraction with 5-digit numbers:\n";
    assert((BigInt(12345) - BigInt(6789)) == BigInt(5556));
    assert((BigInt(-98765) - BigInt(43210)) == BigInt(-141975));
    assert((BigInt(11111) - BigInt(99999)) == BigInt(-88888));

    // Subtraction test with 20-digit numbers
    std::cout << "\nSubtraction with 20-digit numbers:\n";
    assert((BigInt("12345678901234567890") - BigInt("9876543210987654321")) == BigInt("2469135690246913569"));
    assert((BigInt("-98765432101234567890") - BigInt("12345678901234567890")) == BigInt("-111111111002469135780"));
    assert((BigInt("10000000000000000000") - BigInt("9999999999999999999")) == BigInt(1));

    std::cout << "All tests passed!" << '\n';
}
