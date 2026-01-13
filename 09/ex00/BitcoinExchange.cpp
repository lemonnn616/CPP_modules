#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

static std::string trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return std::string();
	std::size_t last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
}

static bool isLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return year % 4 == 0;
}

BitcoinExchange::BitcoinExchange()
	: _rates()
{
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
	: _rates()
{
	loadDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _rates(other._rates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() = default;

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	_rates.clear();

	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database file.");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
			continue;

		date = trim(date);
		valueStr = trim(valueStr);

		if (!isValidDate(date))
			continue;

		double value = 0.0;
		if (!parseValue(valueStr, value))
			continue;

		_rates[date] = value;
	}

	if (_rates.empty())
		throw std::runtime_error("Error: no valid data in database file.");
}

double BitcoinExchange::getRateForDate(const std::string& date) const
{
	if (_rates.empty())
		throw std::runtime_error("Error: no exchange rates loaded.");

	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
	if (it == _rates.end())
	{
		--it;
	}
	else if (it->first != date)
	{
		if (it == _rates.begin())
			throw std::runtime_error("Error: no earlier exchange rate available.");
		--it;
	}
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dim = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		dim = 29;

	return day >= 1 && day <= dim;
}

bool BitcoinExchange::parseValue(const std::string& str, double& value)
{
	if (str.empty())
		return false;

	char* end = 0;
	const char* cstr = str.c_str();
	value = std::strtod(cstr, &end);

	if (end == cstr || *end != '\0')
		return false;

	return true;
}
