#include "FlagTrap.hpp"

FlagTrap::FlagTrap() {

	std::cout << "FlagTrap - " << this->_name << " DEFAULT CONSTRUCTOR called" << std::endl;
	this->_hitPoints = FLAG_TRAP_DEFAULT_HEALTH;
	this->_energyPoints = FLAG_TRAP_DEFAULT_ENERGY;
	this->_attackDamage = FLAG_TRAP_DEFAULT_DAMAGE;
	return;
}

FlagTrap::FlagTrap(const std::string& name) : ClapTrap(name) {

	std::cout << "FlagTrap - " << this->_name << " CONSTRUCTOR called" << std::endl;
	this->_hitPoints = FLAG_TRAP_DEFAULT_HEALTH;
	this->_energyPoints = FLAG_TRAP_DEFAULT_ENERGY;
	this->_attackDamage = FLAG_TRAP_DEFAULT_DAMAGE;
	return;
}

FlagTrap::FlagTrap(const FlagTrap& src) {

	std::cout << "Copy constructor called for " << src._name << " FlagTrap" << std::endl;
	*this = src;
}

const FlagTrap& FlagTrap::operator=(const FlagTrap& src) {

	std::cout << "Copy assigment operator called for " << src._name << " FlagTrap" << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

FlagTrap::~FlagTrap() {

	std::cout << "FlagTrap - " << this->_name << " DESTRUCTOR called" << std::endl;
}

void	FlagTrap::highFivesGuys() {

	std::cout << "FlagTrap" << this->_name << " is requesting high fives" << std::endl;
}
