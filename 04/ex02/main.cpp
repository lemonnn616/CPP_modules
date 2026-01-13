#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int N = 4;
	const Animal* animals[N];

	std::cout << "\n";
	for (int i = 0; i < N / 2; ++i)
		animals[i] = new Dog();

	std::cout << "\n";
	for (int i = N / 2; i < N; ++i)
		animals[i] = new Cat();

	std::cout << "\n";
	for (int i = 0; i < N; ++i)
		animals[i]->makeSound();

	std::cout << "\n";
	for (int i = 0; i < N; ++i)
		delete animals[i];

	std::cout << "\n";
	// Animal a;
	// new Animal();

	return 0;
}
