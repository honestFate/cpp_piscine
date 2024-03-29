#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat bureaucratA("Bob", 10);
	Form formA("random form", 9, 11);
	try
	{
		Form formErr("random form", FORM_LOWEST_GRADE + 1, FORM_HIGHEST_GRADE);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form formErr("random form", FORM_HIGHEST_GRADE, FORM_HIGHEST_GRADE - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		bureaucratA.signForm(formA);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	bureaucratA++;
	try
	{
		bureaucratA.signForm(formA);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
