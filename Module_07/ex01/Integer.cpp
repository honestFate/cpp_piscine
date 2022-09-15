#include "Integer.hpp"

Integer::Integer() : _x(0)
{
	std::cout << "Integer object created by default constructor" << std::endl;
}

Integer::~Integer()
{
	std::cout << "Integer object deleted" << std::endl;
}

Integer::Integer(int x) : _x(x)
{
	std::cout << "Integer object created with " << x << " value" << std::endl;
}

Integer::Integer(const Integer& src)
{
	*this = src;
}

const Integer& Integer::operator=(const Integer& src)
{
	if (this != &src)
	{
		this->_x = src.getX();
	}
	return (*this);
}

int	Integer::operator++()
{
	++(this->_x);

	return this->_x;
}

int	Integer::getX() const
{
	return this->_x;
}

void Integer::setX(int x)
{
	this->_x = x;
}
