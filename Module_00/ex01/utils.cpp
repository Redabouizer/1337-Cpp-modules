#include "phonebook.hpp"

long toLong(std::string str)
{
    long result = 0;
    size_t i = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    if (!isNumSign(str.substr(i))) {
        return -1;
    }

    while (i < str.length() && std::isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        if (result > INT_MAX) {
            return -1;
        }
        i++;
    }

    return result * sign;
}

void getPhone(std::string *str) {
    while (true) {
        std::cout << "Phone number: ";
        std::getline(std::cin, *str);

        if (std::cin.eof()) {
            break;
        }

        if (isPhone(*str) && !(*str).empty()) {
            break;
        }

        std::cout << "Invalid number, ";
    }
}

std::string fmt10(std::string word)
{
    if (word.length() > 10) {
        return word.substr(0, 9) + ".";
    }
    return std::string(10 - word.length(), ' ') + word;
}

bool isPhone(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]) || !std::isprint(str[i])) {
            return false;
        }
    }
    return true;
}

bool isPrintAlpha(std::string str) {
    int c = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if(std::isalpha(str[i]))
            c++;
        if (!std::isprint(str[i])) 
            return false;
    } 
    if (c == 0)
        return false;
    return true;
}

bool isNumSign(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            if (str[i] != '-' && str[i] != '+') {
                return false;
            }
        }
    }
    return true;
}