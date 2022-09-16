#include "identifier.hpp"

void	identify(Base* p)
{
	if (p == NULL)
	{
		std::cerr << RED << "p is nullptr!" << RESET << std::endl;
	}
	else if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << GREEN << "Real type of object pointing by p is A" << RESET << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << GREEN << "Real type of object pointing by p is B" << RESET << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << GREEN << "Real type of object pointing by p is C" << RESET << std::endl;
	}
	else
	{
		std::cerr << RED << "Real type of object pointing by p is unknown" << RESET << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		if (&dynamic_cast<A &>(p))
		{
			std::cout << GREEN << "That's reference to A object!" << RESET << std::endl;
			return;
		}
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << "That isn't reference to A object..." << std::endl;
	}
	try
	{
		if (&dynamic_cast<B &>(p))
		{
			std::cout << GREEN << "That's reference to B object!" << RESET << std::endl;
			return;
		}
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << "That isn't reference to B object..." << std::endl;
	}
	try
	{
		if (&dynamic_cast<C &>(p))
		{
			std::cout << GREEN << "That's reference to C object!" << RESET << std::endl;
			return;
		}
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << "That isn't reference to C object..." << std::endl;
	}
	std::cerr << RED << "Real type of object referencing by p is unknown" << RESET << std::endl;
}
