#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\nWRONG EXAMPLES" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrong->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	delete wrong;
	delete wrongCat; // net leaks potomuchto mi ne alociruem pamyat, tak bi bilo
	return 0;
}