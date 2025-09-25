#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void displayArray(Array<T> const &array, const std::string &label)
{
    std::cout << label << " (size=" << array.size() << ")" << std::endl;
    for (unsigned int i = 0; i < array.size(); ++i)
        std::cout << "  [" << i << "] = " << array[i] << std::endl;
}

int main()
{
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>(i * 10);

    displayArray(numbers, "Numbers");

    try
    {
        std::cout << numbers[5] << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Array<std::string> words(3);
    words[0] = "template";
    words[1] = "array";
    words[2] = "copy";

    Array<std::string> copy(words);
    displayArray(words, "Words");
    displayArray(copy, "Copy");

    words[1] = "modified";
    displayArray(words, "Words (modified)");
    displayArray(copy, "Copy (unchanged)");

    Array<int> assigned;
    assigned = numbers;
    displayArray(assigned, "Assigned numbers");

    Array<char> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try
    {
        empty[0];
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception on empty array: " << e.what() << std::endl;
    }

    return 0;
}
