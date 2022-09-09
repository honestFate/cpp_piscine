#pragma once
#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {


public:

	WrongCat(void);
	WrongCat(const WrongCat& src);
	~WrongCat(void);

	const WrongCat&	operator=(const WrongCat& src);

	void	makeSound() const;

};

#endif

