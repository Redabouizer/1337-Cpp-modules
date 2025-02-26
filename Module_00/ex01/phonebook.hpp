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
	void	add();
	void	search();
	void	print_table();
};

#endif