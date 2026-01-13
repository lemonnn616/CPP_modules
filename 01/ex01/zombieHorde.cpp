#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		std::ostringstream fullName; // в с++11 у нас есть to_string здесь такой опции нет, альтернативо итоа чтобы мы могли писать инт как стринг
		fullName << name << " #" << (i + 1);
		horde[i].setName(fullName.str());
	}

	return horde;
}
