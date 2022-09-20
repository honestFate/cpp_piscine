#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* tmp1;
	tmp = src->createMateria("ice");
	std::cout << "Try equip" << std::endl;
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	std::cout << "Try equip" << std::endl;
	me->equip(tmp1);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->use(0, *bob);
	me->equip(tmp);
	me->use(0, *me);

	delete bob;
	delete me;
	delete src;
	delete tmp;
	delete tmp1;
	return 0;
}
