#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <sstream>

// Constructeurs/destructeur (généralement vides pour une classe statique)
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &o) { (void)o; return *this; }

// --- Définitions des fonctions d'aide statiques privées ---

void ScalarConverter::displayChar(double d) {
    std::cout << "char\t: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "impossible\n";
    } else if (!std::isprint(static_cast<char>(d))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(d) << "'\n";
    }
}

void ScalarConverter::displayInt(double d) {
    std::cout << "int\t: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(d) << "\n";
    }
}

void ScalarConverter::displayFloat(double d) {
    std::cout << "float\t: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
}

void ScalarConverter::displayDouble(double d) {
    std::cout << "double\t: " << std::fixed << std::setprecision(1) << d << "\n";
}

// --- Méthode de conversion principale ---

void ScalarConverter::convert(const std::string& input) {
    // Cas 1: La chaîne est un caractère unique non numérique
    if (input.length() == 1 && !std::isdigit(input[0])) {
        char c = input[0];
        displayChar(static_cast<double>(c));
        displayInt(static_cast<double>(c));
        displayFloat(static_cast<double>(c));
        displayDouble(static_cast<double>(c));
        return;
    }

    // Cas 2: La chaîne est un nombre ou un pseudo-littéral
    std::string processedInput = input;
    if (input == "nanf" || input == "+inff" || input == "-inff") {
        processedInput = input.substr(0, input.length() - 1);
    }
    
    std::stringstream ss(processedInput);
    double d;
    ss >> d;

    // Vérifie si la conversion a réussi et si toute la chaîne a été consommée
    if (ss.fail() || !ss.eof()) {
        std::cout << "char\t: impossible\n"
                  << "int\t: impossible\n"
                  << "float\t: impossible\n"
                  << "double\t: impossible\n";
        return;
    }

    // Affichage pour tous les types à partir du double converti
    displayChar(d);
    displayInt(d);
    displayFloat(d);
    displayDouble(d);
}
