#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) 
: AForm("RobotomyRequestForm", 72, 45),
_target(target) {}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm	const& other) 
:AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& o) {
	AForm::operator=(o);
	return *this;
}

void RobotomyRequestForm::executeAction() const {
	
	if(rand() % 2 == 0)
		std::cout 	<< "Brr… Brr… Brr… BRRRRUM BRRRRUM BROOOOOO! " 
				<< _target << " has been robotomized successfully.\n";
	else
		std::cout 	<< "Brr… Brr… Brr… " 
					<< _target << "-robotomy failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {}
