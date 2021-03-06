#if !defined(PRESIDENTIAL_PARDON_FORM_HPP)
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

#define PPF PresidentialPardonForm

class PPF : public Form
{
private:
	const std::string _target;
protected:
	virtual void _execute(const Bureaucrat& executor) const;
public:
	PPF(std::string target);
	PPF(const PPF& other);
	~PPF();

	std::string getTarget() const;
};
std::ostream& operator<<(std::ostream& out, const PPF& form);

#endif // PRESIDENTIAL_PARDON_FORM_HPP
