#include "Zombie.hpp"

int	main()
{
	Zombie 		*zombie_horde;
	std::string	name;

	std::cout << "Give them a name: " << std::endl;
	std::cin >> name;
	zombie_horde = zombieHorde(ZOMBIE_COUNT, name);
	for (int i = 0; i < ZOMBIE_COUNT; i++)
	{
		zombie_horde[i].announce();
	}
	delete [] zombie_horde;
}
