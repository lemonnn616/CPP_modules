#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "DEBUG\n";
	std::cout << "Some comments\n";
}

void Harl::info(void)
{
	std::cout << "INFO\n";
	std::cout << "Some comments\n";
}

void Harl::warning(void)
{
	std::cout << "WARNING\n";
	std::cout << "Some comments\n";
}

void Harl::error(void)
{
	std::cout << "ERROR\n";
	std::cout << "Some comments\n";
}

void Harl::complain(std::string level)
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" }; // poryadok vazhen (masiv)
	void (Harl::*functions[])(void) = // masiv ukazatelei na metodi (NE VIZOV FUNKCI aadress funkcii)
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*functions[i])(); // ukazatel na metod (ne vizov a ukazatel kotorii uzhe sdelaet iz nashei stroki takuu this->warning())
			return;
		}
	}

	std::cout << "Not Harl level: " << level << std::endl;
}
