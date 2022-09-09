#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name(BUREAUCRAT_DEFAULT_NAME),
_grade(BUREAUCRAT_LOWEST_GRADE)
{
	std::cout << "Bureaucrat object created by default constructor" << std::endl;
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
		_grade = BUREAUCRAT_LOWEST_GRADE;
		std::cout << "Bureaucrat " << _name << " called execption" << std::endl;
		throw;
	}
	std::cout << *this << " created" << std::endl;
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
	if (grade > BUREAUCRAT_LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	if (grade < BUREAUCRAT_HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "Exception Bureaucrat::GradeTooHighException created" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "Exception Bureaucrat::GradeTooHighException deleted" << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade was too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "Exception Bureaucrat::GradeTooLowException created" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "Exception Bureaucrat::GradeTooLowException deleted" << std::endl;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade was too low";
}

bool	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		return true;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
	return false;
}

std::ostream&	operator<<(std::ostream&o, const Bureaucrat& obj)
{
	return o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
}
