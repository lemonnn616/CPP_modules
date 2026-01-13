#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat tester("Tester", 50);
		Bureaucrat boss("Boss", 1);

		Form f1("TestForm", 75, 30);
		Form f2("TopSecret", 1, 1);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		tester.signForm(f1);
		tester.signForm(f2);
		boss.signForm(f2);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Fatal: " << e.what() << std::endl;
	}
	return 0;
}
