#include "Converter.hpp"

Converter::Converter() {}

Converter::~Converter() {}

Converter::Converter(const std::string& str) : _sourceStr(str) {}

Converter::Converter(const Converter& src) : _sourceStr(src.getSourceStr()) {}

const Converter& Converter::operator=(const Converter& src)
{
	if (this != &src)
	{
		this->_sourceStr = src._sourceStr;
	}
	return (*this);
}

const std::string&	Converter::getSourceStr() const
{
	return this->_sourceStr;
}

void	Converter::setSourceStr(const std::string& str)
{
	this->_sourceStr = str;
}

void	Converter::convert() const
{
	RealType strType = identifyStrType();
	void (Converter::*convertStr[4])() const = {
		&Converter::convertCharStr,
		&Converter::convertIntStr,
		&Converter::convertFloatStr,
		&Converter::convertDoubleStr
	};

	if (strType == empty)
	{
		std::cout << "String not setted!" << std::endl;
		return;
	}
	if (strType == undefinedType)
	{
		std::cout << "Can't convert this string:(" << std::endl;
		return;
	}
	(this->*convertStr[strType])();
}

Converter::RealType	Converter::identifyStrType() const
{
	bool (Converter::*isType[5])() const = {
		&Converter::isCharStr,
		&Converter::isIntegerStr,
		&Converter::isFloatStr,
		&Converter::isDoubleStr,
		&Converter::isEmptyStr
	};
	for (size_t i = 0; i < 5; i++)
	{
		if ((this->*isType[i])())
		{
			return static_cast<RealType>(i);
		}
	}
	return undefinedType;
}

bool		Converter::isCharStr() const
{
	return this->_sourceStr.length() == 1 && !isdigit(this->_sourceStr[0]);
}

bool		Converter::isIntegerStr() const
{
	const char * ptr = this->_sourceStr.c_str();

	if (*ptr == '+' || *ptr == '-')
	{
		++ptr;
	}
	if (isdigit(*ptr))
	{
		while (*ptr && isdigit(*ptr))
		{
			++ptr;
		}
	}
	return *ptr == '\0';
}

bool		Converter::isFloatStr() const
{
	if (this->_sourceStr == "nanf" || this->_sourceStr == "+inff" || this->_sourceStr == "-inff"
		|| (this->isFloatPointNmb() && this->_sourceStr.back() == 'f'))
	{
		return true;
	}
	return false;
}

bool	Converter::isDoubleStr() const
{
	if (this->_sourceStr == "nan" || this->_sourceStr == "+inf" || this->_sourceStr == "-inf"
		|| (this->isFloatPointNmb() && this->_sourceStr.back() != 'f'))
	{
		return true;
	}
	return false;
}

bool	Converter::isEmptyStr() const
{
	if (this->_sourceStr.empty())
	{
		return true;
	}
	return false;
}

bool	Converter::isFloatPointNmb() const
{
	bool digitAfterDot = false;
	bool dot = false;
	const char * ptr = this->_sourceStr.c_str();

	if (*ptr == '+' || *ptr == '-')
	{
		++ptr;
	}
	while (*ptr)
	{
		if (isdigit(*ptr) && dot)
		{
			digitAfterDot = true;
		}
		if (*ptr == '.')
		{
			if (dot)
			{
				return false;
			}
			dot = true;
		}
		else if (*ptr == 'f')
		{
			if (*(ptr + 1))
			{
				return false;
			}
			break;
		}
		else if (!isdigit(*ptr))
		{
			return false;
		}
		++ptr;
	}
	if (!digitAfterDot)
	{
		return false;
	}
	return true;
}

void	Converter::convertCharStr() const
{
	char c = this->_sourceStr[0];

	std::cout	<< std::fixed << std::setprecision(1)
				<< "char: " << c << std::endl
				<< "int: " << static_cast<int>(c) << std::endl
				<< "float: " << static_cast<float>(c) << 'f' << std::endl
				<< "double: " << static_cast<double>(c) << std::endl;
}

void	Converter::convertIntStr() const
{
	char * end;

	errno = 0;
	long int longRes = strtol(this->_sourceStr.c_str(), &end, 10);
	if ((errno == ERANGE && longRes == std::numeric_limits<long int>::max())
		|| longRes > std::numeric_limits<int>::max())
	{
		std::cout << "Can't convert this INTEGER, because - OVERFLOW" << std::endl;
		return;
	}
	if ((errno == ERANGE && longRes == std::numeric_limits<long int>::min())
		|| longRes < std::numeric_limits<int>::min())
	{
		std::cout << "Can't convert this INTEGER, because - UNDERFLOW" << std::endl;
		return;
	}
	if (*end)
	{
		std::cout << "Can't convert this DOUBLE, because - ???" << std::endl;
		return;
	}
	int intRes = static_cast<int>(longRes);
	std::cout	<< std::fixed << std::setprecision(1)
				<< "char: " << truncateToChar(intRes) << std::endl
				<< "int: " << intRes << std::endl
				<< "float: " << static_cast<float>(intRes) << 'f' << std::endl
				<< "double: " << static_cast<double>(intRes) << std::endl;
}

