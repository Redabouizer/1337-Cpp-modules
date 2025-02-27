#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie( void );
	Zombie( std::string Name );
	~Zombie( void );

	void	announce( void );
    Zombie* newZombie( std::string name );
    void	randomChump( std::string name );
};


#endif