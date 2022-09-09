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

	const Fixed&	operator=( const Fixed& fp2 );
	bool			operator>( const Fixed& fp2 ) const;
	bool			operator<( const Fixed& fp2 ) const;
	bool			operator>=( const Fixed& fp2 ) const;
	bool			operator<=( const Fixed& fp2 ) const;
	bool			operator==( const Fixed& fp2 ) const;
	bool			operator!=( const Fixed& fp2 ) const;
	Fixed			operator+( const Fixed& fp2 ) const;
	Fixed			operator-( const Fixed& fp2 ) const;
	Fixed			operator*( const Fixed& fp2 ) const;
	Fixed			operator/( const Fixed& fp2 ) const;
	const Fixed&	operator++();
	Fixed			operator++( int );
	const Fixed&	operator--();
	Fixed			operator--( int );

	int				getRawBits( void ) const;
	void			setRawBits( const int raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;

	static Fixed&		min( Fixed& fp1, Fixed& fp2 );
	static const Fixed&	min( const Fixed& fp1, const Fixed& fp2 );
	static Fixed&		max( Fixed& fp1, Fixed& fp2 );
	static const Fixed&	max( const Fixed& fp1, const Fixed& fp2 );

private:

	static const int _fractionalBitsNumber;
	int _value;

};

std::ostream&	operator<<(std::ostream& o, const Fixed& fp);

#endif
