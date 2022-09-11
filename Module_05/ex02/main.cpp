#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat bureaucratA("Bob", 46);
	AForm *formPardon = new PresidentialPardonForm("Navalny");
	AForm *formRobotomy = new RobotomyRequestForm("delivery");
	AForm *formShruberry = new ShrubberyCreationForm("home");
	try
	{
		bureaucratA.executeForm(*formShruberry);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		bureaucratA.signForm(*formShruberry);
		bureaucratA.executeForm(*formShruberry);
		bureaucratA.signForm(*formRobotomy);
		bureaucratA.executeForm(*formRobotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat put_in("Put_in", 2);
	try
	{
		put_in.signForm(*formShruberry);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	AForm *formShruberry2 = new ShrubberyCreationForm("barak");
	put_in.signForm(*formShruberry2);
	put_in.executeForm(*formShruberry2);

	put_in.executeForm(*formRobotomy);

	put_in.signForm(*formPardon);
	put_in.executeForm(*formPardon);

	delete formPardon;
	delete formRobotomy;
	delete formShruberry;
	delete formShruberry2;
}
