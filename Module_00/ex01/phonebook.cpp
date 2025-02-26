/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:41 by zderfouf          #+#    #+#             */
/*   Updated: 2025/02/26 02:13:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::string str[5];
    const std::string prompts[] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};

    for (int i = 0; i < 5; i++)
    {
        while (true)
        {
            std::cout << prompts[i];
            if (!std::getline(std::cin, str[i]) || str[i].empty())
            {
                std::cout << "Field cannot be empty. Retry: ";
                continue;
            }

            if (i == 3 && !isPhone(str[i]))
            {
                std::cout << "Invalid phone number. Retry: ";
                continue;
            }

            break;
        }
    }

    contact[Index] = Contact(Index, str[0], str[1], str[2], str[3], str[4]);

    if (C_count < 8)
        C_count++;
    
    Index = (Index + 1) % 8;
}
