#include <string>
#include <cstring>
#include <iostream>

#include "Intern.hpp"

Intern::WrongFormException::WrongFormException(std::string msg) : std::invalid_argument(msg)
{}

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern&
Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{}

ShruberryCreationForm*
Intern::_makeSCF(const std::string form, const std::string target) const
{
	if (std::strcmp(form.c_str(), "shruberry creation"))
		throw WrongFormException("Form " + form + " is not a SCF");
	return new ShruberryCreationForm(target);
}
RobotomyRequestForm*
Intern::_makeRRF(const std::string form, const std::string target) const
{
	if (std::strcmp(form.c_str(), "robotomy request"))
		throw WrongFormException("Form " + form + " is not a RRF");
	return new RobotomyRequestForm(target);
}
PresidentialPardonForm*
Intern::_makePPF(const std::string form, const std::string target) const
{
	if (std::strcmp(form.c_str(), "presidential pardon"))
		throw WrongFormException("Form " + form + " is not a PPF");
	return new PresidentialPardonForm(target);
}


AForm*
Intern::makeForm(const std::string form, const std::string target) const
{
	AForm *f = NULL;
	try
	{
		f = this->_makeSCF(form, target);
	}
	catch(const std::exception& e)
	{}
	try
	{
		f =  this->_makeRRF(form, target);
	}
	catch(const std::exception& e)
	{}
	try
	{
		f =  this->_makePPF(form, target);
	}
	catch(const std::exception& e)
	{}

	if (f)
		std::cout << "Form " << form << " created" << std::endl;
	else
		std::cout << "Form " << form << " is not a known form" << std::endl;
	return f;
}

std::ostream& operator<<(std::ostream& out, const Intern& form);
