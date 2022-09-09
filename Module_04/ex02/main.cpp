#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define TEST_IDEAS_ARRAY_SIZE 4
#define TEST_ANIMALS_ARRAY_SIZE 4

int main()
{
	//AAnimal a; //Error!
	std::string	testIdeas[TEST_IDEAS_ARRAY_SIZE] = {"Walk", "Bite", "Eat", "Sleep"};
	AAnimal*	animals[TEST_ANIMALS_ARRAY_SIZE];

	for (size_t i = 0; i < TEST_ANIMALS_ARRAY_SIZE / 2; i++)
	{
		animals[i] = new Cat();
		for (size_t j = 0; j < TEST_IDEAS_ARRAY_SIZE; j++)
		{
			animals[i]->setNewIdea(testIdeas[j]);
		}
	}

	animals[0]->showAllIdeas();
	animals[1]->showAllIdeas();

	for (size_t i = TEST_ANIMALS_ARRAY_SIZE / 2; i < TEST_ANIMALS_ARRAY_SIZE; i++)
	{
		animals[i] = new Dog();
		for (size_t j = 0; j < TEST_IDEAS_ARRAY_SIZE; j++)
		{
			animals[i]->setNewIdea(testIdeas[j]);
		}
	}

	animals[0]->showAllIdeas();
	animals[1]->showAllIdeas();
	animals[1]->setNewIdea("Bark");

	*animals[0] = *animals[1];

	animals[1]->setNewIdea("Play");
	animals[0]->showAllIdeas();
	animals[1]->showAllIdeas();

	*animals[0] = *animals[2];

	for (size_t i = 0; i < TEST_ANIMALS_ARRAY_SIZE; i++)
	{
		delete animals[i];
	}

	return 0;
}
