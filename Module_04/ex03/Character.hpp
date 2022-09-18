#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter
{

public:

	Character();
	Character(const std::string& name);
	Character(const Character& src);
	~Character();

	const Character&	operator=(const Character& src);

	void						setName(const std::string& name);
	virtual std::string const &	getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

private:

	std::string	_name;
	AMateria*	_inventory[INVENTORY_SIZE];

};

#endif
