#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern object created by default constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern object deleted" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Copy intern... Nothing to copy" << std::endl;
	*this = src;
}

const Intern& Intern::operator=(const Intern& src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment intern... Nothing to copy" << std::endl;
	}
	return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	std::string	avaliableForms[FORMS_TOTAL] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*createForm[FORMS_TOTAL])(const std::string&) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (size_t i = 0; i < FORMS_TOTAL + 1; i++)
	{
		if (formName == avaliableForms[i])
		{
			std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
			return (this->*createForm[i])(formTarget);
		}
	}
	std::cout << RED"Form " << formName << " doesn't exist!"RESET << std::endl;
	return (NULL);
}

AForm*	Intern::makeShrubberyCreationForm(const std::string& formTarget)
{
	return new ShrubberyCreationForm(formTarget);
}

AForm*	Intern::makeRobotomyRequestForm(const std::string& formTarget)
{
	return new RobotomyRequestForm(formTarget);	
}

AForm*	Intern::makePresidentialPardonForm(const std::string& formTarget)
{
	return new PresidentialPardonForm(formTarget);
}
