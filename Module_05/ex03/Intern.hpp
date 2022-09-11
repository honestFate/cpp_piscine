#pragma once
#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORMS_TOTAL 3

class Intern
{

public:

	Intern();
	Intern(const Intern& src);
	~Intern();

	const Intern&	operator=(const Intern& src);

	AForm*	makeForm(const std::string& formName, const std::string& formTarget);


private:

	AForm*	makeShrubberyCreationForm(const std::string& formTarget);
	AForm*	makeRobotomyRequestForm(const std::string& formTarget);
	AForm*	makePresidentialPardonForm(const std::string& formTarget);

};

#endif
