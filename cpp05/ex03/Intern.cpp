#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static AForm* createShrub(const std::string& target) { 
    return new ShrubberyCreationForm(target);
}
static AForm* createRobot(const std::string& target) { 
    return new RobotomyRequestForm(target);
}
static AForm* createPardon(const std::string& target) { 
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(Intern	const &other) {(void)other;}

Intern& Intern::operator=(Intern const& o) { (void)o; return(*this);}

AForm* Intern::makeForm(std::string const & formName, std::string const & target) {
	static const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	static const Intern::Creator creators[] = {&createShrub,  &createRobot, &createPardon};
	for(int i = 0; i < 3; i++) {
		if(formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (creators[i](target));
		}
	}
	std::cerr << "Intern: form " << formName << " does not exist" << std::endl;
	return NULL;
}



Intern::~Intern() {

}


