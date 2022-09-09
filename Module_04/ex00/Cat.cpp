#include "Cat.hpp"

Cat::Cat() {

	std::cout << "Cat object created" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {

	std::cout << "Animal object deleted" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {

	*this = src;
}

const Cat& Cat::operator=(const Cat& src) {

	if (this != &src) {
		this->type = src.getType();
	}
	return (*this);
}

void	Cat::makeSound() const {
	
	std::cout << "MEOW" << std::endl;
}
