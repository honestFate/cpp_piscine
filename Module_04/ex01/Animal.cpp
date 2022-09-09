#include "Animal.hpp"

Animal::Animal() : type("Untyped")
{
	std::cout << "Animal object created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal object deleted" << std::endl;
	return;
}

Animal::Animal(const Animal& src)
{
	*this = src;
}

const Animal& Animal::operator=(const Animal& src)
{
	this->copy(src);
	return (*this);
}

void	Animal::makeSound() const {

	std::cout << "*Unintelligible sounds*" << std::endl;
}

const std::string&	Animal::getType() const {
	
	return this->type;
}

void	Animal::setNewIdea(const std::string& idea)
{
	(void)idea;
	std::cout << "No brain for ideas:(" << std::endl;
}

void	Animal::showAllIdeas() const
{
	std::cout << "No brain - no ideas" << std::endl;
}

void	Animal::copy(const Animal& src)
{
	(void)src;
	std::cout << "Animal copy. It doesn't have any sense!" << std::endl;
}
