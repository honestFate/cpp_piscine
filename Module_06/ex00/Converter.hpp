#pragma once
#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cerrno>
#include <cfloat>
#include <cmath>
#include <ctype.h>

class Converter
{

public:

	Converter();
	Converter(const std::string& str);
	Converter(const Converter& src);
	~Converter();

	const Converter&	operator=(const Converter& src);

	void				convert() const;
	const std::string&	getSourceStr() const;
	void				setSourceStr(const std::string& str);


private:

	enum	RealType
	{
		charType,
		integerType,
		floatType,
		doubleType,
		undefinedType,
		empty
	};

	std::string	_sourceStr;

	RealType	identifyStrType() const;
	bool		isCharStr() const;
	bool		isIntegerStr() const;
	bool		isFloatStr() const;
	bool		isDoubleStr() const;
	bool		isEmptyStr() const;
	bool		isFloatPointNmb() const;

	void		convertCharStr() const;
	void		convertIntStr() const;
	void		convertFloatStr() const;
	void		convertDoubleStr() const;

	std::string	truncateToChar(int integer) const;
	std::string	truncateToChar(double dbl) const;

	std::string	truncateToInt(double dbl) const;

	std::string	truncateToFloat(double dbl) const;

};

#endif
