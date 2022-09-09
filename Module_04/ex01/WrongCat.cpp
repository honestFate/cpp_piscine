#include "WrongCat.hpp"

WrongCat::WrongCat() {

	this->type = "WrongCat";
	std::cout << "WrongCat object created" << std::endl;
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat object deleted" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {

	*this = src;
}

const WrongCat& WrongCat::operator=(const WrongCat& src) {

	if (this != &src) {
		this->type = src.getType();
	}
	return (*this);
}

void	WrongCat::makeSound() const {
	
	std::cout << "MEOW" << std::endl;
}
