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

AForm::GradeTooHighException::GradeTooHighException()
{
	std::cout << "Exception AForm::GradeTooHighException created" << std::endl;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "Exception AForm::GradeTooHighException deleted" << std::endl;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "grade was too high";
}

AForm::GradeTooLowException::GradeTooLowException()
{
	std::cout << "Exception AForm::GradeTooLowException created" << std::endl;
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "Exception AForm::GradeTooLowException deleted" << std::endl;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "grade was too low";
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

bool	AForm::isValidExecutor(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= this->_gradeToSign)
	{
		return true;
	}
	return false;
}

void	AForm::beSigned(const Bureaucrat& executor)
{
	if (isValidExecutor(executor))
	{
		this->_isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (isValidExecutor(executor))
	{
		this->execTarget();
	}
	else
	{
		throw GradeTooLowException();
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
