#include <iostream>

int main() {

    std::cout << "Pointers:" << std::endl;

    // Declare and initialize an int pointer to nullptr. p stores the memory address of an int
    int* p = nullptr;

    // Declare and initialize an int to 5.
    int alpha = 5;

    // Assign the address of an int variable to the int pointer.
    p = &alpha;

    // Declare and initialize an int pointer pointer. pp stores the memory address of a pointer to a int memory address.
    int** pp = nullptr;

    // Assign the address of an int pointer to the int pointer pointer.
    pp = &p;

    // Print int pointer
    std::cout << "p:\t" << p << std::endl;
    std::cout << "*p:\t" << *p << std::endl;

    // Print int pointer pointer
    std::cout << "pp:\t" << pp << std::endl;
    std::cout << "*pp:\t" << *pp << std::endl;
    std::cout << "**pp:\t" << **pp << std::endl;

    return 0;
}