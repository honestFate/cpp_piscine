#pragma once
#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"

#define AFORM_HIGHEST_GRADE 1
#define AFORM_LOWEST_GRADE 150
#define AFORM_DEFAULT_NAME "noName"

class Bureaucrat;

class AForm
{

public:

	AForm();
	AForm(const std::string& name, size_t gradeToSign, size_t gradeToExecute);
	AForm(const AForm& src);
	virtual ~AForm();

	const AForm&	operator=(const AForm& src);

	const std::string&	getName() const;
	bool				getIsSigned() const;
	size_t				getGradeToSign() const;
	size_t				getGradeToExecute() const;

	void				isValidGrade(size_t grade) const;
	void				beSigned(const Bureaucrat& executor);

	void				execute(Bureaucrat const & executor) const;
	virtual void		execTarget() const = 0;

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

	class FormNotSigned : public std::exception
	{

	public:

		FormNotSigned();
		virtual ~FormNotSigned() throw();

		virtual const char*	what() const throw();

	};

	class AlreadySigned : public std::exception
	{

	public:

		AlreadySigned();
		virtual ~AlreadySigned() throw();

		virtual const char*	what() const throw();

	};

private:

	const std::string	_name;
	bool				_isSigned;
	const size_t		_gradeToSign;
	const size_t		_gradeToExecute;

};

std::ostream&	operator<<(std::ostream& o, const AForm& obj);

#endif
