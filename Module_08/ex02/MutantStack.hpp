#pragma once
#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <iostream>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:

	MutantStack();
	MutantStack(const MutantStack& src);
	~MutantStack();

	const MutantStack&	operator=(const MutantStack& src);

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

};

#include "MutantStack.tpp"

#endif
