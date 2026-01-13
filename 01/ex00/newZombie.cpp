#include "Zombie.hpp"

Zombie* newZombie(std::string name) // potomu chto ukazatel na obiekt
{
	return new Zombie(name);
}
