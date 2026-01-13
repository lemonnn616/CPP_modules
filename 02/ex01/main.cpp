#include "Fixed.hpp"

int main(void)
{
	std::cout << "STACK OBJECTS" << std::endl;
	std::cout << std::endl;

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b); // copy => asigment => getRaw

	std::cout << std::endl;
	a = Fixed(1234.4321f); // float constractor dlya rezultata (create temp) => copy asigment => getRaw => decon TEMP
	std::cout << std::endl;

	std::cout << "a is " << a.toFloat() << std::endl;
	std::cout << "b is " << b.toFloat() << std::endl;
	std::cout << "c is " << c.toFloat() << std::endl;
	std::cout << "d is " << d.toFloat() << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "\nHEAP OBJECTS" << std::endl;
	std::cout << std::endl;

	Fixed* x = new Fixed(100);
	Fixed* y = new Fixed(9.99f);
	std::cout << std::endl;

	std::cout << "*x is " << x->toFloat() << std::endl;
	std::cout << "*y is " << y->toFloat() << std::endl;
	std::cout << "*x is " << x->toInt() << " as integer" << std::endl;
	std::cout << "*y is " << y->toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	delete x;
	delete y;
	return 0; // tut eshe 4 deconstractora dlya stack obiektov
}
