#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "\033[34m== Bureaucrat Creation Valid ==\033[0m" << std::endl;
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\033[33mError: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        std::cout << "\033[34m== Bureaucrat Creation Too High ==\033[0m" << std::endl;
        Bureaucrat b2("Bob", 0);
    } catch (const std::exception& e) {
        std::cout << "\033[33mCaught: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        std::cout << "\033[34m== Bureaucrat Creation Too Low ==\033[0m" << std::endl;
        Bureaucrat b3("Charlie", 151);
    } catch (const std::exception& e) {
        std::cout << "\033[33mCaught: " << e.what() << "\033[0m" << std::endl;
    }

    Bureaucrat emp("Dana", 2);
    std::cout << "\033[34m== Bureaucrat Increment/Decrement ==\033[0m" << std::endl;
    try {
        emp.incrementGrade();
        std::cout << "\033[32mIncremented: " << emp << "\033[0m" << std::endl;
        emp.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << "\033[33mCaught on increment: " << e.what() << "\033[0m" << std::endl;
    }
    try {
        emp.decrementGrade();
        emp.decrementGrade();
        std::cout << "\033[32mDecremented twice: " << emp << "\033[0m" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\033[33mCaught on decrement: " << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\033[34m== Form Creation Valid ==\033[0m" << std::endl;
    try {
        Form f1("FormX", 50, 30);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\033[33mError: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        std::cout << "\033[34m== Form Creation GradeTooHigh ==\033[0m" << std::endl;
        Form f2("FormY", 0, 10);
    } catch (const std::exception& e) {
        std::cout << "\033[33mCaught: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        std::cout << "\033[34m== Form Creation GradeTooLow ==\033[0m" << std::endl;
        Form f3("FormZ", 10, 151);
    } catch (const std::exception& e) {
        std::cout << "\033[33mCaught: " << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\033[34m== Signing Forms ==\033[0m" << std::endl;
    Bureaucrat signer1("Eve", 20);
    Bureaucrat signer2("Frank", 40);
    Form formA("A", 30, 20);
    Form formB("B", 20, 10);

    signer1.signForm(formA);
    signer1.signForm(formB);
    signer2.signForm(formA);
    signer2.signForm(formB);

    return 0;
}
