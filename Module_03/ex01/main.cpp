#include "ScavTrap.hpp"

int	main() {

	ClapTrap a("Bobi");

	a.attack("mid tower");
	a.takeDamage(5);
	a.beRepaired(10);
	for (size_t i = 0; i < 2; i++) {
		a.attack("bottom tower");
	}

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << std::endl;

	ScavTrap b("Bobi");

	b.attack("mid tower");
	b.takeDamage(5);
	b.beRepaired(10);
	for (size_t i = 0; i < 2; i++) {
		b.attack("bottom tower");
		b.guardGate();
	}
}
