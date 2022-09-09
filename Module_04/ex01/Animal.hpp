#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {


public:

	Animal();
	Animal(const Animal& src);
	virtual ~Animal();

	const Animal&	operator=(const Animal& src);

	virtual void		makeSound() const;
	const std::string&	getType() const;
	virtual void		setNewIdea(const std::string& idea);
	virtual void		showAllIdeas() const;
	virtual void		copy(const Animal& src);

protected:

	std::string	type;

};

#endif
