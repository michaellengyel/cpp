#include <iostream>

// Example function 1.
int function(int x) {
    return x;
}

// Example function 2.
int function(int x, int y) {
    return x + y;
}

// Example function 3.
int function(int x, int (&f)(int)) {
    return x + f(x);
}

// Example function 4. (causes ambiguity!)
// int function(int x, int (&f)(int, int)) {
//     return x + f(x, x);
// }

int main() {

    std::cout << "Function Pointers" << std::endl;

    int (*functionPointer1)(int) = function;                // functionPointer1 stores pointer to Example function 1.
    int (*functionPointer2)(int, int) = function;           // functionPointer2 stores pointer to Example function 2.
    int (*functionPointer3)(int, int (&f)(int)) = function; // functionPointer3 stores pointer to Example function 3.

    std::cout << "Address of int function(int x): " << (void*)functionPointer1 << std::endl;
    std::cout << "Address of int function(int x, int y): " << (void*)functionPointer2 << std::endl;
    std::cout << "Address of int function(int x, int (&f)(int)): " << (void*)functionPointer3 << std::endl;


    // Passing a function pointer to a function (See example function 3.)
    // Example function 3's input parameter requires that example function 1 is called
    std::cout << function(5, function) << std::endl;


    return 0;
}
