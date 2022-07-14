#include "HumanB.hpp"

HumanB::HumanB( std::string name )
: _name(name), _weapon(NULL) {
	return;
}

HumanB::~HumanB( void ) {
	return;
}

void	HumanB::attack( void ) {
	std::cout << this->_name << " attacks with their ";
	if (!this->_weapon)
		std::cout << "sharingan";
	else
		std::cout << this->_weapon->getType();
	std::cout << std::endl;
	return;
}

void	HumanB::setWeapon( Weapon& type ) {
	this->_weapon = &type;
	return;
}
