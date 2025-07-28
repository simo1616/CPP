#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

int main(int ac, char* av[]) {
    try {
        // 1) Vérification du nombre d'arguments
		if (ac < 2) {
			throw std::runtime_error( "Usage: <input_file>\n");
			return 1;
		}

		// 2) Ouverture du fichier
		std::ifstream file(av[1]);
		if (!file) {
			throw std::runtime_error( "Error: cannot open file \n");
			return 1;
		}

		// 3) Lecture d'une ligne
		std::string line;
		if (!std::getline(file, line)) {
			throw std::runtime_error( "Error: file is empty or unreadable\n");
			return 1;
		}

		// 4) Conversion en entier
		std::istringstream iss(line);
		int value;
		if (!(iss >> value)) {
			throw std::runtime_error( "Error: invalid integer in file\n");
			return 1;
		}

		// 5) Vérification de domaine
		if (value < 0) {
			throw std::runtime_error( "Error: negative value not allowed\n");
			return 1;
		}

		// 6) Lecture d'un diviseur depuis l'entrée standard
		std::cout << "Enter divisor: ";
		int divisor;
		if (!(std::cin >> divisor)) {
			throw std::runtime_error( "Error: invalid divisor input\n");
			return 1;
		}
		if (divisor == 0) {
			throw std::runtime_error( "Error: division by zero\n");
			return 1;
		}

		// 7) Opération sur les données
		int result = value / divisor;
		std::cout << "Result of " << value << " / " << divisor << " = " << result << "\n";

		// 8) Simulation d'une allocation mémoire
		int* buffer = static_cast<int*>(std::malloc(10 * sizeof(int)));
		if (!buffer) {
			throw std::runtime_error( "Error: memory allocation failed\n");
			return 1;
		}
		// … utilisation de buffer …
		std::free(buffer);
		return 0;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "[ERROR] : " << e.what();
        return 1;  
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Autre exception : " << e.what() << "\n";
        return 1;
    }
    return 0;
}
