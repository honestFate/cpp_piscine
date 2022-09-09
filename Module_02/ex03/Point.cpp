#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {}

Point::~Point( void ) {}

Point::Point( const Point& src ) : x(src.getX()), y(src.getY()) {}

Point::Point( const Fixed& x, const Fixed& y ) : x(x), y(y) {}

const Point& Point::operator=( const Point& src ) {

	return (*this);
}

const Fixed&	Point::getX( void ) const {
	
	return x;
}

const Fixed&	Point::getY( void ) const {

	return y;
}
