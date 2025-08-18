#include "Form.hpp"

Form::Form() 
:name("name"),
isSigned(false),
signGrade(150),
executeGrade(150) {
	std::cout	<< "Defaut constructor "
				<< "Class Form" << std::endl;
}

Form::Form(std::string const& name, int signGrade, int executeGrade) 
:name(name),
isSigned(false),
signGrade(signGrade),
executeGrade(executeGrade) {
	std::cout	<< "Arg constructor "
				<< "Class Form name: " 
				<< name
				<< std::endl;
	if(signGrade < 1 || executeGrade < 1) throw GradeTooHighException();
	if(signGrade > 150 || executeGrade > 150) throw GradeTooLowException();

}

Form::Form(Form	const &other)
:name(other.name), 
isSigned(other.isSigned),
signGrade(other.signGrade), 
executeGrade(other.executeGrade) {
	std::cout	<< "Arg constructor "
				<< "Class Form name: " 
				<< name
				<< std::endl;
	
}

Form& Form::operator=(Form	const &other) {
	if(this != &other)
		isSigned = other.isSigned;
	return(*this);
}

std::string	Form::getName() const{
	return(name);
}

bool Form::getIsSigned() const{
	return(isSigned);
}

int Form::getSignGrade() const{
	return(signGrade);
}

int Form::getExecuteGrade() const{
	return(executeGrade);
}

void Form::beSigned(Bureaucrat const& b) {
	if(b.getGrade() <= signGrade)
		isSigned = true;
	else
  		throw GradeTooLowException();	
}

Form::~Form() {
	std::cout	<< "Arg destructor "
				<< "Class Form name: " 
				<< name
				<< std::endl;
}

std::ostream& operator<<(std::ostream& out, Form const& b) {
	out 	<< "name is = " << b.getName()
			<< " IsSigned is = " << b.getIsSigned()
			<< " SignGrade is = " << b.getSignGrade()
			<< " ExecuteGrade is = " << b.getExecuteGrade()
			<< ".\n";
	return(out);
}