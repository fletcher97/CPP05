#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::GardeTooLowException::GardeTooLowException(std::string msg) : std::invalid_argument(msg)
{}

Bureaucrat::GardeTooHighException::GardeTooHighException(std::string msg) : std::invalid_argument(msg)
{}


Bureaucrat::Bureaucrat(std::string name, int grade) throw (GardeTooHighException, GardeTooLowException) : _name(name)
{
	if (grade > 150)
		throw GardeTooLowException("Can't create bureaucrat with a grade worst than 150. Grade: " + ITOS(grade));
	if (grade < 1)
		throw GardeTooHighException("Can't create bureaucrat with a grade better than 1. Grade: " + ITOS(grade));
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat&
Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

int
Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string
Bureaucrat::getName() const
{
	return this->_name;
}

void
Bureaucrat::promote() throw (GardeTooHighException)
{
	if (this->_grade <= 1)
		throw GardeTooHighException("Grade is already max. Can't promote any higher.");
	this->_grade--;
}

void
Bureaucrat::demote() throw (GardeTooLowException)
{
	if (this->_grade >= 150)
		throw GardeTooLowException("Grade is already min. Can't demote any lower.");
	this->_grade++;
}

void
Bureaucrat::signForm(Form& form) const
{
	if (form.isSigned())
	{
		std::cout << *this << ", couldn't sign " << form << " because it's already signed" << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(Form::GardeTooLowException& e)
	{
		std::cout << *this << ", couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

std::ostream&
operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << " (grade " << bureaucrat.getGrade() << ")";
	return out;
}
