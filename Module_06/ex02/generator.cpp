#include "generator.hpp"

Base *	generate(void)
{
	Base * res;
	int randomNumber = std::rand();

	switch (randomNumber % 3)
	{
	case 0:
		res = new A();
		std::cout << "Object of class A generated..." << std::endl;
		break;
	case 1:
		res = new B();
		std::cout << "Object of class B generated..." << std::endl;
		break;
	case 2:
		res = new C();
		std::cout << "Object of class C generated..." << std::endl;
		break;
	}
	return res;
}
