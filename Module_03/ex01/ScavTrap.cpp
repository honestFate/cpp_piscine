#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {

	std::cout << "ScavTrap - " << this->_name << " DEFAULT CONSTRUCTOR called" << std::endl;
	this->_hitPoints = SCAV_TRAP_DEFAULT_HEALTH;
	this->_energyPoints = SCAV_TRAP_DEFAULT_ENERGY;
	this->_attackDamage = SCAV_TRAP_DEFAULT_DAMAGE;
	return;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {

	std::cout << "ScavTrap - " << this->_name << " CONSTRUCTOR called" << std::endl;
	this->_hitPoints = SCAV_TRAP_DEFAULT_HEALTH;
	this->_energyPoints = SCAV_TRAP_DEFAULT_ENERGY;
	this->_attackDamage = SCAV_TRAP_DEFAULT_DAMAGE;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& src) {

	std::cout << "Copy constructor called for " << src._name << " ScavTrap" << std::endl;
	*this = src;
}

const ScavTrap& ScavTrap::operator=(const ScavTrap& src) {

	std::cout << "Copy assigment operator called for " << src._name << " ScavTrap" << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap - " << this->_name << " DESTRUCTOR called" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
