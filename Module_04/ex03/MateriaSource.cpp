#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _memory() {}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MEMORY_SIZE; i++)
	{
		if (this->_memory[i])
		{
			std::cout << "Deleting AMateria..." << std::endl;
			delete this->_memory[i];
		}
	}
}

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
			std::cout << "Learning materia... puted into " << i << " slot, type " << materia->getType() << std::endl;
			this->_memory[i] = materia;
			return;
		}
	}
	std::cout << "No space left deleting 1 slot..." << std::endl;
	delete this->_memory[0];
	std::cout << "Learn materia " << 0 << " type " << materia->getType() << std::endl;
	this->_memory[0] = materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < MEMORY_SIZE; i++)
	{
		if (this->_memory[i] && this->_memory[i]->getType() == type)
		{
			std::cout << "Create materia " << i << " type - " << type << std::endl;
			return this->_memory[i]->clone();
		}
	}
	return NULL;
}
