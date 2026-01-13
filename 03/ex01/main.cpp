#include "ScavTrap.hpp"

int main()
{
	std::cout << "STACK" << std::endl;
	ScavTrap a("Stacky");
	ScavTrap test;
	a.attack("Enemy");
	a.ClapTrap::attack("Enemy");
	a.beRepaired(10);
	a.takeDamage(20);
	a.guardGate();

	std::cout << "\nHEAP" << std::endl;
	ScavTrap* ptr = new ScavTrap("Heapy");
	ptr->attack("Dummy");
	ptr->guardGate();

	std::cout << "\nCOPY TEST (heap)" << std::endl;
	ScavTrap copy = *ptr;
	copy.attack("Cloney");

	delete ptr;
	return 0;
}
