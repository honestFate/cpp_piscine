#pragma once
#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{

public:

	Ice();
	Ice(const Ice& src);
	~Ice();

	const Ice&	operator=(const Ice& src);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);

private:

	

};

#endif
