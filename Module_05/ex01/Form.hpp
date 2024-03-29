#pragma once
#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

#define FORM_HIGHEST_GRADE 1
#define FORM_LOWEST_GRADE 150
#define FORM_DEFAULT_NAME "noName"

class Bureaucrat;

class Form
{

public:

	Form();
	Form(const std::string& name, size_t gradeToSign, size_t gradeToExecute);
	Form(const Form& src);
	~Form();

	const Form&	operator=(const Form& src);

	const std::string&	getName() const;
	bool				getIsSigned() const;
	size_t				getGradeToSign() const;
	size_t				getGradeToExecute() const;

	void				isValidGrade(size_t grade) const;
	void				beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{

	public:

		GradeTooHighException();
		virtual ~GradeTooHighException() throw();

		virtual const char*	what() const throw();

	};

	class GradeTooLowException : public std::exception
	{

	public:

		GradeTooLowException();
		virtual ~GradeTooLowException() throw();

		virtual const char*	what() const throw();

	};

private:

	const std::string	_name;
	bool				_isSigned;
	const size_t		_gradeToSign;
	const size_t		_gradeToExecute;

};

std::ostream&	operator<<(std::ostream& o, const Form& obj);

#endif
