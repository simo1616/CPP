#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b) {
	out << b.getName() 
		<< ", bureaucrat grade " 
		<< b.getGrade() 
		<< ".\n";

	return(out);
}

Bureaucrat::Bureaucrat() :name(""), grade(1) {
	std::cout << "Default Constructeur Bureaucrate Called\n";
}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
:name(_name) {
	std::cout << "Constructeur ARG " << name << " Called\n";
	if (_grade < 1)   throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat	const &other)
:name(other.name), grade(other.grade) {
	std::cout << "Constructeur Copy " << name << " Called\n";
}

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

std::string Bureaucrat::getName() const {
	return(name);
}

int	Bureaucrat::getGrade() const {
	return(grade);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructeur " << name << " Called\n";
}



