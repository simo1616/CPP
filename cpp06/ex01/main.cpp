#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);

    return 0;
}




// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <limits>
// #include <cmath>

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         std::cerr << "Usage: ./convert <literal>" << std::endl;
//         return 1;
//     }

//     std::string literal = argv[1];
//     double d = std::strtod(literal.c_str(), NULL); // conversion en double

//     // char
//     if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
//         std::cout << "char: impossible" << std::endl;
//     } else if (std::isprint(static_cast<int>(d))) {
//         std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
//     } else {
//         std::cout << "char: Non displayable" << std::endl;
//     }

//     // int
//     if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
//         std::cout << "int: impossible" << std::endl;
//     } else {
//         std::cout << "int: " << static_cast<int>(d) << std::endl;
//     }

//     // float
//     float f = static_cast<float>(d);
//     std::cout << "float: " << f;
//     if (std::isnan(f) || std::isinf(f))
//         std::cout << "f" << std::endl;
//     else
//         std::cout << ".0f" << std::endl;

//     // double
//     std::cout << "double: " << d;
//     if (!(std::isnan(d) || std::isinf(d)))
//         std::cout << ".0";
//     std::cout << std::endl;

//     return 0;
// }
