#include "Data.hpp"

Data::Data()
{
	std::cout << "Data object created by default constructor" << std::endl;
}

Data::~Data()
{
	std::cout << "Data object with fields:" << std::endl;
	std::cout << "_x = " << this->_x << ", _c = " << this->_c << std::endl;
	std::cout << "was deleted" << std::endl;
}

Data::Data(const Data& src) : _c(src.getC()), _x(src.getX()) {}

const Data& Data::operator=(const Data& src)
{
	if (this != &src)
	{
		this->_c = src.getC();
		this->_x = src.getX();
	}
	return (*this);
}

int		Data::getX() const
{
	return this->_x;
}

void	Data::setX(int x)
{
	this->_x = x;
}

char	Data::getC() const
{
	return this->_c;
}

void	Data::setC(char c)
{
	this->_c = c;
}

