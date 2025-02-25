/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:56:32 by rbouizer          #+#    #+#             */
/*   Updated: 2025/02/25 00:58:28 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include <climits>

bool		isPhone(std::string str);
bool		isNumSign(std::string str);
bool        isPrint(std::string str);
long        toLong(std::string str);
std::string fmt10(std::string word);
void        getPhone(std::string *str);

class Phonebook
{
private:
	int		C_count;
	int		Index;
	Contact contact[8];
public:
	Phonebook();
	void	add(Phonebook *_PHONE);
	void	search(Phonebook _PHONE);
	void	print_table(Phonebook _PHONE);
};

#endif