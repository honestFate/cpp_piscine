#pragma once
#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

#define SCAV_TRAP_DEFAULT_HEALTH 100
#define SCAV_TRAP_DEFAULT_ENERGY 50
#define SCAV_TRAP_DEFAULT_DAMAGE 20

class ScavTrap : public ClapTrap {


public:

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();

	const ScavTrap&	operator=(const ScavTrap& src);

	void	guardGate();

};

#endif
