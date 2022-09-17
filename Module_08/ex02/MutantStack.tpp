#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(){}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& src) : std::stack<T, Container>(src) {}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}

template<typename T, typename Container>
const MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& src)
{
	std::stack<T, Container>::operator=(src);
	return *this;
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template<typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template<typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template<typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.end();
}

template<typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

template<typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}
