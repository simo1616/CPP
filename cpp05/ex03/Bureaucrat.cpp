#include "Bureaucrat.hpp"
#include "AForm.hpp" 

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b) {
	out << b.getName() 
		<< ", bureaucrat grade " 
		<< b.getGrade() 
		<< ".\n";

	return(out);
}

Bureaucrat::Bureaucrat() :name(""), grade(150) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
:name(_name) {
	if (_grade < 1)   throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat	const &other)
:name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) 
		this->grade = other.grade;
    return (*this);
}

void Bureaucrat::incrementGrade() {
	if(grade + 1 > 150)
		throw (GradeTooLowException());
	--grade;
}

void Bureaucrat::decrementGrade() {
	if(grade < 1)
		throw (GradeTooHighException());
	++grade;
}

void Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout	<< name
					<< " signed "
					<< f.getName()
					<< std::endl;


	}
	catch(const std::exception& e) {
		std::cerr	<< name
					<< " couldn’t sign "
					<< f.getName()
					<< " because "
					<< e.what()
					<< std::endl;

	}
}

std::string Bureaucrat::getName() const {
	return(name);
}

int	Bureaucrat::getGrade() const {
	return(grade);
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout 	<< name 
					<< " executed " 
					<< form.getName() 
					<< std::endl;

	}
	catch (std::exception const& e) {
		std::cerr 	<< name 
					<< " couldn’t execute "
					<< form.getName()
					<< " because "
					<< e.what() 
					<< std::endl;
	}
}


Bureaucrat::~Bureaucrat() {}



