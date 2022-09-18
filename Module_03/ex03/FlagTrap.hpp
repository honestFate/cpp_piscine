#pragma once
#ifndef FLAG_TRAP_H
#define FLAG_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FlagTrap : public virtual ClapTrap {

public:

	FlagTrap();
	FlagTrap(const std::string& name);
	FlagTrap(const FlagTrap& src);
	~FlagTrap();

	const FlagTrap&	operator=(const FlagTrap& src);

	void	highFivesGuys(void);

protected:

	static const int _initialHealth;
	static const int _initialEnergy;
	static const int _initialDamage;

};

#endif
