#include "Form.hpp"

Form::Form() : _name("noName"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false)
{
	std::cout << "Form object created by default constructor" << std::endl;
}

Form::~Form()
{
	std::cout << *this << ". Deleted" << std::endl;
}

Form::Form(const Form& src) :
_name(src._name),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute),
_isSigned(false)
{
	*this = src;
}

const Form& Form::operator=(const Form& src)
{
	if (this != &src)
	{
		std::cout << "Too many constants here. What are you want from that operation?" << std::endl;
	}
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

const size_t	Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

const size_t	Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

std::ostream&	operator<<(std::ostream& o, const Form& obj)
{
	return o << std::boolalpha
			<< "Form " << obj.getName()
			<< ", signed - " << obj.getIsSigned()
			<< ", grade to sign" << obj.getGradeToSign()
			<< ", grade to execute" << obj.getGradeToExecute();
}
