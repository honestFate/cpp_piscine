#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

template<typename T>
class Array
{

public:

	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();

	const Array&	operator=(const Array& src);
	T&				operator[](int index);

	size_t	size() const;

private:

	T*		_array;
	size_t	_size;

};

#include "Array.tpp"

#endif
