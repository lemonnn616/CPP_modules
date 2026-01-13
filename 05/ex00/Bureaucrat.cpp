#include "Bureaucrat.hpp"

void Bureaucrat::checkGradeInRange(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat()
	: _name("NoName"), _grade(150)
{
	checkGradeInRange(_grade);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	checkGradeInRange(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	checkGradeInRange(_grade - 1);
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	checkGradeInRange(_grade + 1);
	++_grade;
}


const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Bureaucrat grade is too high";
}
const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream& res, const Bureaucrat& cls)
{
	res << cls.getName() << ", bureaucrat grade " << cls.getGrade() << ".";
	return res;
}
