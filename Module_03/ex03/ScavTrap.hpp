#pragma once
#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

public:

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();

	const ScavTrap&	operator=(const ScavTrap& src);

	void	attack(const std::string& target);
	void	guardGate();

protected:

	static const int _initialHealth;
	static const int _initialEnergy;
	static const int _initialDamage;

};

#endif
