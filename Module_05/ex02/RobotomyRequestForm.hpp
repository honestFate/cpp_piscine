#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

#define ROBOTOMY_REQUEST_SIGN_REQ 72
#define ROBOTOMY_REQUEST_EXEC_REQ 45

class RobotomyRequestForm : public AForm
{

public:

	RobotomyRequestForm();
	RobotomyRequestForm::RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();

	const RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);

	virtual void	execTarget() const;

private:

	const std::string	_target;

};

#endif