void	Converter::convertFloatStr() const
{
	char * end;

	errno = 0;
	double dbl = strtod(this->_sourceStr.c_str(), &end);

	if (errno == ERANGE && fabs(dbl) == HUGE_VAL)
	{
		std::cout << errno << " ";
		std::cout << "Can't convert this FLOAT, because - OVERFLOW" << std::endl;
		return;
	}
	if (errno == ERANGE && fabs(dbl) <= DBL_MIN)
	{
		std::cout << "Can't convert this FLOAT, because - UNDERFLOW" << std::endl;
		return;
	}
	if (*end != 'f')
	{
		std::cout << "Can't convert this FLOAT, because - ???" << std::endl;
		return;
	}
	if (isfinite(dbl))
	{
		if (dbl < std::numeric_limits<float>::lowest()
			|| dbl > std::numeric_limits<float>::max())
		{
			std::cout << "Can't convert this FLOAT, because - OVERFLOW" << std::endl;
			return;
		}
	}
	float fltRes = static_cast<float>(dbl);
	if (ceilf(fltRes) == fltRes)
	{
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout	<< "char: " << truncateToChar(static_cast<double>(fltRes)) << std::endl
				<< "int: " << truncateToInt(static_cast<double>(fltRes)) << std::endl
				<< "float: " << fltRes << 'f' << std::endl
				<< "double: " << dbl << std::endl;
}

void	Converter::convertDoubleStr() const
{
	char * end;

	errno = 0;
	double dblRes = strtod(this->_sourceStr.c_str(), &end);

	if (errno == ERANGE && fabs(dblRes) == HUGE_VAL)
	{
		std::cout << "Can't convert this DOUBLE, because - OVERFLOW" << std::endl;
		return;
	}
	if (errno == ERANGE && fabs(dblRes) <= DBL_MIN)
	{
		std::cout << "Can't convert this DOUBLE, because - UNDERFLOW" << std::endl;
		return;
	}
	if (*end)
	{
		std::cout << "Can't convert this DOUBLE, because - ???" << std::endl;
		return;
	}
	if (ceil(dblRes) == dblRes)
	{
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout	<< "char: " << truncateToChar(dblRes) << std::endl
				<< "int: " << truncateToInt(dblRes) << std::endl
				<< "float: " << truncateToFloat(dblRes) << 'f' << std::endl
				<< "double: " << dblRes << std::endl;
}

std::string	Converter::truncateToChar(int integer) const
{
	std::string str;

	if (integer > std::numeric_limits<char>::max()
		|| integer < std::numeric_limits<char>::lowest())
	{
		str = "Overflow!";
	}
	else
	{
		char c = static_cast<char>(integer);
		if (isprint(c))
		{
			str = "'";
			str += c;
			str += "'";
		}
		else
		{
			str = "Non displayable";
		}
	}
	return str;
}

std::string	Converter::truncateToChar(double dbl) const
{
	std::string str;
	
	if (!isfinite(dbl))
	{
		str = "impossible";
	}
	else if (dbl > std::numeric_limits<char>::max()
		|| dbl < std::numeric_limits<char>::lowest())
	{
		str = "Overflow!";
	}
	else
	{
		char c = static_cast<char>(dbl);
		if (isprint(c))
		{
			str = "'";
			str += c;
			str += "'";
		}
		else
		{
			str = "Non displayable";
		}
	}
	return str;
}

std::string	Converter::truncateToInt(double dbl) const
{
	std::string str;
	
	if (!isfinite(dbl))
	{
		str = "impossible";
	}
	else if (dbl > std::numeric_limits<int>::max()
		|| dbl < std::numeric_limits<int>::lowest())
	{
		str = "Overflow!";
	}
	else
	{
		int i = static_cast<int>(dbl);
		std::ostringstream ss;
     	ss << i;
		str = ss.str();
	}
	return str;
}


std::string	Converter::truncateToFloat(double dbl) const
{
	std::string str;
	
	if (isfinite(dbl) && (dbl > std::numeric_limits<float>::max()
		|| dbl < std::numeric_limits<float>::lowest()))
	{
		str = "Overflow!";
	}
	else
	{
		float flt = static_cast<float>(dbl);
		std::ostringstream ss;
		if (ceilf(flt) == flt)
		{
			ss << std::fixed << std::setprecision(1);
		}
     	ss << flt;
		str = ss.str();
	}
	return str;
}
