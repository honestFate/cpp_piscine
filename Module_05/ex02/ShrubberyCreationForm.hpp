#pragma once
#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include <iostream>
#include <fstream>
#include "AForm.hpp"

#define SHRUBBERY_SIGN_REQ 145
#define SHRUBBERY_EXEC_REQ 137

class ShrubberyCreationForm : public AForm
{

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();

	const ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);

	virtual void	execTarget() const;

private:

	const std::string	_target;

};

#endif
