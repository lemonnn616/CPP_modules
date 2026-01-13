#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me  = new Character("me");
// 	ICharacter* bob = new Character("bob");

// 	AMateria* ice  = src->createMateria("ice");
// 	AMateria* cure = src->createMateria("cure");


// 	me->equip(ice);
// 	me->equip(cure);

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	me->use(3, *bob);
// 	AMateria* unknown = src->createMateria("fire");
// 	if (!unknown)
// 		std::cout << "source doesnt know type fire\n";
// 	me->equip(unknown);

// 	me->unequip(0);
// 	me->use(0, *bob);

// 	Character* alice = new Character("alice");
// 	AMateria* ice2 = src->createMateria("ice");
// 	alice->equip(ice2);
// 	alice->use(0, *bob);

// 	Character* aliceCopy = new Character(*alice);
// 	delete alice;

// 	aliceCopy->use(0, *bob);

// 	delete aliceCopy;
// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }