#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v{0, 2, 4, 6, 8};
	try
	{
		auto it = easyfind(v, 4);
		std::cout << "found in v: " << *it << '\n';
		*it = 42;
		std::cout << "v after modify: ";
		for (auto x : v)
			std::cout << x << ' ';
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	const std::list<int> lst{10, 20, 30, 40};
	try
	{
		auto it = easyfind(lst, 30);
		std::cout << "found in lst: " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << '\n';
	}

	std::cout << std::endl;
	try
	{
		auto it = easyfind(lst, 99);
		std::cout << "found in lst: " << *it << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << "exception: " << e.what() << '\n';
	}

	return 0;
}
