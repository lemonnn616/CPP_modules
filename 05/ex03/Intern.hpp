#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <vector>
#include "AForm.hpp"

class Intern
{
private:
	static AForm* createShrubbery(const std::string& target);
	static AForm* createRobotomy(const std::string& target);
	static AForm* createPresidential(const std::string& target);

	std::vector<AForm*> _owned;
public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
