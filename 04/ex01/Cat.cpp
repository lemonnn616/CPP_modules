#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* tmp = new Brain(*other.brain);
		delete brain;
		brain = tmp;
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	brain = nullptr;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound!" << std::endl;
}

Brain& Cat::getBrain()
{
	return *brain;
}

const Brain& Cat::getBrain() const
{
	return *brain;
}