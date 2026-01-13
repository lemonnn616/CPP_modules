#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Intern someRandomIntern;

		Bureaucrat tester50("tester50", 50);
		Bureaucrat tester2("tester2", 1);
		Bureaucrat tester150("tester150", 150);

		AForm* s = someRandomIntern.makeForm("shrubbery creation", "home");
		AForm* r = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* p = someRandomIntern.makeForm("presidential pardon", "Change flag");
		AForm* bad = someRandomIntern.makeForm("coffee", "Latte");
		(void)bad;
		std::cout << std::endl;

		std::cout << *s << std::endl;
		std::cout << *r << std::endl;
		std::cout << *p << std::endl;
		std::cout << std::endl;

		tester50.executeForm(*r);
		std::cout << std::endl;

		tester50.signForm(*s);
		tester50.signForm(*r);
		tester50.signForm(*p);
		tester2.signForm(*p);
		std::cout << std::endl;

		tester150.executeForm(*s);
		tester50.executeForm(*s);
		std::cout << std::endl;

		tester50.executeForm(*r);
		tester2.executeForm(*r);
		std::cout << std::endl;

		tester50.executeForm(*p);
		tester2.executeForm(*p);
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Fatal: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
