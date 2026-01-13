#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"

static std::string trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return std::string();
	std::size_t last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	try
	{
		exchange.loadDatabase("data.csv");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::string line;
	if (!std::getline(input, line))
		return 0;

	while (std::getline(input, line))
	{
		if (line.empty())
			continue;

		std::size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!BitcoinExchange::isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value = 0.0;
		if (!BitcoinExchange::parseValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (value < 0.0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000.0)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double rate = exchange.getRateForDate(date);
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
