#include "Brain.hpp"

Brain::Brain() : index(0)
{
	std::cout << "Brain object created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain object deleted" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
}

const Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brainwashing..." << std::endl;
	if (this != &src)
	{
		size_t i = 0;
		for (; i < src.index; i++)
		{
			this->ideas[i] = src.ideas[i];
		}
		for (; i < BRAIN_CAPACITY; i++)
		{
			this->ideas[i].clear();
		}
		this->index = src.index;
	}
	return (*this);
}

void	Brain::setNewIdea(const std::string& idea)
{
	this->ideas[this->index] = idea;
	(this->index)++;
	if (this->index == BRAIN_CAPACITY)
	{
		this->index = 0;
	}
}

void	Brain::showAllIdeas() const
{
	bool isEmpty = true;
	size_t i = 0;
	for (; i < BRAIN_CAPACITY; i++)
	{
		if (!this->ideas[i].empty())
		{
			std::cout << this->ideas[i] << std::endl;
			isEmpty = false;
		}
	}
	if (isEmpty)
	{
		std::cout << "*brain is empty*" << std::endl;
	}
}
