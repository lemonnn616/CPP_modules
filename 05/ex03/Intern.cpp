#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cctype>
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern&)
{
}

Intern& Intern::operator=(const Intern&)
{
	return *this;
}

Intern::~Intern()
{
	for (std::size_t i = 0; i < _owned.size(); ++i)
		delete _owned[i];
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	struct Entry
	{
		const char* key;
		AForm* (*fn)(const std::string&);
	};

	static const Entry table[] =
	{
		{ "shrubbery creation", &Intern::createShrubbery },
		{ "robotomy request", &Intern::createRobotomy },
		{ "presidential pardon", &Intern::createPresidential }
	};

	for (std::size_t i = 0; i < sizeof(table) / sizeof(table[0]); ++i)
	{
		if (formName == table[i].key)
		{
			AForm* f = table[i].fn(target);
			const_cast<Intern*>(this)->_owned.push_back(f);
			std::cout << "Intern creates " << table[i].key << std::endl;
			return f;
		}
	}
	std::cout << "Intern: unknown form " << formName << std::endl;
	return 0;
}