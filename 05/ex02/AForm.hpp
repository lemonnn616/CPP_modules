#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

	void checkGradeInRange(int grade) const;

protected:
	void assertExecutable(const Bureaucrat& executor) const;

public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const noexcept override;
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& res, const AForm& cls);

#endif
