#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== Créations valides ===\n";
	try {
		Bureaucrat ok("Alice", 42);
		std::cout << ok;  
	}
	catch (const std::exception& e) {
		std::cerr << "Erreur inattendue : " << e.what() << "\n";
	}

	std::cout << "\n=== Créations invalides ===\n";
	try {
		Bureaucrat tooHigh("Bob", 0);
		std::cout << tooHigh << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Bob : " << e.what() << "\n";
	}
	try {
		Bureaucrat tooLow("Carol", 200);
		std::cout << tooLow << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Carol : " << e.what() << "\n";
	}

	std::cout << "\n=== Incrémentation / décrémentation ===\n";
	try {
		Bureaucrat top("David", 2);
		std::cout << top;
		top.incrementGrade();
		std::cout << "Après increment: " << top;
		top.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << "David : " << e.what() << "\n";
	}

	try {
		Bureaucrat bottom("Eve", 149);
		std::cout << bottom;
		bottom.decrementGrade();
		std::cout << "Après decrement: " << bottom;
		bottom.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << "Eve : " << e.what() << "\n";
	}

	return 0;
}
