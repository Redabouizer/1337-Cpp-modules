#include "phonebook.hpp"

Phonebook::Phonebook() : C_count(0), Index(0) {}

void Phonebook::print_table()
{
    std::cout << "|" << "     index";
	std::cout << "|" << "first_name";
	std::cout << "|" << " last_name";
	std::cout << "|" << " nick_name";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < C_count; i++)
    {
        contact[i].print();
    }
}

void Phonebook::search()
{
    if (C_count == 0)
    {
        std::cout << "No available contacts to show." << std::endl;
        return;
    }

    print_table();

    std::string line;
    while (true)
    {
        std::cout << "Enter index to search: ";
        if (!std::getline(std::cin, line) || line.empty())
            break;

        if (!isPhone(line))
        {
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }

        int index = toLong(line);
        if (index < 0 || index >= C_count)
        {
            std::cerr << "No contact available with the given index!" << std::endl;
            continue;
        }

        contact[index].print_info();
    }
}

void Phonebook::add()
{
    int i = 0;
    std::string str[5];
    const std::string prompts[] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};

    while (!std::cin.eof() && i < 5)
    {
        if (i == 3)
        {
            getPhone(&str[i]); 
            i++;
            continue;
        }
        std::cout << prompts[i];

        while (true)
        {
            std::getline(std::cin, str[i]);
            
            if (std::cin.eof())
                return;

            if (str[i].empty())
            {
                std::cout << "Field cannot be empty. Retry: ";
                continue;
            }

            if (i != 3 && !isPrintAlpha(str[i]))
            {
                std::cout << "Invalid input. Retry: ";
                continue;
            }

            break;
        }

        i++;
    }

    contact[Index] = Contact(Index, str[0], str[1], str[2], str[3], str[4]);

    if (C_count < 8)
        C_count++;
    Index++;
    if (Index == 8)
        Index = 0;
}
