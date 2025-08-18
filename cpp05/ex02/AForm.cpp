#include "AForm.hpp"

AForm::AForm() 
:name("name"),
isSigned(false),
signGrade(150),
executeGrade(150) {}

AForm::AForm(std::string const& name, int signGrade, int executeGrade) 
:name(name),
isSigned(false),
signGrade(signGrade),
executeGrade(executeGrade) {
	if(signGrade < 1 || executeGrade < 1) throw GradeTooHighException();
	if(signGrade > 150 || executeGrade > 150) throw GradeTooLowException();

}

AForm::AForm(AForm	const &other)
:name(other.name), 
isSigned(other.isSigned),
signGrade(other.signGrade), 
executeGrade(other.executeGrade) {}

AForm& AForm::operator=(AForm	const &other) {
	if(this != &other)
		isSigned = other.isSigned;
	return(*this);
}

std::string	AForm::getName() const{
	return(name);
}

bool AForm::getIsSigned() const{
	return(isSigned);
}

int AForm::getSignGrade() const{
	return(signGrade);
}

int AForm::getExecuteGrade() const{
	return(executeGrade);
}

void AForm::beSigned(Bureaucrat const& b) {
	if(b.getGrade() <= signGrade)
		isSigned = true;
	else
  		throw GradeTooLowException();	
}

void AForm::execute(Bureaucrat const& executor) const {
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > executeGrade)
		throw GradeTooLowException();
	executeAction();
}



AForm::~AForm() {}

std::ostream& operator<<(std::ostream& out, AForm const& f) {
    out << std::boolalpha
        << "Form \"" << f.getName() << "\":\n"
        << "  • Signed         : " << (f.getIsSigned() ? "true" : "false") << "\n"
        << "  • Grade to sign  : " << f.getSignGrade()   << "\n"
        << "  • Grade to exec  : " << f.getExecuteGrade() << "\n";
    return out;
}

