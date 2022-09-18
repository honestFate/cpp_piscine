#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _memory() {}

MateriaSource::~MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

const MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < MEMORY_SIZE; i++)
		{
			this->_memory[i] = src._memory[i];
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (size_t i = 0; i < MEMORY_SIZE; i++)
	{
		if (!this->_memory[i])
		{
			std::cout << "Learn materia " << i << " type " << materia->getType() << std::endl;
			this->_memory[i] = materia;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < MEMORY_SIZE; i++)
	{
		if (this->_memory[i])
			std::cout << this->_memory[i]->getType() << std::endl;
		if (this->_memory[i] && this->_memory[i]->getType() == type)
		{
			std::cout << "Create materia " << i << " type - " << type << std::endl;
			return this->_memory[i]->clone();
		}
	}
	return NULL;
}
