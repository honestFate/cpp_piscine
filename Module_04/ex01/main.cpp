#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define TEST_IDEAS_ARRAY_SIZE 4
#define TEST_ANIMALS_ARRAY_SIZE 4

int main()
{
	std::string	testIdeas[TEST_IDEAS_ARRAY_SIZE] = {"Walk", "Bite", "Eat", "Sleep"};
	Animal*	animals[TEST_ANIMALS_ARRAY_SIZE];

	for (size_t i = 0; i < TEST_ANIMALS_ARRAY_SIZE / 2; i++)
	{
		animals[i] = new Cat();
		for (size_t j = 0; j < TEST_IDEAS_ARRAY_SIZE; j++)
		{
			animals[i]->setNewIdea(testIdeas[j]);
		}
	}

	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	animals[0]->showAllIdeas();
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	animals[1]->showAllIdeas();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	for (size_t i = TEST_ANIMALS_ARRAY_SIZE / 2; i < TEST_ANIMALS_ARRAY_SIZE; i++)
	{
		animals[i] = new Dog();
		for (size_t j = 0; j < TEST_IDEAS_ARRAY_SIZE; j++)
		{
			animals[i]->setNewIdea(testIdeas[j]);
		}
	}

	animals[1]->setNewIdea("Bark");
	*animals[0] = *animals[1];

	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	animals[1]->setNewIdea("Play");
	animals[0]->showAllIdeas();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	animals[1]->showAllIdeas();
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	*animals[0] = *animals[2];
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	*animals[1] = *animals[0];
	animals[1]->showAllIdeas();
	std::cout << std::endl;

	for (size_t i = 0; i < TEST_ANIMALS_ARRAY_SIZE; i++)
	{
		delete animals[i];
	}

	return 0;
}
