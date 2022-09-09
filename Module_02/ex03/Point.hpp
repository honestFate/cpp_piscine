#pragma once
#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {


public:

	Point( void );
	Point( const Fixed& x, const Fixed& y );
	Point( const Point& src );
	~Point( void );

	const Point&	operator=( const Point& src );

	const Fixed&	getX( void ) const;
	const Fixed&	getY( void ) const;

private:

	const Fixed	x;
	const Fixed	y;

};

#endif
