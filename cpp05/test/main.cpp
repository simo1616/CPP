#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  // pour malloc/free

int main(int argc, char* argv[]) {
    // 1) Vérification du nombre d'arguments
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    // 2) Ouverture du fichier
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: cannot open file '" << argv[1] << "'\n";
        return 1;
    }

    // 3) Lecture d'une ligne
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Error: file is empty or unreadable\n";
        return 1;
    }

    // 4) Conversion en entier
    std::istringstream iss(line);
    int value;
    if (!(iss >> value)) {
        std::cerr << "Error: invalid integer in file\n";
        return 1;
    }

    // 5) Vérification de domaine
    if (value < 0) {
        std::cerr << "Error: negative value not allowed\n";
        return 1;
    }

    // 6) Lecture d'un diviseur depuis l'entrée standard
    std::cout << "Enter divisor: ";
    int divisor;
    if (!(std::cin >> divisor)) {
        std::cerr << "Error: invalid divisor input\n";
        return 1;
    }
    if (divisor == 0) {
        std::cerr << "Error: division by zero\n";
        return 1;
    }

    // 7) Opération sur les données
    int result = value / divisor;
    std::cout << "Result of " << value << " / " << divisor << " = " << result << "\n";

    // 8) Simulation d'une allocation mémoire
    int* buffer = static_cast<int*>(std::malloc(10 * sizeof(int)));
    if (!buffer) {
        std::cerr << "Error: memory allocation failed\n";
        return 1;
    }
    // … utilisation de buffer …
    std::free(buffer);

    return 0;
}
