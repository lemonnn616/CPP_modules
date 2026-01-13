#include "Base.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>

Base::~Base()
{
}

Base* generate(void)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		seeded = true;
	}

	int r = std::rand() % 3;
	switch (r)
	{
		case 0:
			std::cout << "generate(): created A" << std::endl;
			return new A();
		case 1:
			std::cout << "generate(): created B" << std::endl;
			return new B();
		default:
			std::cout << "generate(): created C" << std::endl;
			return new C();
	}
}

void identify(Base* p)
{
	if (p == 0)
	{
		std::cout << "identify(Base*): null pointer" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "identify(Base*): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identify(Base*): B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identify(Base*): C" << std::endl;
	else
		std::cout << "identify(Base*): Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "identify(Base&): A" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "identify(Base&): B" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "identify(Base&): C" << std::endl;
		return;
	}
	catch (...)
	{
	}

	std::cout << "identify(Base&): Unknown type" << std::endl;
}
