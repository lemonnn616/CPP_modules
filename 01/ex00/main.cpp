#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	std::cout << "Creating zombie on heap:" << std::endl;
	Zombie* heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\nCreating zombie on stack:" << std::endl;
	randomChump("Stacky");

	return 0;
}
