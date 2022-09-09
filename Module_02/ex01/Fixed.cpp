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

Fixed::Fixed( const int src ) {

	_value = src << _fractionalBitsNumber; 
}

Fixed::Fixed( const float src ) {

	_value = (int)roundf(src * (1 << _fractionalBitsNumber));
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

float	Fixed::toFloat( void ) const {

	return ((float)_value / (1 << _fractionalBitsNumber));
}

int	Fixed::toInt( void ) const {

	return (_value >> _fractionalBitsNumber);
}

std::ostream&	operator<<(std::ostream& o, const Fixed& fp) {

	return (o << fp.toFloat());
}

const int	Fixed::_fractionalBitsNumber = 8;
