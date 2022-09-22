#include "AForm.hpp"

AForm::AForm() :
_name(AFORM_DEFAULT_NAME),
_isSigned(false),
_gradeToSign(1),
_gradeToExecute(1)
{
	std::cout << *this << ". Created by default constructor" << std::endl;
}

AForm::AForm(const std::string& name, size_t gradeToSign, size_t gradeToExecute) :
_name(name),
_isSigned(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	isValidGrade(gradeToSign);
	isValidGrade(gradeToExecute);
	std::cout << *this << ". Created" << std::endl;
}

AForm::AForm(const AForm& src) :
_name(src._name),
_isSigned(false),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{
	std::cout << "AForm copy constructor" << std::endl;
	*this = src;
}

AForm::~AForm()
{
	std::cout << *this << ". Deleted" << std::endl;
}

const AForm& AForm::operator=(const AForm& src)
{
	(void)src;
	std::cout << "AForm copy assigment" << std::endl;
	std::cout << "Too many constants here. What are you want from that operation?" << std::endl;
	return (*this);
}

const std::string&	AForm::getName() const
{
	return this->_name;	
}

bool	AForm::getIsSigned() const
{
	return this->_isSigned;
}

size_t	AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

size_t	AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return RED"grade was too high"RESET;
}

AForm::GradeTooLowException::GradeTooLowException() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return RED"grade was too low"RESET;
}

AForm::FormNotSigned::FormNotSigned() {}

AForm::FormNotSigned::~FormNotSigned() throw() {}

const char*	AForm::FormNotSigned::what() const throw()
{
	return RED"tryed to execute not signed form"RESET;
}

AForm::AlreadySigned::AlreadySigned() {}

AForm::AlreadySigned::~AlreadySigned() throw() {}

const char*	AForm::AlreadySigned::what() const throw()
{
	return RED"form already signed"RESET;
}

void	AForm::isValidGrade(size_t grade) const
{
	if (grade > AFORM_LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	if (grade < AFORM_HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
}

void	AForm::beSigned(const Bureaucrat& executor)
{
	if (this->_isSigned)
	{
		throw AlreadySigned();
	}
	else
	{
		if (executor.getGrade() <= this->_gradeToSign)
		{
			this->_isSigned = true;
		}
		else
		{
			throw GradeTooLowException();
		}
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned)
	{
		if (executor.getGrade() <= this->_gradeToExecute)
		{
			this->execTarget();
		}
		else
		{
			throw GradeTooLowException();
		}
	}
	else
	{
		throw FormNotSigned();
	}
}

std::ostream&	operator<<(std::ostream& o, const AForm& obj)
{
	return o << std::boolalpha
			<< "AForm " << obj.getName()
			<< ", signed - " << obj.getIsSigned()
			<< ", grade to sign - " << obj.getGradeToSign()
			<< ", grade to execute - " << obj.getGradeToExecute();
}
