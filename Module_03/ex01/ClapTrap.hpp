#pragma once
#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>

#define CLAP_TRAP_DEFAULT_HEALTH 10
#define CLAP_TRAP_DEFAULT_ENERGY 10
#define CLAP_TRAP_DEFAULT_DAMAGE 0

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

};

#endif
