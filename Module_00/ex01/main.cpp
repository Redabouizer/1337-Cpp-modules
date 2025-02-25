/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:04:09 by rbouizer          #+#    #+#             */
/*   Updated: 2025/02/25 00:04:11 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	Phonebook	_PHONE;
	std::string	line_read;

	while (std::cin)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Enter a command (ADD, SEARCH, EXIT):";
		std::getline(std::cin, line_read);
		if (line_read == "ADD")
			_PHONE.add(&_PHONE);
		else if (line_read == "SEARCH")
			_PHONE.search(_PHONE);
		else if (line_read == "EXIT")
			break ;
	}
}