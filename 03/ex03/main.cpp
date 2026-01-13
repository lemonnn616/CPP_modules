#include "DiamondTrap.hpp"

int main()
{
	std::cout << "STACK" << std::endl;
	DiamondTrap dt("Diamond");

	dt.attack("Target");
	dt.beRepaired(20);
	dt.takeDamage(40);
	dt.highFivesGuys();
	dt.guardGate();
	dt.whoAmI();

	std::cout << "\nHEAP" << std::endl;
	DiamondTrap* heap = new DiamondTrap("Heapy");
	heap->whoAmI();

	DiamondTrap copy = *heap;
	copy.whoAmI();

	delete heap;
	return 0;
}
