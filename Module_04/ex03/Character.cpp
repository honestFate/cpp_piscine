#include "Character.hpp"

Character::Character() : _name("NoName"), _inventory() {}

Character::Character(const std::string& name) : _name(name), _inventory()  {}

Character::Character(const Character& src)
{
	*this = src;
}

Character::~Character() {}

const Character& Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		for (size_t i = 0; i < INVENTORY_SIZE; i++)
		{
			this->_inventory[i] = src._inventory[i];
		}
	}
	return (*this);
}

void	Character::setName(const std::string& name)
{
	this->_name = name;
}


std::string const &	Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!this->_inventory[i])
		{
			std::cout << "equiping " << m->getType() << " into " << i << " slot" << std::endl;
			this->_inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (this->_inventory[idx])
	{
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
	}
}
