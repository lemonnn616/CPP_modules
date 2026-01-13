#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat tester1("tester1", 50);
		Bureaucrat tester2("tester2", 1);
		Bureaucrat tester3("tester3", 150);

		ShrubberyCreationForm f1("home");
		RobotomyRequestForm f2("Bender");
		PresidentialPardonForm f3("Change flag");

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		tester1.signForm(f1);
		tester1.signForm(f2);
		tester1.signForm(f3);
		tester2.signForm(f3);

		tester3.executeForm(f1);
		tester1.executeForm(f1);
		tester1.executeForm(f2);
		tester1.executeForm(f3);
		tester2.executeForm(f3);

		RobotomyRequestForm unsignedRobotomy("Marvin");
		tester1.executeForm(unsignedRobotomy);

		ShrubberyCreationForm lowExec("yard");
		tester1.signForm(lowExec);
		tester3.executeForm(lowExec);

		try
		{
			Bureaucrat badHigh("BadHigh", 0);
		}
		catch (const std::exception& e)
		{
			std::cerr << "error" << e.what() << std::endl;
		}
		try
		{
			Bureaucrat badLow("BadLow", 151);
		}
		catch (const std::exception& e)
		{
			std::cerr << "error" << e.what() << std::endl;
		}

		ShrubberyCreationForm unsignedShrub("garden");
		tester2.executeForm(unsignedShrub);

	}
	catch (const std::exception& e)
	{
		std::cerr << "Fatal: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
