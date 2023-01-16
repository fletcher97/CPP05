#if !defined(ROBOTOMY_REQUEST_FORM_HPP)
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

#define RRF RobotomyRequestForm

class RRF : public AForm
{
private:
	const std::string _target;
	RRF& operator=(const RRF& other);
protected:
	virtual void _execute(const Bureaucrat& executor) const;
public:
	RRF(std::string target);
	RRF(const RRF& other);
	~RRF();

	std::string getTarget() const;
};
std::ostream& operator<<(std::ostream& out, const RRF& form);

#endif // ROBOTOMY_REQUEST_FORM_HPP
