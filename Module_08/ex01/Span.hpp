#pragma once
#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <sstream>

#define DEF_SIZE 8

class Span
{

public:

	Span();
	Span(size_t N);
	Span(const Span& src);
	~Span();

	const Span&	operator=(const Span& src);

	void		addNumber(int number);
	size_t		shortestSpan();
	size_t		longestSpan() const;
	void		printVec();
	void		fillRandom();
	size_t		getSize() const;

	static int	getRandom();

	class ContainerReachLimit : public std::exception
	{

	public:

		ContainerReachLimit();
		ContainerReachLimit(const std::string& msg);
		~ContainerReachLimit() throw();

		const char* what() const throw();

	private:

		std::string	_message;

	};

	class NotEnoughItems : public std::exception
	{

	public:

		NotEnoughItems();
		NotEnoughItems(const std::string& msg);
		~NotEnoughItems() throw();

		const char* what() const throw();

	private:

		std::string	_message;

	};
	

private:

	size_t				_size;
	std::vector<int>	_vec;

};

#endif
