#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	Span sp_basic(5);
	sp_basic.addNumber(6);
	sp_basic.addNumber(3);
	sp_basic.addNumber(17);
	sp_basic.addNumber(9);
	sp_basic.addNumber(11);
	std::cout << "shortestSpan = " << sp_basic.shortestSpan() << std::endl;
	std::cout << "longestSpan  = " << sp_basic.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp_ex(1);
	sp_ex.addNumber(42);
	try
	{
		sp_ex.addNumber(10);
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	try
	{
		sp_ex.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	const unsigned int N = 10000;
	Span sp_big(N);
	std::vector<int> values;
	values.reserve(N);
	for (unsigned int i = 0; i < N; ++i)
		values.push_back(std::rand());
	sp_big.addRange(values.begin(), values.end());
	std::cout << "shortestSpan = " << sp_big.shortestSpan() << std::endl;
	std::cout << "longestSpan  = " << sp_big.longestSpan() << std::endl;
	std::cout << std::endl;

	return 0;
}
