#include <iostream>


int main() {

    std::cout << "casting and conversion>" << std::endl;


    // Implicit conversions are automatically performed when a value is copied to a compatible type

    // int to short
    {
        int value = 87;
        short result = value;
        std::cout << "variable, sizeof(): [" << value << ", " << sizeof(value) << "]; result, sizeof(): [" << result << ", " << sizeof(result) << "]" << std::endl;
    }

    // int to double
    {
        int variable = 87;
        float result = variable;
        std::cout << "variable, sizeof(): [" << variable << ", " << sizeof(variable) << "]; result, sizeof(): [" << result << ", " << sizeof(result) << "]" << std::endl;
    }

    // double to int
    {
        double variable = 87.342;
        int result = variable;
        std::cout << "variable, sizeof(): [" << variable << ", " << sizeof(variable) << "]; result, sizeof(): [" << result << ", " << sizeof(result) << "]" << std::endl;
    }

    // Promotion (smaller type to larger type) e.g. float to double, short to int:

    // Situations where data loss or "overflow" can happen

    // negative int to unsigned int
    {
        int variable = -34;
        unsigned int result = variable;
        std::cout << "variable, sizeof(): [" << variable << ", " << sizeof(variable) << "]; result, sizeof(): [" << result << ", " << sizeof(result) << "]" << std::endl;
    }

    // negative int to std::size_t
    {
        int variable = -34;
        std::size_t result = variable;
        std::cout << "variable, sizeof(): [" << variable << ", " << sizeof(variable) << "]; result, sizeof(): [" << result << ", " << sizeof(result) << "]" << std::endl;
    }

    // TODO:
    // Type casting for primitive types (explicit conversion)

    int x = int(4.3); // functional notation
    int y = (int)4.3; // c-like notation

    // Pointer casting

    // Type casting for user types (explicit conversion)

    // dynamic_cast <new_type> (expression)
    // reinterpret_cast <new_type> (expression)
    // static_cast <new_type> (expression)
    // const_cast <new_type> (expression)

    // typeid (expression)





    return 0;
}