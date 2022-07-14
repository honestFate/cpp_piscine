#include "Harl.hpp"

Harl::Harl( void ) {
	return;
}

Harl::~Harl() {
	return;
}

void	Harl::debug( void ) {
	std::cout << DEBUG << std::endl;
}

void	Harl::info( void ) {
	std::cout << INFO << std::endl;
}

void	Harl::warning( void ) {
	std::cout << WARNING << std::endl;
}

void	Harl::error( void ) {
	std::cout << ERROR << std::endl;
}

void	Harl::complain( std::string level ) {
	void	(Harl::*f[4])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	lvl_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == lvl_arr[i])
		{
			(this->*f[i])();
			return;
		}
	}
	std::cout << LVL_ERROR << std::endl;
}