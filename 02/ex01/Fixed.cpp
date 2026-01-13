#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
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
		_rawBits = value << _fractionalBits; // sdvigaem na 8 simvolov v 2ichnom kode to est *265
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
		_rawBits = static_cast<int>(round(scaled)); // round okruglaet do celogo; float nelzya sdvig
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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
