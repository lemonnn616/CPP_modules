#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;
	std::cout << std::endl;

	Array<int> ints(5);
	std::cout << "ints.size() = " << ints.size() << std::endl;
	for (unsigned int i = 0; i < ints.size(); ++i)
		std::cout << "ints[" << i << "] = " << ints[i] << std::endl;
	std::cout << std::endl;

	for (unsigned int i = 0; i < ints.size(); ++i)
		ints[i] = static_cast<int>(i * 10);
	std::cout << "after write:" << std::endl;
	for (unsigned int i = 0; i < ints.size(); ++i)
		std::cout << "ints[" << i << "] = " << ints[i] << std::endl;
	std::cout << std::endl;

	Array<int> copy(ints);
	copy[0] = 999;
	std::cout << "copy[0] = " << copy[0] << ", ints[0] = " << ints[0] << std::endl;
	std::cout << std::endl;

	Array<int> assigned;
	assigned = ints;
	assigned[1] = 777;
	std::cout << "assigned[1] = " << assigned[1] << ", ints[1] = " << ints[1] << std::endl;
	std::cout << std::endl;

	Array<std::string> strings(3);
	strings[0] = "hello";
	strings[1] = "array";
	strings[2] = "template";
	for (unsigned int i = 0; i < strings.size(); ++i)
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
	std::cout << std::endl;

	const Array<int> cints(ints);
	std::cout << "cints.size() = " << cints.size() << std::endl;
	for (unsigned int i = 0; i < cints.size(); ++i)
		std::cout << "cints[" << i << "] = " << cints[i] << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "access ints[10]" << std::endl;
		std::cout << ints[10] << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "access cints[100]" << std::endl;
		std::cout << cints[100] << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
