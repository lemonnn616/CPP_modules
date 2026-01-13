#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "STACK" << std::endl;
	FragTrap frag("Fragger");
	frag.attack("Target 1");
	frag.beRepaired(20);
	frag.takeDamage(50);
	frag.highFivesGuys();

	std::cout << "\nHEAP" << std::endl;
	FragTrap* frag2 = new FragTrap("Heapy");
	frag2->attack("Target 2");
	frag2->highFivesGuys();

	FragTrap clone = *frag2;
	clone.attack("CopyTarget");

	delete frag2;
	return 0;
}
