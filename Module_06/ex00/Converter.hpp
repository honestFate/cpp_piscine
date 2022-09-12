#pragma once
#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <iomanip>
#include <cerrno>
#include <cfloat>
#include <cmath>


class Converter
{

public:

	Converter();
	Converter(const Converter& src);
	~Converter();

	const Converter&	operator=(const Converter& src);

	void	convert();

private:

	std::string	_str;

	char	toChar(const std::string& str);
	int		toInt(const std::string& str);
	float	toFloat(const std::string& str);
	double	toDouble(const std::string& str);
	bool	isValidNumeric(const std::string& str);

};

#endif
