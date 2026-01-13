#include <iostream>
#include <string>
#include "whatever.hpp"

struct Point
{
	int x;
	int y;
};

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	Point p1 = {1, 2};
	Point p2 = {3, 4};

	::swap(p1, p2);
	std::cout << "p1 = (" << p1.x << ", " << p1.y << "), "
				<< "p2 = (" << p2.x << ", " << p2.y << ")" << std::endl;
	// std::cout << "min(p1, p2) = " << ::min(p1, p2) << std::endl;
	// std::cout << "max(p1, p2) = " << ::max(p1, p2) << std::endl;

	return 0;
}
