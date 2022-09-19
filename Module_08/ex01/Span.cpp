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
		this->_vec.resize(last - first);
		std::copy(first, last, this->_vec.begin());
		std::cout << "ok " << std::endl;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	std::cout	<< "Trying to add number " << number << " to collection size " << _vec.size()
				<< " and max size: " << _size << std::endl;
	if (this->_vec.size() == this->_size)
	{
		std::stringstream ss;
		ss << "Collection size of " << _vec.size() << " no space left";
		throw ContainerReachLimit(ss.str());
	}
	this->_vec.push_back(number);
}

size_t	Span::shortestSpan()
{
	if (this->_vec.size() < 2)
	{
		std::stringstream ss;
		ss << "In collection size of " << _vec.size() << " can't be found shortest span";
		throw NotEnoughItems(ss.str());
	}
	std::sort(this->_vec.begin(), this->_vec.end()); //sort original vector
	std::vector<long int> transoformed(this->_vec.size() - 1); //creating new empty vector with less one size
	std::transform(this->_vec.begin() + 1, this->_vec.end(), this->_vec.begin(), transoformed.begin(), std::minus<int>()); //fill with *(n + 1) - *n
	return *(std::min_element(transoformed.begin(), transoformed.end()));
}

size_t	Span::longestSpan() const
{
	if (this->_vec.size() < 2)
	{
		std::stringstream ss;
		ss << "In collection size of " << _vec.size() << " can't be found longest span";
		throw NotEnoughItems(ss.str());
	}
	return abs(*(std::max_element(this->_vec.begin(), this->_vec.end()))
		- *(std::min_element(this->_vec.begin(), this->_vec.end())));
}

void	Span::printVec() const
{
	std::cout << "The numbers in vector with size " << this->_vec.size() << " and max size " << this->_size << std::endl;
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

Span::ContainerReachLimit::ContainerReachLimit() : _message("Overflow")
{
	std::cout << "Overflow exception created" << std::endl;
}

Span::ContainerReachLimit::ContainerReachLimit(const std::string& msg) : _message(msg)
{
	std::cout << "Overflow exception " << msg << " created" << std::endl;
}

Span::ContainerReachLimit::~ContainerReachLimit() throw()
{
	std::cout << "Overflow exception deleted" << std::endl;
}

const char* Span::ContainerReachLimit::what() const throw()
{
	return _message.c_str();
}

Span::NotEnoughItems::NotEnoughItems() : _message("Overflow")
{
	std::cout << "Not enough items exception created" << std::endl;
}

Span::NotEnoughItems::NotEnoughItems(const std::string& msg) : _message(msg)
{
	std::cout << "Not enough items exception " << msg << " created" << std::endl;
}

Span::NotEnoughItems::~NotEnoughItems() throw()
{
	std::cout << "Not enough items exception deleted" << std::endl;
}

const char* Span::NotEnoughItems::what() const throw()
{
	return _message.c_str();
}
