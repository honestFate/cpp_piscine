#include "Zombie.hpp"

int	main()
{
	Zombie 		*zombie_arr[ZOMBIE_COUNT];
	std::string	name;

	for (int i = 0; i < ZOMBIE_COUNT; i++)
	{
		std::cout << "Give him a name: " << std::endl;
		std::cin >> name;
		zombie_arr[i] = newZombie(name);
		zombie_arr[i]->announce();
		randomChump("stack " + name);
	}
	for (int i = 0; i < ZOMBIE_COUNT; i++)
	{
		delete zombie_arr[i];
	}
}
