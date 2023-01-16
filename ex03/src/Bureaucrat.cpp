#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg) : std::range_error(msg)
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg) : std::range_error(msg)
{}


Bureaucrat::Bureaucrat(std::string name, int grade) throw (GradeTooHighException, GradeTooLowException) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException("Can't create bureaucrat with a grade worst than 150. Grade: " + ITOS(grade));
	if (grade < 1)
		throw GradeTooHighException("Can't create bureaucrat with a grade better than 1. Grade: " + ITOS(grade));
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
Bureaucrat::promote() throw (GradeTooHighException)
{
	if (this->_grade <= 1)
		throw GradeTooHighException("Grade is already max. Can't promote any higher.");
	this->_grade--;
}

void
Bureaucrat::demote() throw (GradeTooLowException)
{
	if (this->_grade >= 150)
		throw GradeTooLowException("Grade is already min. Can't demote any lower.");
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
	catch(Form::GradeTooLowException& e)
	{
		std::cout << *this << ", couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void
Bureaucrat::executeForm(const Form& form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " failed to execute " << form << " because " << e.what() << std::endl;
	}
}

std::ostream&
operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << " (grade " << bureaucrat.getGrade() << ")";
	return out;
}
