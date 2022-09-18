#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& src) : AMateria("cure")
{
	(void)src;
}

const Cure& Cure::operator=(const Cure& src)
{
	AMateria::operator=(src);

	return *this;
}

AMateria*	Cure::clone() const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
