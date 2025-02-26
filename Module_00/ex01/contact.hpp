#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
private:
	int			index;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
public:
	Contact();
	Contact(int _Index,
    std::string _First_name, std::string _Last_name,
    std::string _Nick_name, std::string _Phone_number,
    std::string _Darkest_secret);
	void	print(void);
	void	print_info(void);
};

#endif