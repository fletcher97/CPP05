#include <iostream>

#include "PresidentialPardonForm.hpp"

PPF::PPF(std::string target) : AForm("PPF_" + target, 25, 5), _target(target)
{}

PPF::PPF(const PPF& other) : AForm(other), _target(other.getTarget())
{}

PPF::~PPF()
{}

std::string
PPF::getTarget() const
{
	return this->_target;
}

void
PPF::_execute(const Bureaucrat& bureaucrat) const
{
	(void) bureaucrat;
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PPF&
PPF::operator=(const PPF& other)
{
	AForm::operator=(other);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const PPF& form)
{
	out << "\"" << form.getName();
	out << "\": {GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExec();
	out << ", Target: " << form.getTarget();
	out << ", Signed: " << (form.isSigned() ? "Yes}" : "No}");
	return out;
}
