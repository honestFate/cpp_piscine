#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{

public:

	Fixed( void );
	Fixed( const Fixed& fixed );
	~Fixed( void );

	Fixed*	operator=( const Fixed& f2 );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );

private:

	static const int _fractionalBitsNumber = 8;
	int _value;

};

#endif
