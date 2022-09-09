#include "Dog.hpp"

Dog::Dog() : _brain(*new Brain()) {

	this->type = "Dog";
	std::cout << "Dog object created" << std::endl;
}

Dog::~Dog() {

	delete &_brain;
	std::cout << "Dog object deleted" << std::endl;
}

Dog::Dog(const Dog& src) : AAnimal(src), _brain(*new Brain())
{
	*this = src;
}

const Dog& Dog::operator=( const Dog& src )
{
	std::cout << "Dog copy asigment" << std::endl;
	if (this != &src)
	{
		this->_brain = src._brain;
	}
	return (*this);
}

void	Dog::makeSound() const {
	
	std::cout << "WOOF" << std::endl;
}

void	Dog::setNewIdea(const std::string& idea)
{
	this->_brain.setNewIdea(idea);
}

void	Dog::showAllIdeas() const
{
	std::cout << this->getType() << " ideas" << std::endl;
	this->_brain.showAllIdeas();
}

void	Dog::copy(const AAnimal& src)
{
	std::cout << "Dog copy..." << std::endl;
	const Dog* tmp = dynamic_cast<const Dog*>(&src);
	if (tmp)
	{
		*this = *tmp;
	}
	else
	{
		std::cout << "Dog copy failed! Rvalue is not a Dog!" << std::endl;
	}
}
