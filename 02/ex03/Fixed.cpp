#include "Fixed.hpp"
#include <cmath>

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	if (value > (INT_MAX >> _fractionalBits) || value < (INT_MIN >> _fractionalBits))
	{
		std::cerr << "Error: value is too large or too small" << std::endl;
		_rawBits = 0;
	}
	else
		_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	double scaled = static_cast<double>(value) * (1 << _fractionalBits);
	if (scaled > INT_MAX || scaled < INT_MIN)
	{
		std::cerr << "Error: float value is too large or too small" << std::endl;
		_rawBits = 0;
	}
	else
		_rawBits = static_cast<int>(round(scaled));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed Fixed::operator-() const
{
	return Fixed(-this->toFloat());
}
