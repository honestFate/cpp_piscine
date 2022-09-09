#pragma once
#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

#define BRAIN_CAPACITY 100

class Brain {


public:

	Brain();
	Brain(const Brain& src);
	~Brain();

	const Brain&	operator=(const Brain& src);

	void	setNewIdea(const std::string& idea);
	void	showAllIdeas() const;

private:

	std::string		ideas[BRAIN_CAPACITY];
	unsigned int	index;

};

#endif
