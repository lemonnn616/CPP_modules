#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* tmp = new Brain(*other.brain);
		delete brain;
		brain = tmp;
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	brain = nullptr;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound!" << std::endl;
}

Brain& Dog::getBrain()
{
	return *brain;
}

const Brain& Dog::getBrain() const
{
	return *brain;
}