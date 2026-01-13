#include "RPN.hpp"

#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
	: _stack()
{
}

RPN::RPN(const RPN& other)
	: _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() = default;

int RPN::evaluate(const std::string& expression)
{
	std::stack<int> empty;
	_stack.swap(empty);

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
		{
			int value = token[0] - '0';
			_stack.push(value);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Invalid expression");

			int rhs = _stack.top();
			_stack.pop();
			int lhs = _stack.top();
			_stack.pop();

			int result = 0;
			switch (token[0])
			{
				case '+':
					result = lhs + rhs;
					break;
				case '-':
					result = lhs - rhs;
					break;
				case '*':
					result = lhs * rhs;
					break;
				case '/':
					if (rhs == 0)
						throw std::runtime_error("Division by zero");
					result = lhs / rhs;
					break;
				default:
					throw std::runtime_error("Unknown operator");
			}
			_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Invalid token");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression");

	return _stack.top();
}
