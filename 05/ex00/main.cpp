#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Alice", 3);
	std::cout << a << std::endl;
	

	a.incrementGrade();
	std::cout << a << std::endl;

	// Bureaucrat test("Test", 1);
	// std::cout << test << std::endl;
	// test.incrementGrade();
	// std::cout << test << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 150);
		std::cout << low << std::endl;
		low.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat badHigh("BadHigh", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat badLow("BadLow", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	Bureaucrat b = a;
	std::cout << b << std::endl;
	Bureaucrat c("Charlie", 100);
	c = a;
	std::cout << c << std::endl;

	return 0;
}
