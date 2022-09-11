#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("home")
{
	std::cout << "ShrubberyCreationForm object created by default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :	
AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_REQ, SHRUBBERY_EXEC_REQ),
_target(target)
{
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm object deleted" << std::endl;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	(void)src;
	if (this != &src)
	{
		std::cout << "It's bad idea" << std::endl;
	}
	return (*this);
}

void	ShrubberyCreationForm::execTarget() const
{
	std::ofstream fout(_target + "_shrubbery");

	for(size_t i = 0; i < 3; i++)
	{
		fout << "       _-_" << std::endl
    	<< "    /~~   ~~\\" << std::endl
		<< " /~~         ~~\\" << std::endl
		<< "{               }" << std::endl
		<< " \\  _-     -_  /" << std::endl
		<< "   ~  \\\\ //  ~" << std::endl
		<< "_- -   | | _- _" << std::endl
		<< "  _ -  | |   -_" << std::endl
		<< "      // \\\\" << std::endl;
	}
	fout.close();
}
