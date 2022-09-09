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
		for (size_t i = 0; i < src.index; i++)
		{
			this->ideas[i] = src.ideas[i];
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
	size_t i = 0;
	for (; i < index; i++)
	{
		std::cout << this->ideas[i] << std::endl;
	}
	if (i == 0)
	{
		std::cout << "*brain is empty*" << std::endl;
	}
}
