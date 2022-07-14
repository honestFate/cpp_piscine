#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>
# include <iostream>

# define ZOMBIE_COUNT 2 

class Zombie
{


private:

	std::string	_name;


public:

	Zombie( std::string );
	Zombie();
	~Zombie();

	void	setName( std::string );
	void	announce( void );

};

Zombie* zombieHorde( int N, std::string name );


#endif