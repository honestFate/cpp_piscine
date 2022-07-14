#include "Harl.hpp"

int	main( int argc, char *argv[] ) {
	Harl	harl_instance;

	if (argc == 2)
		harl_instance.complain(argv[1]);
	else
		harl_instance.complain("?");
}
