#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Untyped") {

	std::cout << "WrongAnimal object created" << std::endl;
}

WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal object deleted" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {

	*this = src;
}

const WrongAnimal& WrongAnimal::operator=( const WrongAnimal& src ) {

	if (this != &src) {
		this->type = src.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const {

	std::cout << "*Unintelligible sounds*" << std::endl;
}

const std::string&	WrongAnimal::getType() const {
	
	return this->type;
}
