#include "Animal.hpp"

Animal::Animal() : type("Untyped") {

	std::cout << "Animal object created" << std::endl;
}

Animal::~Animal() {

	std::cout << "Animal object deleted" << std::endl;
	return;
}

Animal::Animal(const Animal& src) {

	*this = src;
}

const Animal& Animal::operator=( const Animal& src ) {

	if (this != &src) {
		this->type = src.type;
	}
	return (*this);
}

void	Animal::makeSound() const {

	std::cout << "*Unintelligible sounds*" << std::endl;
}

const std::string&	Animal::getType() const {
	
	return this->type;
}
