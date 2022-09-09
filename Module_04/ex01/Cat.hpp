#pragma once
#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {


public:

	Cat(void);
	Cat(const Cat& src);
	~Cat(void);

	virtual const Cat&	operator=(const Cat& src);

	virtual void	makeSound() const;
	virtual void	copy(const Animal& src);
	virtual void	setNewIdea(const std::string& idea);
	virtual void	showAllIdeas() const;

private:

	Brain&	_brain;

};

#endif
