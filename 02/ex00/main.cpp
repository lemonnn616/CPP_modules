#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	std::cout << "STACK OBJECTS" << std::endl;
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "\nHEAP OBJECTS" << std::endl;
	Fixed* x = new Fixed();
	Fixed* y = new Fixed(*x);
	Fixed* z = new Fixed();

	*z = *y;

	std::cout << x->getRawBits() << std::endl;
	std::cout << y->getRawBits() << std::endl;
	std::cout << z->getRawBits() << std::endl;

	delete x;
	delete y;
	delete z;

	return 0;
}
