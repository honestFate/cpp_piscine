#pragma once
#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();

	const ClapTrap&	operator=( const ClapTrap& src );

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	static const int _initialHealth;
	static const int _initialEnergy;
	static const int _initialDamage;

};

#endif
