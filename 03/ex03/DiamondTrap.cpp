#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(std::string("noname") + "_clap_name"), ScavTrap("noname"), FragTrap("noname"), name("noname")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap default constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << name << ", ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
