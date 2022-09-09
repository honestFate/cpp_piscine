#pragma once
#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

class WrongAnimal {


public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal& src);
	~WrongAnimal();

	const WrongAnimal&	operator=(const WrongAnimal& src);

	void				makeSound() const;
	const std::string&	getType() const;

protected:

	std::string	type;

};

#endif
