#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap - " << this->_name << " DEFAULT CONSTRUCTOR called" << std::endl;
	this->_hitPoints = this->_initialHealth;
	this->_energyPoints = this->_initialEnergy;
	this->_attackDamage = this->_initialDamage;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap - " << this->_name << " CONSTRUCTOR called" << std::endl;
	this->_hitPoints = this->_initialHealth;
	this->_energyPoints = this->_initialEnergy;
	this->_attackDamage = this->_initialDamage;
}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	std::cout << "Copy constructor called for " << src._name << " ScavTrap" << std::endl;
	*this = src;
}

const ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "Copy assigment operator called for " << src._name << " ScavTrap" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap - " << this->_name << " DESTRUCTOR called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " doesn't has energy!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

const int ScavTrap::_initialHealth = 100;
const int ScavTrap::_initialEnergy = 50;
const int ScavTrap::_initialDamage = 20;
