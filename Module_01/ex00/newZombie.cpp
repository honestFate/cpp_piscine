#include "Zombie.hpp"

Zombie*	newZombie( std::string name ) {
	Zombie* bobi = new Zombie(name);
	return (bobi);
}
