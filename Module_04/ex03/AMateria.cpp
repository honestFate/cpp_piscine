#include "AMateria.hpp"

AMateria::AMateria() : type("default") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& src)
{
	(void)src;
}

AMateria::~AMateria() {}

const AMateria& AMateria::operator=(const AMateria& src)
{
	(void)src;
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
