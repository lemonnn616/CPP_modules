#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int N = 4;
	const Animal* animals[N];

	std::cout << "\n";
	for (int i = 0; i < N/2; ++i) animals[i] = new Dog();

	std::cout << "\n";
	for (int i = N/2; i < N; ++i) animals[i] = new Cat();

	std::cout << "\n";
	for (int i = 0; i < N; ++i) animals[i]->makeSound();

	std::cout << "\n";
	for (int i = 0; i < N; ++i) delete animals[i];

	std::cout << "\nDeep copy\n";
	Cat original;
	original.getBrain().setIdea(0, "Original Cat idea 0");

	Cat copy = original;
	std::cout << "original.brain=" << &original.getBrain()
			  << "copy.brain="	<< &copy.getBrain() << "\n";

	copy.getBrain().setIdea(0, "Copy Cat idea 0");

	std::cout << "Original brain[0]: " << original.getBrain().getIdea(0) << "\n";
	std::cout << "Copy brain[0]: " << copy.getBrain().getIdea(0) << "\n";

	std::cout << "\nDeep copy\n";
	Dog d1;
	d1.getBrain().setIdea(1, "Dog Idea 1");
	Dog d2;
	d2 = d1;
	std::cout << "d1.brain=" << &d1.getBrain()
			  << " d2.brain=" << &d2.getBrain() << "\n";

	d2.getBrain().setIdea(1, "Dog2 Idea 1");
	std::cout << "d1.brain[1]: " << d1.getBrain().getIdea(1) << "\n";
	std::cout << "d2.brain[1]: " << d2.getBrain().getIdea(1) << "\n";

	std::cout << "\n";
	return 0;
}
