#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat bobi("Bobi", 1);
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	bobi.signForm(*rrf);
	bobi.executeForm(*rrf);

	someRandomIntern.makeForm("robotomy", "Bender");
	
	delete rrf;
}
