#include <iostream>
#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

RRF::RRF(std::string target) : AForm("RRF_" + target, 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}

RRF::RRF(const RRF& other) : AForm(other), _target(other.getTarget())
{}

RRF&
RRF::operator=(const RRF& other)
{
	AForm::operator=(other);
	return *this;
}

RRF::~RRF()
{}

std::string
RRF::getTarget() const
{
	return this->_target;
}

void
RRF::_execute(const Bureaucrat& bureaucrat) const
{
	(void) bureaucrat;
	std::cout << "*DRILL NOISES*" << std::endl;
	std::cout << "The robotomy for " << this->_target << " was a " << (std::rand() % 2 ? "success." : "failure.") << std::endl;
}

std::ostream& operator<<(std::ostream& out, const RRF& form)
{
	out << "\"" << form.getName();
	out << "\": {GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExec();
	out << ", Target: " << form.getTarget();
	out << ", Signed: " << (form.isSigned() ? "Yes}" : "No}");
	return out;
}
