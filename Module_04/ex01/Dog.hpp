#pragma once
#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {


public:

	Dog();
	Dog(const Dog& src);
	~Dog();

	virtual const Dog&	operator=(const Dog& src);

	virtual void	makeSound() const;
	virtual void	copy(const Animal& src);
	void			setNewIdea(const std::string& idea);
	void			showAllIdeas() const;

private:

	Brain&	_brain;

};

#endif
