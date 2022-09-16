#pragma once
#ifndef DATA_H
#define DATA_H

#include <iostream>

struct Data
{

public:

	Data();
	Data(const Data& src);
	~Data();

	const Data&	operator=(const Data& src);

	int		getX() const;
	void	setX(int x);
	char	getC() const;
	void	setC(char c);

private:

	char	_c;
	int		_x;

};

#endif
