#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat A;
	Bureaucrat B("Sam", 10);
	try
	{
		Bureaucrat C("Bob", LOWEST_GRADE + 1);
		std::cout << C << std::endl;
		Bureaucrat D("Bobi", 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat C("Bob", HIGHEST_GRADE - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	A++;
	++A;
	std::cout << A << std::endl;
	--B;
	B--;
	std::cout << B << std::endl;
	/*while (1)
	{
		B--;
	}*/
}
