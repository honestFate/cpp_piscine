#include "generator.hpp"
#include "identifier.hpp"

int main()
{
	std::srand(std::time(0));
	Base * ptr0 = generate();
	Base * ptr1 = generate();
	Base * ptr2 = generate();
	Base * ptr3 = generate();
	Base * ptr4 = new Base();

	std::cout << std::endl;
	std::cout << "Identifying pointers..." << std::endl;
	identify(ptr0);
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	identify(ptr4);
	identify(NULL);

	std::cout << std::endl;
	std::cout << "Now try with references..." << std::endl;
	identify(*ptr0);
	identify(*ptr1);
	identify(*ptr2);
	identify(*ptr3);
	identify(*ptr4);

	return 0;
}
