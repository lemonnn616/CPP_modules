#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("Bob");
	ClapTrap alice("Alice");
	ClapTrap test("test");
	test = bob;
	ClapTrap Mack = bob;

	bob.attack("Alice");
	alice.takeDamage(0);

	alice.attack("Bob");
	alice.beRepaired(3);

	bob.takeDamage(5);
	bob.beRepaired(2);

	for (int i = 0; i < 10; i++)
		bob.attack("Dummy");

	bob.takeDamage(10);
	bob.attack("Alice");
	bob.beRepaired(10);
	bob.attack("Alice");
	return 0;
}
