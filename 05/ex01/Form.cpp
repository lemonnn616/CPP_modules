#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::checkGradeInRange(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Form::Form()
	: _name("NoForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	checkGradeInRange(_gradeToSign);
	checkGradeInRange(_gradeToExecute);
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGradeInRange(_gradeToSign);
	checkGradeInRange(_gradeToExecute);
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _gradeToSign;
}

int Form::getExecGrade() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (_signed)
		return;
	if (b.getGrade() <= _gradeToSign)
	{
		_signed = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& res, const Form& cls)
{
	res << "Form \"" << cls.getName() << "\""
		<< " [signed: " << (cls.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << cls.getSignGrade()
		<< ", grade to execute: " << cls.getExecGrade()
		<< "]";
	return res;
}
