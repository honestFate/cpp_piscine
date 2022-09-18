#pragma once
#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include <iostream>
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap
{

public:

	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& src);
	~DiamondTrap();

	const DiamondTrap&	operator=(const DiamondTrap& src);

	void	attack(const std::string& target);
	void	whoAmI();

private:

	std::string	_name;

};

#endif
