#include <iostream>
#include <stdexcept>  // pour std::runtime_error

// Fonction qui divise et lance une exception si b == 0
int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division par zéro interdite");
    }
    return a / b;
}

int main() {
    int x = 10;
    int y = 0;

    try {
        // Tentative d’appel à divide()
        int result = divide(x, y);
        std::cout << "Résultat : " << result << "\n";
    }
    catch (const std::runtime_error& e) {
        // On récupère spécifiquement les runtime_error
        std::cerr << "Erreur détectée : " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        // Pour toute autre exception dérivée de std::exception
        std::cerr << "Exception inconnue : " << e.what() << "\n";
    }

    std::cout << "Fin du programme.\n";
    return 0;
}
