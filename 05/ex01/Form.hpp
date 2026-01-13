#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

	void checkGradeInRange(int grade) const;

public:
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string& getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& b);

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
};

std::ostream& operator<<(std::ostream& res, const Form& cls);

#endif
