#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::checkGradeInRange(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void AForm::assertExecutable(const Bureaucrat& executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

AForm::AForm()
	: _name("NoForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	checkGradeInRange(_gradeToSign);
	checkGradeInRange(_gradeToExecute);
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGradeInRange(_gradeToSign);
	checkGradeInRange(_gradeToExecute);
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{ 
	return _gradeToSign;
}

int AForm::getExecGrade() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (_signed)
		return;
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Form grade is too high";
}
const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Form grade is too low";
}
const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& res, const AForm& cls)
{
	res << "Form \"" << cls.getName() << "\""
		<< " [signed: " << (cls.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << cls.getSignGrade()
		<< ", grade to execute: " << cls.getExecGrade()
		<< "]";
	return res;
}
