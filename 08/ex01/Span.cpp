#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span()
	: _capacity(0), _numbers()
{
}

Span::Span(unsigned int n)
	: _capacity(n), _numbers()
{
	_numbers.reserve(n);
}

Span::Span(const Span& other)
	: _capacity(other._capacity), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() = default;

void Span::addNumber(int value)
{
	if (_numbers.size() >= _capacity)
		throw SpanFullException();
	_numbers.push_back(value);
}

unsigned int Span::size() const
{
	return static_cast<unsigned int>(_numbers.size());
}

unsigned int Span::capacity() const
{
	return _capacity;
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (std::size_t i = 0; i + 1 < tmp.size(); ++i)
	{
		long diff = static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i]);
		unsigned int udiff = static_cast<unsigned int>(diff);
		if (udiff < minSpan)
			minSpan = udiff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	auto minmax = std::minmax_element(_numbers.begin(), _numbers.end());
	long diff = static_cast<long>(*minmax.second) - static_cast<long>(*minmax.first);
	return static_cast<unsigned int>(diff);
}

const char* Span::SpanFullException::what() const noexcept
{
	return "Span is full";
}

const char* Span::NotEnoughElementsException::what() const noexcept
{
	return "Not enough elements to compute a span";
}
