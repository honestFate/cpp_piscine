#include <iostream>
#include <ctime>

int	main() {
	time_t t = time(nullptr);
	std::cout << t << std::endl;
}
