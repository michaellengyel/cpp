#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::cout << "Lambdas" << std::endl;

    // Structure of a Lambda (without and with return type):
    // []() { }
    // []() mutable -> T { }

    // Parts of a lambda function:
    // [] capture list
    // () argument list
    // -> T return type (can be omitted)
    // [] function body

    // Capture List:
    // [x] capture variable by value x
    // [&x] capture variable by reference
    // [=] capture any/all variables is scope by value
    // [&] capture any/all variables is scope by reference

    // Argument list:
    // Follows standard cpp function syntax

    // Return type:
    // If lambda has a single return, then return type can be omitted

    // Function body:
    // Follows standard cpp function syntax

    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Lambda function for printing passed into std::for_each function
    std::for_each(numbers.begin(), numbers.end(), [] (int x) {std::cout << x << " ";});
    std::cout << std::endl;

    // Lambda function for sorting passed into std::sort
    std::sort(numbers.begin(), numbers.end(), [] (int x, int y) -> bool {return y < x ? x : y;});

    // Lambda function for printing passed into std::for_each function
    std::for_each(numbers.begin(), numbers.end(), [] (int x) {std::cout << x << " ";});
    std::cout << std::endl;

    return 0;
}