#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name(DEFAULT_NAME),
_grade(LOWEST_GRADE)
{
	std::cout << GREEN << "Bureaucrat object created by default constructor" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << *this << " deleted" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string& name, size_t grade) :
_name(name),
_grade(grade)
{
	try
	{
		isValidGrade(grade);
	}
	catch(const std::exception& e)
	{
		_grade = LOWEST_GRADE;
		std::cout << RED << "Bureaucrat " << _name << " called execption" << RESET << std::endl;
		throw;
	}
	std::cout << GREEN << *this << " created" << RESET << std::endl;
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
	size_t tmp = this->_grade;
	this->increaseGrade();

	return tmp;
}

size_t	Bureaucrat::operator--()
{
	return this->decreaseGrade();
}

size_t	Bureaucrat::operator--(int)
{
	size_t tmp = this->_grade;
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
	this->isValidGrade(_grade - 1);
	(this->_grade)--;
	return this->_grade;
}

size_t	Bureaucrat::decreaseGrade()
{
	this->isValidGrade(_grade + 1);
	(this->_grade)++;
	return this->_grade;
}

void	Bureaucrat::isValidGrade(size_t grade) const
{
	if (grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	if (grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED"grade was too high"RESET;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED"grade was too low"RESET;
}

std::ostream&	operator<<(std::ostream&o, const Bureaucrat& obj)
{
	return o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
}
