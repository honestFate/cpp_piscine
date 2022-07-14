#include "Zombie.hpp"

void	randomChump( std::string name ) {
	Zombie bobi = Zombie(name);
	bobi.announce();
	std::cout << "He won't live long" << std::endl;
}
