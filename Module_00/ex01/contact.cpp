/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:03:59 by rbouizer          #+#    #+#             */
/*   Updated: 2025/02/25 01:01:10 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "phonebook.hpp"


Contact::Contact()
{	
}

Contact::Contact(int _Index,
std::string _First_name,
std::string _Last_name,
std::string _Nick_name,
std::string _Phone_number,
std::string _Darkest_secret)
{
	index = _Index;
	first_name = _First_name;
	last_name = _Last_name;
	nick_name = _Nick_name;
	phone_number = _Phone_number;
	darkest_secret = _Darkest_secret;
}

void	Contact::print(void)
{	
	std::cout << "|         ";
	std::cout << index;
	std::cout << "|";
	std::cout << fmt10(first_name);
	std::cout << "|";
	std::cout << fmt10(last_name);
	std::cout << "|";
	std::cout << fmt10(nick_name);
	std::cout << "|" << std::endl;
}

void	Contact::print_info(void)
{
	std::cout << "First name:" << first_name << std::endl;
	std::cout << "Last name:" << last_name << std::endl;
	std::cout << "Nickname:" << nick_name << std::endl;
	std::cout << "Phone number:" << phone_number << std::endl;
	std::cout << "Darkest secret:" << darkest_secret << std::endl;
}