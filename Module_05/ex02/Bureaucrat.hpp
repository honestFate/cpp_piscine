#pragma once
#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "AForm.hpp"

#define BUREAUCRAT_HIGHEST_GRADE 1
#define BUREAUCRAT_LOWEST_GRADE 150
#define BUREAUCRAT_DEFAULT_NAME "noName"
#define RED		"\033[1;91m"
#define GREEN	"\033[1;92m"
#define YELLOW	"\033[1;93m"
#define RESET	"\033[0m"

class AForm;

class Bureaucrat
{

public:

	Bureaucrat();
	Bureaucrat(const std::string& name, size_t grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();

	const Bureaucrat&	operator=(const Bureaucrat& src);
	size_t				operator++();
	size_t				operator++(int);
	size_t				operator--();
	size_t				operator--(int);

	const std::string&	getName() const;
	size_t				getGrade() const;

	size_t				increaseGrade();
	size_t				decreaseGrade();

	void				isValidGrade(size_t grade) const;
	bool				signForm(AForm& form) const;
	bool				executeForm(AForm const & form) const;

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
	size_t				_grade;

};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& obj);

#endif
