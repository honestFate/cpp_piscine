#pragma once
#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{

public:

	Bureaucrat();
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

	class GradeTooHighException : public std::exception
	{

	public:

		GradeTooHighException();
		~GradeTooHighException();

		virtual const char*	info() const throw();

	};

	class GradeTooLowException : public std::exception
	{

	public:

		GradeTooLowException();
		~GradeTooLowException();

		virtual const char*	info() const throw();

	};
	

private:

	const std::string	_name;
	size_t				_grade;

};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& obj);

#endif
