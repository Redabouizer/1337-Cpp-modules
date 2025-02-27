#pragma once

# include <iostream>
# include <new>

class Zombie
{
private:
	std::string	name;
public:
	Zombie( void );
	~Zombie( void );

	void	announce( void );
	void	setName( std::string Name );
};

Zombie* zombieHorde( int N, std::string name );
