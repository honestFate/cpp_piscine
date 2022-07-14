#include "Zombie.hpp"


Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << this->_name << ": created" << std::endl;
	return;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " died" << std::endl;
	return;
}

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}