#if !defined(INTERN_HPP)
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	ShruberryCreationForm *_makeSCF(const std::string name, const std::string target) const;
	RobotomyRequestForm *_makeRRF(const std::string name, const std::string target) const;
	PresidentialPardonForm *_makePPF(const std::string name, const std::string target) const;
public:
	class WrongFormException : public std::invalid_argument
	{
	public:
		WrongFormException(std::string msg);
	};

	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	Form *makeForm(const std::string form, const std::string target) const;
};
std::ostream& operator<<(std::ostream& out, const Intern& form);

#endif // INTERN_HPP
