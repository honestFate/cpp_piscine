#include "Converter.hpp"

Converter::Converter()
{
	std::cout << "Converter object created by default constructor" << std::endl;
}

Converter::~Converter()
{
	std::cout << "Converter object deleted" << std::endl;
}

Converter::Converter(const Converter& src)
{
	return;
}

const Converter& Converter::operator=(const Converter& src)
{
	static_cast<void>(src);
	return (*this);
}

void	Converter::convert(const std::string& str)
{
	if (str.length() == 0)
	{
		std::cout << "String is empty!" << std::endl;
		return;
	}

	try
	{
		std::cout << "char: ";
		std::cout << this->toChar(str) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "int: ";
		std::cout << this->toInt(str) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "float: ";
		std::cout << this->toFloat(str) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "double: ";
		std::cout << this->toDouble(str) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

char	toChar(const std::string& str)
{
	if (str.length() == 1)
	{
		return str[0];
	}
	
	throw std::invalid_argument("Non displayable");
}
