#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GardeTooLowException::GardeTooLowException(std::string msg) : std::invalid_argument(msg)
{}

Form::GardeTooHighException::GardeTooHighException(std::string msg) : std::invalid_argument(msg)
{}

Form::NotSignedException::NotSignedException(std::string msg) : std::invalid_argument(msg)
{}

Form::Form() : _name("Invalid"), _gradeSign(0), _gradeExec(0), _signed(false)
{}

Form::Form(std::string name, int gradeSign, int gradeExec) throw(GardeTooHighException, GardeTooLowException) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (gradeSign > 150)
		throw GardeTooLowException("Can't create form with signing requirering a grade worst than 150. Grade: " + ITOS(gradeSign));
	if (gradeSign < 1)
		throw GardeTooHighException("Can't create form with signing requirering a grade better than 1. Grade: " + ITOS(gradeSign));
	if (gradeExec > 150)
		throw GardeTooLowException("Can't create form with an execution requirering a grade worst than 150. Grade: " + ITOS(gradeExec));
	if (gradeExec < 1)
		throw GardeTooHighException("Can't create form with an execution requirering a grade better than 1. Grade: " + ITOS(gradeExec));
}

Form::Form(const Form& other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _signed(other._signed)
{}

Form&
Form::operator=(const Form& other)
{
	this->_signed = other._signed;
	return *this;
}

Form::~Form()
{}

void
Form::execute(const Bureaucrat& executor) const throw(GardeTooLowException, NotSignedException)
{
	if (!this->isSigned())
		throw NotSignedException("the contract is not signed");
	if (this->getGradeExec() < executor.getGrade())
		throw GardeTooLowException("grade is too low");
	this->_execute(executor);
}

const std::string
Form::getName() const
{
	return this->_name;
}

int
Form::getGradeSign() const
{
	return this->_gradeSign;
}

int
Form::getGradeExec() const
{
	return this->_gradeExec;
}

bool
Form::isSigned() const
{
	return this->_signed;
}

void
Form::beSigned(const Bureaucrat& bureaucrat) throw(GardeTooLowException)
{
	if (this->_gradeSign < bureaucrat.getGrade())
		throw GardeTooLowException("grade is too low");
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "\"" << form.getName();
	out << "\": {GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExec();
	out << ", Signed: " << (form.isSigned() ? "Yes}" : "No}");
	return out;
}
