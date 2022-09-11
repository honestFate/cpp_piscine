#pragma once
#ifndef FLAG_TRAP_H
#define FLAG_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

#define FLAG_TRAP_DEFAULT_HEALTH 100
#define FLAG_TRAP_DEFAULT_ENERGY 100
#define FLAG_TRAP_DEFAULT_DAMAGE 30

class FlagTrap : public ClapTrap {


public:

	FlagTrap();
	FlagTrap(const std::string& name);
	FlagTrap(const FlagTrap& src);
	~FlagTrap();

	const FlagTrap&	operator=(const FlagTrap& src);

	void	highFivesGuys(void);

};

#endif
