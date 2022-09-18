#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("NoName"),
_hitPoints(ClapTrap::_initialHealth),
_energyPoints(ClapTrap::_initialEnergy),
_attackDamage(ClapTrap::_initialDamage)
{
	std::cout << this->_name << "ClapTrap " << " created with default constructor" << std::endl;
	return;
}

ClapTrap::ClapTrap(const std::string& name) :
_name(name),
_hitPoints(ClapTrap::_initialHealth),
_energyPoints(ClapTrap::_initialEnergy),
_attackDamage(ClapTrap::_initialDamage)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->_name << " ClapTrap" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called for " << src._name << " ClapTrap" << std::endl;
	*this = src;
}

const ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assigment operator called for " << src._name << " ClapTrap" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " doesn't has energy!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout	<< "ClapTrap " << this->_name
				<< " takes " << amount << " points of damage! "
				<< "It has " << this->_hitPoints << " now!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout	<< "ClapTrap " << this->_name
					<< " repairs itself for " << amount << " points of damage! "
					<< "It has " << this->_hitPoints << " now!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " doesn't has energy!" << std::endl;
	}
}

const int ClapTrap::_initialHealth = 10;
const int ClapTrap::_initialEnergy = 10;
const int ClapTrap::_initialDamage = 0;
