#include "Form.hpp"

Form::Form() :
_name(FORM_DEFAULT_NAME),
_isSigned(false),
_gradeToSign(1),
_gradeToExecute(1)
{
	std::cout << *this << ". Created by default constructor" << std::endl;
}

Form::Form(const std::string& name, size_t gradeToSign, size_t gradeToExecute) :
_name(name),
_isSigned(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	isValidGrade(gradeToSign);
	isValidGrade(gradeToExecute);
	std::cout << *this << ". Created" << std::endl;
}

Form::Form(const Form& src) :
_name(src._name),
_isSigned(false),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{
	std::cout << "Form copy constructor" << std::endl;
	*this = src;
}

Form::~Form()
{
	std::cout << *this << ". Deleted" << std::endl;
}

const Form& Form::operator=(const Form& src)
{
	(void)src;
	std::cout << "Form copy assigment" << std::endl;
	std::cout << "Too many constants here. What are you want from that operation?" << std::endl;
	return (*this);
}

const std::string&	Form::getName() const
{
	return this->_name;	
}

bool	Form::getIsSigned() const
{
	return this->_isSigned;
}

size_t	Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

size_t	Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "Exception Form::GradeTooHighException created" << std::endl;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "Exception Form::GradeTooHighException deleted" << std::endl;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "grade was too high";
}

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "Exception Form::GradeTooLowException created" << std::endl;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "Exception Form::GradeTooLowException deleted" << std::endl;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "grade was too low";
}

void	Form::isValidGrade(size_t grade) const
{
	if (grade > FORM_LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	if (grade < FORM_HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& o, const Form& obj)
{
	return o << std::boolalpha
			<< "Form " << obj.getName()
			<< ", signed - " << obj.getIsSigned()
			<< ", grade to sign - " << obj.getGradeToSign()
			<< ", grade to execute - " << obj.getGradeToExecute();
}
