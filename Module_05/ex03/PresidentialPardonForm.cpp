#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("home")
{
	std::cout << "PresidentialPardonForm object created by default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :	
AForm("PresidentialPardonForm", PRESIDENTIAL_PARDON_SIGN_REQ, PRESIDENTIAL_PARDON_EXEC_REQ),
_target(target)
{
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm object deleted" << std::endl;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	(void)src;
	if (this != &src)
	{
		std::cout << "It's bad idea" << std::endl;
	}
	return (*this);
}

void	PresidentialPardonForm::execTarget() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
