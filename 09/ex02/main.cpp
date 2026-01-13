#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <climits>
#include "PmergeMe.hpp"

static bool parsePositiveInt(const std::string& str, unsigned int& value)
{
	if (str.empty())
		return false;

	unsigned long long result = 0;
	for (std::size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
		result = result * 10ULL + static_cast<unsigned long long>(str[i] - '0');
		if (result > static_cast<unsigned long long>(INT_MAX))
			return false;
	}
	if (result == 0)
		return false;

	value = static_cast<unsigned int>(result);
	return true;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<unsigned int> input;
	input.reserve(static_cast<std::size_t>(argc - 1));

	for (int i = 1; i < argc; ++i)
	{
		unsigned int value = 0;
		if (!parsePositiveInt(std::string(argv[i]), value))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		input.push_back(value);
	}

	std::cout << "Before: ";
	for (std::size_t i = 0; i < input.size(); ++i)
	{
		std::cout << input[i];
		if (i + 1 < input.size())
			std::cout << " ";
	}
	std::cout << std::endl;

	try
	{
		PmergeMe sorter;
		sorter.load(input);
		sorter.process();
	}
	catch (const std::exception&)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
