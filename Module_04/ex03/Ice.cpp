#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& src) : AMateria("ice")
{
	(void)src;
}

const Ice& Ice::operator=(const Ice& src)
{
	if (this != &src)
	{
		std::cout << "While assigning a Materia to another, copying the type doesn't make sense." << std::endl;
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
