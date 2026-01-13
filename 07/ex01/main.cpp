#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	printElem(T const &value)
{
	std::cout << value << std::endl;
}

void	increment(int &value)
{
	++value;
}

struct Point
{
	int x;
	int y;
};

void	printPoint(Point const &p)
{
	std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	iter(intArray, intLen, increment);
	iter(intArray, intLen, printElem<int>);

	std::string strArray[] = {"hello", "world", "iter"};
	std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	iter(strArray, strLen, printElem<std::string>);

	const int constArray[] = {10, 20, 30};
	std::size_t constLen = sizeof(constArray) / sizeof(constArray[0]);

	iter(constArray, constLen, printElem<int>);

	Point points[] = {{1, 2}, {3, 4}, {5, 6}};
	std::size_t pointsLen = sizeof(points) / sizeof(points[0]);

	iter(points, pointsLen, printPoint);

	return 0;
}
