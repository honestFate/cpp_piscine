#include "Span.hpp"

Span::Span() : _size(DEF_SIZE)
{
	std::cout << "Span object with default size of " << DEF_SIZE << " created" << std::endl;
}

Span::Span(size_t N) : _size(N)
{
	std::cout << "Span object with size of " << N << " created" << std::endl;
}

Span::Span(const Span& src) : _size(src.getSize()), _vec(src._vec)
{
	std::cout << "Span object with size of " << _size << " copied" << std::endl;
}

Span::~Span() {}

const Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		std::vector<int>::const_iterator first = src._vec.begin();
		std::vector<int>::const_iterator last;
		if (src._vec.begin() + this->_size >= src._vec.end())
		{
			last = src._vec.end();
		}
		else
		{
			last = src._vec.begin() + this->_size;
		}
		std::copy(first, last, this->_vec.begin());
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	std::cout << "size: " << _vec.size() << " max:" << _size << std::endl;
	if (this->_vec.size() == this->_size)
	{
		throw std::exception();
	}
	this->_vec.push_back(number);
}

size_t	Span::shortestSpan() const
{
	if (this->_vec.size() < 2)
	{
		throw std::exception();
	}
	std::vector<long int> transoformed(this->_vec.size() - 1);
	std::transform(this->_vec.begin(), this->_vec.end() - 1, this->_vec.begin() + 1, transoformed.begin(), std::minus<int>());
	std::transform(transoformed.begin(), transoformed.end(), transoformed.begin(), static_cast<long int (*)(long int)>(std::abs));
	return *(std::min_element(transoformed.begin(), transoformed.end()));
}

size_t	Span::longestSpan() const
{
	return abs(*(std::max_element(this->_vec.begin(), this->_vec.end()))
		- *(std::min_element(this->_vec.begin(), this->_vec.end())));
}

void	Span::printVec() const
{
	std::cout << "The numbers in vector are: " << std::endl;
	std::copy(this->_vec.begin(), this->_vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int	Span::getRandom()
{
	return std::rand() % 100;
}

void	Span::fillRandom()
{
	std::srand(time(0));
	_vec.resize(_size);
	std::generate_n(this->_vec.begin(), this->_size, getRandom);
}

size_t	Span::getSize() const
{
	return _size;
}
