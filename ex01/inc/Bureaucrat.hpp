#if !defined(BUREAUCRAT_HPP)
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

#include <sstream>

#ifndef ITOS

#define ITOS(x) (static_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) )).str()

#endif // ITOS(x)

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
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

	Bureaucrat(std::string name, int grade) throw (GardeTooHighException, GardeTooLowException);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	int getGrade() const;
	const std::string getName() const;

	void promote() throw (GardeTooHighException);
	void demote() throw (GardeTooLowException);

	void signForm(Form& form) const;
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
