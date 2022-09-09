#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <iostream>
#include "AForm.hpp"

#define PRESIDENTIAL_PARDON_SIGN_REQ 25
#define PRESIDENTIAL_PARDON_EXEC_REQ 5

class PresidentialPardonForm : public AForm
{

public:

	PresidentialPardonForm();
	PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();

	const PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);

	virtual void	execTarget() const;

private:

	const std::string	_target;

};

#endif
