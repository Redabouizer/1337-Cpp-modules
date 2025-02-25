/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:19:41 by zderfouf          #+#    #+#             */
/*   Updated: 2025/02/25 01:14:37 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	C_count = 0;
	Index = 0;
}

void	Phonebook::print_table(Phonebook _PHONE)
{
	std::cout << "|" << "     index";
	std::cout << "|" << "first_name";
	std::cout << "|" << " last_name";
	std::cout << "|" << " nick_name";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _PHONE.C_count; i++)
	{
		contact[i].print();
	}
}

void	Phonebook::search(Phonebook _PHONE)
{
	int index;

	if (!_PHONE.C_count)
		return (void) (std::cout << "No available contacts to show." << std::endl);
	print_table(_PHONE);
	while (!std::cin.eof())
	{
		std::string line;

		std::cout << "Enter index to be looked for:";
		std::getline(std::cin, line);
		if (!line.size() || !isPhone(line))
			continue ;
		index = toLong(line);

		if ( index < 0 || index > _PHONE.C_count - 1)
		{
			std::cerr << "No contact available with the index given !" << std::endl;
			continue ;
		}
		if (!std::cin.eof())
			contact[index].print_info();
	}
}

void	Phonebook::add(Phonebook *_PHONE)
{
	int i = 0;
	std::string str[5];

	while (!std::cin.eof() && i < 5)
	{
		if (i == 0)
			std::cout << "First name:";
		if (i == 1)
			std::cout << "Last name:";
		if (i == 2)
			std::cout << "Nickname:";
		if (i == 3)
		{
			getPhone(&str[i++]);
			continue ;
		}
		if (i == 4)
			std::cout << "Darkest secret:";
		while (1)
		{
			std::getline(std::cin, str[i]);
			if (std::cin.eof())
				return ;
			if (str[i].empty() || !isPrint(str[i]))
				std::cout << "Can't have that! Retry:";
			else
				break ;
		}
		i++;
	}
	contact[_PHONE->Index] = Contact(_PHONE->Index, str[0], str[1], str[2], str[3], str[4]);
	if (_PHONE->C_count < 8)
		_PHONE->C_count++;
	_PHONE->Index++;
	if (_PHONE->Index == 8)
		_PHONE->Index = 0;
}