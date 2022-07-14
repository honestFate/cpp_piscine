#include "Weapon.hpp"

Weapon::Weapon( std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string const &	Weapon::getType( void ) {
	return this->_type;
}

void	Weapon::setType( std::string weaponType ) {
	this->_type = weaponType;
}
