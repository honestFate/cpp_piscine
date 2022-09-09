#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Untyped")
{
	std::cout << "AAnimal object created" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal object deleted" << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal& src)
{
	*this = src;
}

const AAnimal& AAnimal::operator=(const AAnimal& src)
{
	this->copy(src);
	return (*this);
}

void	AAnimal::makeSound() const {

	std::cout << "*Unintelligible sounds*" << std::endl;
}

const std::string&	AAnimal::getType() const {
	
	return this->type;
}
