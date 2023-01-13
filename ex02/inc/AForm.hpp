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

protected:
	Form();
	virtual void _execute(const Bureaucrat& executor) const = 0;
public:

	class GardeTooLowException : public std::invalid_argument
	{
	public:
		GardeTooLowException(std::string msg);
	};

	class GardeTooHighException : public std::invalid_argument
	{
	public:
		GardeTooHighException(std::string msg);
	};

	class NotSignedException : public std::invalid_argument
	{
	public:
		NotSignedException(std::string msg);
	};

	Form(std::string name, int gradeSign, int gradeExec) throw (GardeTooHighException, GardeTooLowException);
	Form(const Form& other);
	Form& operator=(const Form& other);
	virtual ~Form();

	void execute(const Bureaucrat& executor) const throw (GardeTooLowException, NotSignedException);

	const std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat) throw(GardeTooLowException);

};
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif // FORM_HPP
