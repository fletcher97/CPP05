#if !defined(SHRUBBERY_CREATION_FORM_HPP)
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

#define SCF ShruberryCreationForm

class SCF : public AForm
{
private:
	const std::string _target;
protected:
	virtual void _execute(const Bureaucrat& executor) const;
public:
	SCF(std::string target);
	SCF(const SCF& other);
	~SCF();

	std::string getTarget() const;
};
std::ostream& operator<<(std::ostream& out, const SCF& form);


#endif // SHRUBBERY_CREATION_FORM_HPP
