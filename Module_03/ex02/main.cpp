#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int	main() {

	ClapTrap a("Bobi");

	a.attack("mid tower");
	a.takeDamage(5);
	a.beRepaired(10);
	for (size_t i = 0; i < 2; i++) {
		a.attack("bottom tower");
	}

	ScavTrap b("Bobi mid");

	b.attack("mid tower");
	b.takeDamage(5);
	b.beRepaired(10);
	for (size_t i = 0; i < 2; i++) {
		b.attack("bottom tower");
		b.guardGate();
	}

	FlagTrap c("Bobi center");
	c.attack("mid tower");
	c.takeDamage(5);
	c.beRepaired(10);
	for (size_t i = 0; i < 2; i++) {
		c.attack("bottom tower");
		c.highFivesGuys();
	}
}
