#include "Fixed.hpp"

Fixed::Fixed( void ) : _value( 0 ) {}

Fixed::~Fixed( void ) {}

Fixed::Fixed( const Fixed& src ) {

	*this = src;
}

Fixed::Fixed( const int src ) {

	_value = src << _fractionalBitsNumber; 
}

Fixed::Fixed( const float src ) {

	_value = (int)roundf(src * (1 << _fractionalBitsNumber));
}

const Fixed& Fixed::operator=( const Fixed& f2 ) {

	if (this != &f2)
		this->_value = f2.getRawBits();

	return (*this);
}

bool	Fixed::operator>( const Fixed& fp2 ) const {
	
	return this->getRawBits() > fp2.getRawBits();
}

bool	Fixed::operator<( const Fixed& fp2 ) const {
	
	return this->getRawBits() < fp2.getRawBits();
}

bool	Fixed::operator>=( const Fixed& fp2 ) const {
	
	return this->getRawBits() >= fp2.getRawBits();
}

bool	Fixed::operator<=( const Fixed& fp2 ) const {
	
	return this->getRawBits() <= fp2.getRawBits();
}

bool	Fixed::operator==( const Fixed& fp2 ) const {
	
	return this->getRawBits() == fp2.getRawBits();
}

bool	Fixed::operator!=( const Fixed& fp2 ) const {
	
	return this->getRawBits() != fp2.getRawBits();
}

Fixed	Fixed::operator+( const Fixed& fp2 ) const {

	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() + fp2.getRawBits());

	return tmp;
}

Fixed	Fixed::operator-( const Fixed& fp2 ) const {

	Fixed	tmp;

	tmp._value = this->getRawBits() - fp2.getRawBits();

	return tmp;
}

Fixed	Fixed::operator*( const Fixed& fp2 ) const {

	Fixed	tmp;

	tmp._value = ((long long int)this->getRawBits() * fp2.getRawBits()) >> _fractionalBitsNumber;
	
	return tmp;
}

Fixed	Fixed::operator/( const Fixed& fp2 ) const {

	Fixed	tmp;

	tmp._value = ((long long int)this->getRawBits() << _fractionalBitsNumber) / fp2.getRawBits();

	return tmp;
}

const Fixed&	Fixed::operator++() {

	++_value;

	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed tmp(*this);

	++_value;

	return tmp;
}

const Fixed&	Fixed::operator--() {

	--_value;

	return *this;
}

Fixed	Fixed::operator--( int ) {

	Fixed tmp(*this);

	--_value;

	return tmp;
}

void Fixed::setRawBits( const int raw ) {

	_value = raw;
}

int Fixed::getRawBits( void ) const {

	return _value;
}

float	Fixed::toFloat( void ) const {

	return (float)_value / (1 << _fractionalBitsNumber);
}

int	Fixed::toInt( void ) const {

	return _value >> _fractionalBitsNumber;
}

std::ostream&	operator<<(std::ostream& o, const Fixed& fp) {

	return o << fp.toFloat();
}

Fixed&	Fixed::min( Fixed& fp1, Fixed& fp2 ) {
	return fp1 <= fp2 ? fp1 : fp2;
}

const Fixed&	Fixed::min( const Fixed& fp1, const Fixed& fp2 ) {
	return fp1 <= fp2 ? fp1 : fp2;
}

Fixed&	Fixed::max( Fixed& fp1, Fixed& fp2 ) {
	return fp1 >= fp2 ? fp1 : fp2;
}

const Fixed&	Fixed::max( const Fixed& fp1, const Fixed& fp2 ) {
	return fp1 >= fp2 ? fp1 : fp2;
}

const int	Fixed::_fractionalBitsNumber = 8;
