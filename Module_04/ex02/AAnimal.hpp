#pragma once
#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>

class AAnimal {


public:

	AAnimal();
	AAnimal(const AAnimal& src);
	virtual ~AAnimal();

	const AAnimal&	operator=(const AAnimal& src);

	virtual void		makeSound() const;
	const std::string&	getType() const;
	virtual void		setNewIdea(const std::string& idea) = 0;
	virtual void		showAllIdeas() const = 0;
	virtual void		copy(const AAnimal& src) = 0;

protected:

	std::string	type;

};

#endif
