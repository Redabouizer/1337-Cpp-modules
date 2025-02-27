# include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string's adress : " << &str << std::endl;
	std::cout << "string's ptr adress : "  << stringPTR << std::endl;
	std::cout << "string's ref adress : " << &stringREF << std::endl;
	
	std::cout << "string's value : " << str << std::endl;
	std::cout << "string's ptr value : " << *stringPTR << std::endl;
	std::cout << "string's ref value : " << stringREF << std::endl;
}