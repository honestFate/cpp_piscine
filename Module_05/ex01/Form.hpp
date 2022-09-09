#pragma once
#ifndef FORM_H
#define FORM_H

#include <iostream>

class Form
{

public:

	Form();
	Form(std::string& name, size_t gradeToSign, size_t gradeToExecute);
	Form(const Form& src);
	~Form();

	const Form&	operator=(const Form& src);

	const std::string&	getName() const;
	bool				getIsSigned() const;
	const size_t		getGradeToSign() const;
	const size_t		getGradeToExecute() const;

private:

	const std::string	_name;
	bool				_isSigned;
	const size_t		_gradeToSign;
	const size_t		_gradeToExecute;

};

std::ostream&	operator<<(std::ostream& o, const Form& obj);

#endif
