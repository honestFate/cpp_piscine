#include "Harl.hpp"

Harl::Harl( void ) {
	return;
}

Harl::~Harl() {
	return;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG << std::endl << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO << std::endl << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING << std::endl << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR << std::endl << std::endl;
}

void	Harl::complain( std::string level ) {
	void	(Harl::*f[4])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	lvl_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index = -1;

	for (size_t i = 0; i < 4; i++)
	{
		if (level == lvl_arr[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			(this->*f[index])();
			++index;
		case 1:
			(this->*f[index])();
			++index;
		case 2:
			(this->*f[index])();
			++index;
		case 3:
			(this->*f[index])();
			break;
		default:
			std::cout << LVL_ERROR << std::endl;
			break;
	}
}
