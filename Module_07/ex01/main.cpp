#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"

template <typename T>
void printElement(T const &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void increment(T &value)
{
    ++value;
}

void toUpperChar(char &character)
{
    character = static_cast<char>(std::toupper(character));
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::size_t numbersLength = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Before increment:" << std::endl;
    ::iter(numbers, numbersLength, ::printElement<int>);

    ::iter(numbers, numbersLength, ::increment<int>);

    std::cout << "After increment:" << std::endl;
    ::iter(numbers, numbersLength, ::printElement<int>);

    const std::string words[] = {"template", "iteration", "const"};
    std::size_t wordsLength = sizeof(words) / sizeof(words[0]);

    std::cout << "\nConst array output:" << std::endl;
    ::iter(words, wordsLength, ::printElement<std::string>);

    char letters[] = {'a', 'b', 'c', 'd'};
    std::size_t lettersLength = sizeof(letters) / sizeof(letters[0]);

    ::iter(letters, lettersLength, &toUpperChar);

    std::cout << "\nUppercased letters:" << std::endl;
    ::iter(letters, lettersLength, ::printElement<char>);

    return 0;
}
