#include "Base.hpp"
#include <iostream>

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "RANDOM:" << i << std::endl;

		Base* p = generate();

		identify(p);

		if (p)
			identify(*p);

		delete p;
	}
	std::cout << std::endl;
	Base* nullPtr = 0;
	identify(nullPtr);

	return 0;
}
