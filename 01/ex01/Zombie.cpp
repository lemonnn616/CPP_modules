#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created (no name)" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
