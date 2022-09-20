#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << "meta type: " << meta->getType() << " " << std::endl;
		std::cout << "i type: " << i->getType() << " " << std::endl;
		std::cout << "j type: " << j->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "====================" << std::endl;
	{
		const WrongAnimal* animal = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		const WrongCat* catAsCat = new WrongCat();
	
		std::cout << animal->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << catAsCat->getType() << " " << std::endl;

		animal->makeSound();
		cat->makeSound();
		catAsCat->makeSound();

		delete animal;
		delete cat;
		delete catAsCat;
	}
	return 0;
}
