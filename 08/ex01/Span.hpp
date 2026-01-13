#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
private:
	unsigned int _capacity;
	std::vector<int> _numbers;

public:
	Span();
	explicit Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int value);

	template <typename InputIt>
	void addRange(InputIt first, InputIt last)
	{
		for (auto it = first; it != last; ++it)
			addNumber(*it);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	unsigned int size() const;
	unsigned int capacity() const;

	class SpanFullException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

	class NotEnoughElementsException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

};

#endif
