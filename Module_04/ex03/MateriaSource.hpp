#pragma once
#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include <iostream>
#include "IMateriaSource.hpp"

#define MEMORY_SIZE 4

class MateriaSource : public IMateriaSource
{

public:

	MateriaSource();
	MateriaSource(const MateriaSource& src);
	~MateriaSource();

	const MateriaSource&	operator=(const MateriaSource& src);

	virtual void		learnMateria(AMateria* materia);
	virtual AMateria*	createMateria(std::string const & type);

private:

	AMateria*	_memory[MEMORY_SIZE];

};

#endif
