#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat object created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat object deleted" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return (*this);
}

size_t	Bureaucrat::operator++()
{
	return this->increaseGrade();
}

size_t	Bureaucrat::operator++(int)
{
	size_t tmp = this->getGrade();
	this->increaseGrade();

	return tmp;
}

size_t	Bureaucrat::operator--()
{
	return this->decreaseGrade();
}

size_t	Bureaucrat::operator--(int)
{
	size_t tmp = this->getGrade();
	this->decreaseGrade();

	return tmp;
}

const std::string&	Bureaucrat::getName() const
{
	return this->_name;
}

size_t	Bureaucrat::getGrade() const
{
	return this->_grade;
}

size_t	Bureaucrat::increaseGrade()
{
	if (this->getGrade() > HIGHEST_GRADE)
	{
		--(this->_grade);
	}
	return this->getGrade();
}

size_t	Bureaucrat::decreaseGrade()
{
	
}
