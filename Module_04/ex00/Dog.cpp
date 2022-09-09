#include "Dog.hpp"

Dog::Dog() {

	this->type = "Dog";
	std::cout << "Dog object created" << std::endl;
}

Dog::~Dog() {

	std::cout << "Dog object deleted" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {

	*this = src;
}

const Dog& Dog::operator=( const Dog& src ) {

	if (this != &src) {
		this->type = src.getType();
	}
	return (*this);
}

void	Dog::makeSound() const {
	
	std::cout << "WOOF" << std::endl;
}
