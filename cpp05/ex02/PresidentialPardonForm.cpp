#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) 
: AForm("PresidentialPardonForm", 25, 5),
_target(target) {}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm	const& other) 
:AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& o) {
	AForm::operator=(o);
	return *this;
}

void PresidentialPardonForm::executeAction() const {
	std::cout 	<< _target
				<< " has been pardoned by Zaphod Beeblebrox" 
				<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
