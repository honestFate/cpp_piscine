#pragma once
#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <ctype.h>

class Converter
{

public:

	Converter();
	Converter(const Converter& src);
	~Converter();

	const Converter&	operator=(const Converter& src);

	void	convert(const std::string& str);

private:

	char	toChar(const std::string& str);
	int		toInt(const std::string& str);
	float	toFloat(const std::string& str);
	double	toDouble(const std::string& str);

};

#endif
