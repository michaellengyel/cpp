#include <iostream>
#include <string>
#include <bitset>

void printText(const std::string& str)
{
    std::cout << str << std::endl;
}

template <typename T>
void printNumber(const T& t)
{
    std::cout << "DEC: " << t << std::endl;
    std::cout << "BIN: " << std::bitset<sizeof(T)*8>(t) << std::endl;
}

int main() {

    printText("Section 1.0 - Bitwise Operators");
    printText("\n");

    // Bit shift left operator
    {
        printText("Bit shift left by 2:");
        int x = 13;
        printNumber<int>(x);
        x = x << 2;
        printNumber<int>(x);
        printText("\n");
    }

    // Bit shift right operator
    {
        printText("Bit shift right by 1:");
        short x = 13;
        printNumber<short>(x);
        x = x >> 1;
        printNumber<short>(x);
        printText("\n");
    }

    // Bitwise AND operator (std::min)
    {
        printText("Bitwise AND two numbers (std::min):");
        int x = 34;
        int y = 62;
        int z = x & y;
        printNumber<int>(x);
        printNumber<int>(y);
        printNumber<int>(z);
        printText("\n");
    }

    // Bitwise OR operator (std::max)
    {
        printText("Bitwise OR two numbers (std::max):");
        int x = 34;
        int y = 62;
        int z = x | y;
        printNumber<int>(x);
        printNumber<int>(y);
        printNumber<int>(z);
        printText("\n");
    }

    // Bitwise XOR operator (Exclusive OR)
    {
        printText("Bitwise XOR two numbers:");
        short x = 34;
        short y = 62;
        short z = x ^ y;
        printNumber<short>(x);
        printNumber<short>(y);
        printNumber<short>(z);
        printText("\n");
    }

    // Bitwise NOT (Inverter)
        {
        printText("Bitwise NOT of a number:");
        int x = 13;
        printNumber<int>(x);
        x = ~x;
        printNumber<int>(x);
        printText("\n");
    }


    return 0;
}