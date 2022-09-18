#pragma once
#ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{

public:

	Cure();
	Cure(const Cure& src);
	~Cure();

	const Cure&	operator=(const Cure& src);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);

private:

	

};

#endif
