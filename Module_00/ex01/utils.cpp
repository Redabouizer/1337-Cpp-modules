/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:04:36 by rbouizer          #+#    #+#             */
/*   Updated: 2025/02/25 00:04:38 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

long	my_atol(std::string str)
{
	long i, nb, s;

	(1) && (i = 0, nb = 0, s = 1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (!_parse(str))
		return (-1);
	while (std::isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX)
			return (-1);
		i++;
	}
	return (nb * s);
}

void	phone_number(std::string *str)
{
	std::cout << "Phone number:";
	std::getline(std::cin, *str);
	while (!std::cin.eof() && (!parse(*str) || (*str).empty()))
	{
		std::cout << "Enter a valide number:";
		std::getline(std::cin, *str);
	}
}

std::string ten_char(std::string word)
{
	std::string tmp;

	if (word.size() > 10)
	{
		tmp = word.substr(0, 10);
		tmp[9] = '.';
		return tmp;
	}
	else
	{
		int spaces_count;

		tmp = "          ";
		spaces_count = 10 - word.size();
		tmp = tmp.substr(0, spaces_count) + word;
		return tmp;
	}
	return word;
}

bool	parse(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]) || !std::isprint(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	parse_(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!std::isprint(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	_parse(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (false);
		i++;
	}
	return (true);
}