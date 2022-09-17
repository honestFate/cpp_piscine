#pragma once
#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>

#define DEF_SIZE 8

class Span
{

public:

	Span();
	Span(size_t N);
	Span(const Span& src);
	~Span();

	const Span&	operator=(const Span& src);

	void	addNumber(int number);
	size_t	shortestSpan() const;
	size_t	longestSpan() const;
	void	printVec() const;
	static int	getRandom();
	void	fillRandom();
	size_t	getSize() const;

private:

	size_t				_size;
	std::vector<int>	_vec;

};

#endif
