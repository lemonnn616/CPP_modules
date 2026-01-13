#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

	void checkGradeInRange(int grade) const;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form) const;

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

std::ostream& operator<<(std::ostream& res, const Bureaucrat& cls);

#endif
