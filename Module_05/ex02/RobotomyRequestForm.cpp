#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("home")
{
	std::cout << "RobotomyRequestForm object created by default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :	
AForm("Robotomy request form", ROBOTOMY_REQUEST_SIGN_REQ, ROBOTOMY_REQUEST_EXEC_REQ),
_target(target)
{
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm object deleted" << std::endl;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	(void)src;
	if (this != &src)
	{
		std::cout << "It's bad idea" << std::endl;
	}
	return (*this);
}

void	RobotomyRequestForm::execTarget() const
{
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1)
	{
		std::cout << GREEN << _target << " has been robotomized successfully!"RESET << std::endl;
	}
	else
	{
		std::cout << YELLOW << _target << " robotomy failed!"RESET << std::endl;
	}
}
