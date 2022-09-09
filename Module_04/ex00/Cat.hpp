#pragma once
#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {


public:

	Cat(void);
	Cat(const Cat& src);
	~Cat(void);

	const Cat&	operator=(const Cat& src);

	virtual void	makeSound() const;

};

#endif
