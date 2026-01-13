#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <string>

static void	print_impossible_all()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	print_pseudo(const std::string& lit)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (lit == "nanf" || lit == "+inff" || lit == "-inff")
	{
		std::cout << "float: " << lit << std::endl;
		if (lit[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else if (lit[0] == '-')
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: nan" << std::endl;
		return;
	}
	if (lit == "nan")
		std::cout << "float: nanf" << std::endl;
	else if (lit == "+inf")
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: -inff" << std::endl;
	std::cout << "double: " << lit << std::endl;
}

static void	charprint(const double& num)
{
	if (num != num || num < 0.0 || num > 127.0)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	char c = static_cast<char>(num);
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	intprint(const double& num)
{
	if (num != num
		|| num < static_cast<double>(std::numeric_limits<int>::min())
		|| num > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(num) << std::endl;
}

static void	floatprint(const double& num)
{
	if (num > static_cast<double>(std::numeric_limits<float>::max())
		|| num < -static_cast<double>(std::numeric_limits<float>::max()))
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1)
				<< "float: " << static_cast<float>(num) << 'f' << std::endl;
}

static void	doubleprint(const double& num)
{
	std::cout << std::fixed << std::setprecision(1)
				<< "double: " << num << std::endl;
}

static void	print_all(const double& num)
{
	charprint(num);
	intprint(num);
	floatprint(num);
	doubleprint(num);
}

static bool	is_pseudo(const std::string& s)
{
	return (s == "nan" || s == "+inf" || s == "-inf"
		|| s == "nanf" || s == "+inff" || s == "-inff");
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& literal)
{
	if (is_pseudo(literal))
	{
		print_pseudo(literal);
		return;
	}

	if (literal.empty())
	{
		print_impossible_all();
		return;
	}

	if (literal.size() == 1)
	{
		unsigned char ch = static_cast<unsigned char>(literal[0]);
		if (std::isdigit(ch))
			print_all(static_cast<double>(std::atoi(literal.c_str())));
		else
			print_all(static_cast<double>(ch));
		return;
	}

	std::string core = literal;
	if (core[core.size() - 1] == 'f')
		core.erase(core.size() - 1);

	if (core.empty()
		|| core[0] == '.'
		|| core[core.size() - 1] == '.'
		|| ((core[0] == '+' || core[0] == '-') && core.size() > 1 && core[1] == '.'))
	{
		print_impossible_all();
		return;
	}

	char* end = 0;
	double n = std::strtod(core.c_str(), &end);
	if (*end != '\0')
	{
		print_impossible_all();
		return;
	}

	print_all(n);
}
