#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    std::cout << "=== Intern: makeForm (valid + invalid) ===\n";
    Intern intern;
    AForm* shrub = intern.makeForm("shrubbery creation", "home");
    AForm* robo  = intern.makeForm("robotomy request", "Bender");
    AForm* pardon= intern.makeForm("presidential pardon", "Arthur");
    AForm* bad   = intern.makeForm("invalid form", "Nobody");

    if (shrub)  std::cout << *shrub;
    if (robo)   std::cout << *robo;
    if (pardon) std::cout << *pardon;
    if (bad)    std::cout << *bad; // devrait être NULL → rien ne s'affiche

    std::cout << "\n=== Bureaucrats (grades variés) ===\n";
    Bureaucrat low("Louise", 150);
    Bureaucrat mid("Michel", 50);
    Bureaucrat high("Hector", 1);
    Bureaucrat signer145("Signer145", 145);
    Bureaucrat exec138("Exec138", 138);
    Bureaucrat exec46("Exec46", 46);
    Bureaucrat exec5("Exec5", 5);
    std::cout << low << mid << high << signer145 << exec138 << exec46 << exec5 << '\n';

    std::cout << "=== Execute without signing (should report: not signed) ===\n";
    if (shrub)  high.executeForm(*shrub);
    if (robo)   high.executeForm(*robo);
    if (pardon) high.executeForm(*pardon);

    std::cout << "=== Sign forms (mix of failures and successes) ===\n";
    if (shrub) {
        low.signForm(*shrub);
        signer145.signForm(*shrub);
        high.signForm(*shrub);
    }
    if (robo) {
        low.signForm(*robo);
        mid.signForm(*robo);
        high.signForm(*robo);
    }
    if (pardon) {
        low.signForm(*pardon);
        mid.signForm(*pardon);
        high.signForm(*pardon);
    }

    std::cout << "=== Double-sign (idempotent, should not throw) ===\n";
    if (shrub)  high.signForm(*shrub);
    if (robo)   high.signForm(*robo);
    if (pardon) high.signForm(*pardon);

    std::cout << "=== Execute with insufficient exec grade (close to threshold) ===\n";
    if (shrub)  exec138.executeForm(*shrub);   // needs 137
    if (robo)   exec46.executeForm(*robo);     // needs 45
    if (pardon) mid.executeForm(*pardon);      // needs 5

    std::cout << "=== Execute with sufficient grade ===\n";
    if (shrub)  mid.executeForm(*shrub);       // ok: 50 <= 137
    if (robo)   high.executeForm(*robo);       // ok: 1 <= 45
    if (pardon) exec5.executeForm(*pardon);    // ok: 5 == 5

    std::cout << "=== Robotomy randomness (multiple runs) ===\n";
    for (int i = 0; i < 6; ++i) {
        if (robo) high.executeForm(*robo);
    }

    if (bad) delete bad;
    if (pardon) delete pardon;
    if (robo) delete robo;
    if (shrub) delete shrub;

    return 0;
}
