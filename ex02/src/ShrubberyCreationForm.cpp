#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

SCF::SCF(std::string target) : AForm("SCF_" + target, 145, 137), _target(target)
{}

SCF::SCF(const SCF& other) : AForm(other), _target(other.getTarget())
{}

SCF::~SCF()
{}

std::string
SCF::getTarget() const
{
	return this->_target;
}

void
SCF::_execute(const Bureaucrat& bureaucrat) const
{
	(void) bureaucrat;
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());
	file <<
"                                                         .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;.\n\
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,..    Gilo97\n";
	file.flush();
	file.close();
}

SCF&
SCF::operator=(const SCF& other)
{
	AForm::operator=(other);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const SCF& form)
{
	out << "\"" << form.getName();
	out << "\": {GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExec();
	out << ", Target: " << form.getTarget();
	out << ", Signed: " << (form.isSigned() ? "Yes}" : "No}");
	return out;
}
