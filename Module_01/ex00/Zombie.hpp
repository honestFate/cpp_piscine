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
	~Zombie();

	void announce( void );

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif