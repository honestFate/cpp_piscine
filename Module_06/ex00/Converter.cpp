#include "Converter.hpp"

Converter::Converter()
{
	//std::cout << "Converter object created by default constructor" << std::endl;
}

Converter::~Converter()
{
	//std::cout << "Converter object deleted" << std::endl;
}

Converter::Converter(const Converter& src)
{
	static_cast<void>(src);
	return;
}

const Converter& Converter::operator=(const Converter& src)
{
	static_cast<void>(src);
	return (*this);
}

void	Converter::convert()
{
	double	dbl;
	bool	dblOverflow = false;

	if (this->_str.length() == 0)
	{
		std::cout << "String is empty!" << std::endl;
		return;
	}
	std::cout << "double: ";
	if (this->_str.length() == 1)
	{
		dbl = static_cast<double>(this->_str[0]);
		std::cout << dbl;
	}
	else
	{
		try
		{
			dbl = this->toDouble(this->_str);
			std::cout << dbl;
		}
		catch(const std::exception& e)
		{
			dblOverflow = true;
			std::cerr << e.what();
			return;
		}
	}
	std::cout << std::endl;

	std::cout << "float: ";
	if (dblOverflow)
	{
		std::cout << "Overflow!" << std::endl;
	}
	else
	{
		float	flt = static_cast<float>(dbl);
		if (static_cast<double>(flt) != dbl)
		{
			std::cout << "Overflow!";
		}
		else
		{
			std::cout << flt << "f";
		}
	}
	std::cout << std::endl;

	std::cout << "int: ";
	try
	{
		int integer = this->toInt(this->_str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "char: ";
	try
	{
		int integer = this->toInt(this->_str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

char	Converter::toChar(const std::string& str)
{
	char	c;

	if (str.length() == 1 && !isdigit(str[0]))
	{
		return str[0];
	}

	int	intRepr = this->toInt(str);
	if (intRepr > std::numeric_limits<char>::max()
		|| intRepr < std::numeric_limits<char>::min())
	{
		throw std::invalid_argument("Overflow!");
	}

	c = static_cast<char>(intRepr);
	if (!isprint(c))
	{
		throw std::invalid_argument("Non displayable");
	}

	return c;
}

int		Converter::toInt(const std::string& str)
{
	char	*end;

	errno = 0;
    long int res = strtol(str.c_str(), &end, 10);
    if ((errno == ERANGE && res == std::numeric_limits<long int>::max())
		|| res > std::numeric_limits<int>::max())
	{
        throw std::invalid_argument("Overflow");
    }
    if ((errno == ERANGE && res == std::numeric_limits<long int>::min())
		|| res < std::numeric_limits<int>::min())
	{
        throw std::invalid_argument("Underflow");
    }
    if (*end != '\0')
	{
        throw std::invalid_argument("Invalid symbols");
    }

    return static_cast<int>(res);
}

double	Converter::toDouble(const std::string& str)
{
	char *end;
	errno = 0;
	double result = strtod(str.c_str(), &end);

	if (*end == 'f')
	{
		++end;
	}
	while (isspace(*end))
	{
		++end;
	}

	if (*end && *end != 'f')
	{
		throw std::invalid_argument("Invalid symbols");
	}
	if (errno == ERANGE && fabs(result) == HUGE_VAL)
	{
		throw std::invalid_argument("Overflow");
	}
	if (errno == ERANGE && fabs(*end) <= DBL_MIN)
	{
		throw std::invalid_argument("Underflow");
	}

	return result;
}

bool	Converter::isValidNumeric(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		return true;
	}

	const char	*ptr = str.c_str();
	while (isspace(*ptr))
		++ptr;
	if (*ptr == '+' || *ptr == '-')
		++ptr;
	if (!isdigit(*ptr))
		return false;
	while (isdigit(*ptr))
		++ptr;
	if (*ptr != '.' && *ptr != ',')
		++ptr;
	if (*ptr == 'f')
	{
		++ptr;
		while (isspace(*ptr))
			++ptr;
		if (*ptr)
			return false;
		return true;
	}
	if (!isdigit(*ptr))
		return false;
	while (isdigit(*ptr))
		++ptr;
	if (*ptr == 'f')
		++ptr;
	while (isspace(*ptr))
		++ptr;
	if (*ptr)
		return false;
	return true;
}
