#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{

public:

	Fixed( void );
	Fixed( const Fixed& src );
	Fixed( const int src );
	Fixed( const float src );
	~Fixed( void );

	Fixed*	operator=( const Fixed& f2 );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	static const int	_fractionalBitsNumber;
	int					_value;

};

std::ostream&	operator<<(std::ostream& o, const Fixed& fp);

#endif
