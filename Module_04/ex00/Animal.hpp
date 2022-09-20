#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {


public:

	Animal();
	Animal(const Animal& src);
	virtual	~Animal();

	const Animal&	operator=(const Animal& src);

	virtual void		makeSound() const;
	const std::string&	getType() const;

protected:

	std::string	type;

};

#endif
