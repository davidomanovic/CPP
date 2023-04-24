#include <iostream>
#include <memory>

void fillInFibonacciNumbers(int* result, int length)
{
    // Define the first two numbers in the sequence
    result[0] = 0;
    result[1] = 1;

    for (int i = 2; i < length; i++) // Fibonacci sequence recursion
    {
        result[i] = result[i-1] + result[i-2];
    }
}

void printArray(int* arr, int length)
{
    for (int i=0; i < length; i++) // Loop through pointer, print out element in terminal
    {
        std::cout << arr[i] << "\n";
    }
}

void createFibonacci()
{
    int length; // How many fibonacci numbers?

    // Ask how many numbers to generate
    std::cout << "Amount of Fibonacci numbers: ";
    std::cin >> length;

    // Allocate memory to a table big enough for the series we want
    int* result = new int[static_cast<std::size_t>(length)] {};
    std::cout << "Memory allocated for " << length << " fibonacci numbers.\n";

    // Fill table with fillInFibonacciNumbers;
    fillInFibonacciNumbers(result, length);

    // Print out result with our function printArray()
    printArray(result, length);

    // Deallocate memory that was reserved
    delete[] result;
    result = nullptr;
}
