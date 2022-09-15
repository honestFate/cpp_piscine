#pragma once
#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

class Integer
{

public:

	Integer();
	Integer(int x);
	Integer(const Integer& src);
	~Integer();

	const Integer&	operator=(const Integer& src);
	int				operator++();

	int	getX() const;
	void setX(int x);

private:

	int	_x;

};

#endif
