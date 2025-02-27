#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug() {
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(){
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		arrayLevel[4] = {"debug", "info", "warning", "error"};
	int		i = 0;

	while (i < 4) {
		if (arrayLevel[i] == level)
			break;
        i++;
	}
	switch (i)
    {
    case 0:
        this->debug();
        break;
    case 1:
        this->info();
        break;
    case 2:
        this->warning();
        break;
    case 3:
        this->error();
        break;
    default:
        break;
    }

}