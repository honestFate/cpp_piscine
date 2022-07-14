#include <iostream>
#include "Sed.hpp"

int	main( int argc, char *argv[] ) {
	Sed*	seder;

	if (argc != 4)
	{
		std::cout << "Wrong arguments" << std::endl;
		return (1);
	}
	seder = Sed::init(argv[1]);
	if (!seder)
	{
		std::cout << "File error" << std::endl;
		return (1);
	}
	seder->sed(argv[2], argv[3]);
	delete seder;
	return (0);
}
