/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:46:16 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 19:26:12 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int main() {
//     //std::cout << std::fixed << std::setprecision(6);
//     std::cout << "=== 1. Constructeurs ===\n";
//     Fixed def;                                 // default
//     Fixed fromInt(  5 );                       // int -> Fixed
//     Fixed fromFloat( 3.141593f );              // float -> Fixed
//     Fixed copyCtr(fromFloat);                  // copy constructor
//     std::cout << "def        = " << def        << "\n";
//     std::cout << "fromInt   = " << fromInt   << "\n";
//     std::cout << "fromFloat = " << fromFloat << "\n";
//     std::cout << "copyCtr   = " << copyCtr   << "\n\n";

//     std::cout << "=== 2. Arithmétique ===\n";
//     Fixed a( 2.5f ), b( -1.25f ), zero(0);
//     std::cout << "a = " << a << ", b = " << b << "\n\n";

//     // addition / subtraction / multiplication
//     std::cout << "a + b = " << (a + b) << "\n";
//     std::cout << "a - b = " << (a - b) << "\n";
//     std::cout << "a * b = " << (a * b) << "\n";
//     // division normale
//     std::cout << "a / b = " << (a / b) << "\n";
//     // division par zéro
//     std::cout << "a / zero = " << (a / zero) << "  <-- doit afficher une erreur puis 0\n\n";

//     // conversions implicites via constructeur de conversion
//     std::cout << "a + 3      = " << (a + 3)      << "  // int converti en Fixed\n";
//     std::cout << "3 + a      = " << (Fixed(3) + a) << "  // Fixed(int)+Fixed\n";
//     std::cout << "b * 2.0f   = " << (b * 2.0f)   << "  // float converti en Fixed\n\n";

//     std::cout << "=== 3. Comparaisons ===\n";
//     std::cout << std::boolalpha;
//     std::cout << "a == b?  " << (a == b)  << "\n";
//     std::cout << "a != b?  " << (a != b)  << "\n";
//     std::cout << "a <  b?  " << (a <  b)  << "\n";
//     std::cout << "a >  b?  " << (a >  b)  << "\n";
//     std::cout << "a <= b?  " << (a <= b)  << "\n";
//     std::cout << "a >= b?  " << (a >= b)  << "\n\n";

//     std::cout << "=== 4. Incrément / Décrément ===\n";
//     Fixed x(0);
//     std::cout << "x initial = " << x << "\n";
//     std::cout << "++x       = " << ++x << "\n";
//     std::cout << "x         = " << x << "\n";
//     std::cout << "x++       = " << x++ << "\n";
//     std::cout << "x         = " << x << "\n";
//     std::cout << "--x       = " << --x << "\n";
//     std::cout << "x         = " << x << "\n";
//     std::cout << "x--       = " << x-- << "\n";
//     std::cout << "x         = " << x << "\n\n";

//     std::cout << "=== 5. Min / Max (statique) ===\n";
//     Fixed p(  7.75f );
//     Fixed q( -2.125f );
//     std::cout << "p = " << p << ", q = " << q << "\n";
//     std::cout << "min(p,q) = " << Fixed::min(p, q) << "\n";
//     std::cout << "max(p,q) = " << Fixed::max(p, q) << "\n";

//     std::cout << "\n=== Fin des tests ===\n";
//     return 0;
// }
