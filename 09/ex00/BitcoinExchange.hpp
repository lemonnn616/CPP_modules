#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _rates;

public:
	BitcoinExchange();
	explicit BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	double getRateForDate(const std::string& date) const;

	static bool isValidDate(const std::string& date);
	static bool parseValue(const std::string& str, double& value);
};

#endif
