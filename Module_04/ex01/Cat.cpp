#include "Cat.hpp"

Cat::Cat() : _brain(*new Brain())
{
	std::cout << "Cat object created" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	delete &_brain;
	std::cout << "Cat object deleted" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), _brain(*new Brain())
{
	*this = src;
}

const Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy asigment" << std::endl;
	if (this != &src)
	{
		this->_brain = src._brain;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}

void	Cat::setNewIdea(const std::string& idea)
{
	this->_brain.setNewIdea(idea);
}

void	Cat::showAllIdeas() const
{
	std::cout << this->getType() << " ideas" << std::endl;
	this->_brain.showAllIdeas();
}

void	Cat::copy(const Animal& src)
{
	std::cout << "Cat copy..." << std::endl;
	const Cat* tmp = dynamic_cast<const Cat*>(&src);
	if (tmp)
	{
		*this = *tmp;
	}
	else
	{
		std::cout << "Cat copy failed! Rvalue is not a Cat!" << std::endl;
	}
}
