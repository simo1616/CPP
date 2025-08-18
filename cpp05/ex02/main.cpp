#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(static_cast<unsigned>(std::time(0)));

	std::cout << "\033[34m=== Creation ===\033[0m\n";
	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Marvin");
	PresidentialPardonForm pardon("Ford");
	std::cout << shrub << robot << pardon << '\n';

	std::cout << "\033[34m=== Bureaucrats ===\033[0m\n";
	Bureaucrat low("Louise", 150);
	Bureaucrat mid("Michel", 50);
	Bureaucrat high("Hector", 1);
	Bureaucrat signer145("Signer145", 145);
	Bureaucrat exec138("Exec138", 138);
	std::cout << low << mid << high << signer145 << exec138 << '\n';

	std::cout << "\033[34m=== Execute without signing (should fail: not signed) ===\033[0m\n";
	low.executeForm(shrub);
	mid.executeForm(robot);
	high.executeForm(pardon);

	std::cout << "\033[34m=== Sign forms ===\033[0m\n";
	low.signForm(shrub);
	signer145.signForm(shrub);
	high.signForm(shrub);
	mid.signForm(robot);
	high.signForm(robot);
	mid.signForm(pardon);
	high.signForm(pardon);

	std::cout << "\033[34m=== Double-sign (idempotent, should not throw) ===\033[0m\n";
	high.signForm(shrub);
	high.signForm(robot);
	high.signForm(pardon);

	std::cout << "\033[34m=== Execute with insufficient exec grade (different from 150) ===\033[0m\n";
	exec138.executeForm(shrub);
	exec138.executeForm(robot);
	exec138.executeForm(pardon);

	std::cout << "\033[34m=== Execute with mid and high ===\033[0m\n";
	mid.executeForm(shrub);
	mid.executeForm(robot);
	mid.executeForm(pardon);
	high.executeForm(shrub);
	high.executeForm(robot);
	high.executeForm(pardon);

	std::cout << "\033[34m=== Robotomy randomness (multiple runs) ===\033[0m\n";
	for (int i = 0; i < 6; ++i) {
		high.executeForm(robot);
	}

	return 0;
}
