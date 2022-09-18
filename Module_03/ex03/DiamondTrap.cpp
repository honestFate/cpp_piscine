#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name")
{
	this->_hitPoints = FlagTrap::_initialHealth;
	this->_energyPoints = ScavTrap::_initialEnergy;
	this->_attackDamage = FlagTrap::_initialDamage;
	std::cout << "DiamondTrap object created by default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), _name(name)
{
	this->_hitPoints = FlagTrap::_initialHealth;
	this->_energyPoints = ScavTrap::_initialEnergy;
	this->_attackDamage = FlagTrap::_initialDamage;
	std::cout << "DiamondTrap " << this->_name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : _name(src._name)
{
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap object deleted" << std::endl;
}

const DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is - " << this->_name << std::endl;
	std::cout << "My ClapTrap name is - " << this->ClapTrap::_name << std::endl;
}
