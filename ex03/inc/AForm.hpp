#if !defined(AFORM_HPP)
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <sstream>

#include "Bureaucrat.hpp"

#ifndef ITOS

#define ITOS(x) (static_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) )).str()

#endif // ITOS(x)

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _gradeSign;
	const int _gradeExec;
	bool _signed;

protected:
	AForm();
	virtual void _execute(const Bureaucrat& executor) const = 0;
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

	class NotSignedException : public std::runtime_error
	{
	public:
		NotSignedException(std::string msg);
	};

	AForm(std::string name, int gradeSign, int gradeExec) throw (GradeTooHighException, GradeTooLowException);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	void execute(const Bureaucrat& executor) const throw (GradeTooLowException, NotSignedException);

	const std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat) throw(GradeTooLowException);

};
std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif // AFORM_HPP
