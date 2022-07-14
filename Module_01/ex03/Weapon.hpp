#pragma once
#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{


private:
	
	std::string	_type;


public:

	Weapon( std::string type );
	~Weapon();

	std::string const &	getType( void );
	void				setType( std::string );

};


#endif