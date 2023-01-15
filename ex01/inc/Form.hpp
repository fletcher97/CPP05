#if !defined(FORM_HPP)
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <sstream>

#include "Bureaucrat.hpp"

#ifndef ITOS

#define ITOS(x) (static_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) )).str()

#endif // ITOS(x)

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _gradeSign;
	const int _gradeExec;
	bool _signed;

	Form();
public:

	class GradeTooLowException : public std::range_error
	{
	public:
		GradeTooLowException(std::string msg);
	};

	class GradeTooHighException : public std::range_error
	{
	public:
		GradeTooHighException(std::string msg);
	};

	Form(std::string name, int gradeSign, int gradeExec) throw (GradeTooHighException, GradeTooLowException);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException);

};
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif // FORM_HPP
