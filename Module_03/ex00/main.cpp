#include "ClapTrap.hpp"

int	main() {

	ClapTrap a("Bobi");

	a.attack("mid tower");
	a.takeDamage(5);
	a.beRepaired(10);
	for (size_t i = 0; i < 10; i++) {
		a.attack("bottom tower");
	}
}
