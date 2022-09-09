#include "Fixed.hpp"

Fixed::Fixed( void ) : _value( 0 ) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed* Fixed::operator=( const Fixed& f2 ) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f2)
		this->_value = f2.getRawBits();

	return (this);
}

void Fixed::setRawBits( const int raw ) {
	
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	
	return (_value);
}
