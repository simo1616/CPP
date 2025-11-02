#include <iostream>
#include <string>
#include "Whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

// *****************2eme main*************************
// #include <iostream>
// #include <string>
// #include "Whatever.hpp"

// // Type custom pour tester la généricité et les comparaisons
// struct Test {
// 	int value;
// 	Test(int v = 0) : value(v) {}
// 	bool operator<(const Test &other) const { return value < other.value; }
// 	bool operator>(const Test &other) const { return value > other.value; }
// 	bool operator<=(const Test &other) const { return value <= other.value; }
// 	bool operator>=(const Test &other) const { return value >= other.value; }
// 	bool operator==(const Test &other) const { return value == other.value; }
// 	bool operator!=(const Test &other) const { return value != other.value; }
// };

// std::ostream &operator<<(std::ostream &os, const Test &t) {
// 	os << t.value;
// 	return os;
// }

// int main(void) {
// 	std::cout << "==== BASIC TESTS ====" << std::endl;
// 	int a = 2;
// 	int b = 3;

// 	::swap(a, b);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";

// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
// 	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

// 	std::cout << "\n==== CONST TESTS ====" << std::endl;
// 	const int x = 10;
// 	const int y = 10;
// 	// Teste le cas d’égalité → doit retourner le deuxieme
// 	std::cout << "min(x, y) (égalité) = " << ::min(x, y) << std::endl;
// 	std::cout << "max(x, y) (égalité) = " << ::max(x, y) << std::endl;

// 	std::cout << "\n==== CUSTOM TYPE TEST ====" << std::endl;
// 	Test t1(42);
// 	Test t2(21);

// 	std::cout << "Avant swap : t1 = " << t1 << ", t2 = " << t2 << std::endl;
// 	::swap(t1, t2);
// 	std::cout << "Apres swap : t1 = " << t1 << ", t2 = " << t2 << std::endl;
// 	std::cout << "min(t1, t2) = " << ::min(t1, t2) << std::endl;
// 	std::cout << "max(t1, t2) = " << ::max(t1, t2) << std::endl;

// 	std::cout << "\n==== POINTER TEST (piege) ====" << std::endl;
// 	int m = 5, n = 10;
// 	int *pm = &m;
// 	int *pn = &n;

// 	std::cout << "Avant swap pointeurs : *pm=" << *pm << " *pn=" << *pn << std::endl;
// 	::swap(pm, pn); // teste la compatibilité template avec pointeurs
// 	std::cout << "Apres swap pointeurs : *pm=" << *pm << " *pn=" << *pn << std::endl;
// 	std::cout << "min(pm, pn) -> compare adresses, pas valeurs : " << ::min(pm, pn) << std::endl;

// 	std::cout << "\n==== STRING EDGE CASES ====" << std::endl;
// 	std::string empty = "";
// 	std::string same = "";

// 	std::cout << "min(empty, same) = " << ::min(empty, same) << std::endl;
// 	std::cout << "max(empty, same) = " << ::max(empty, same) << std::endl;

// 	std::cout << "\n==== FLOAT PRECISION ====" << std::endl;
// 	float f1 = 1.00001f;
// 	float f2 = 1.00002f;
// 	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
// 	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;

// 	return 0;
// }


// 3eme main

// #include <iostream>
// #include "Whatever.hpp"

// // Un type sans opérateurs de comparaison
// struct NonComparable {
// 	int data;
// 	NonComparable(int d = 0) : data(d) {}
// };

// // Surcharge de << juste pour l’affichage
// std::ostream &operator<<(std::ostream &os, const NonComparable &nc) {
// 	os << "NonComparable(" << nc.data << ")";
// 	return os;
// }

// int main(void) {
// 	NonComparable x(1);
// 	NonComparable y(2);

// 	std::cout << "Test avec NonComparable :" << std::endl;

// 	::swap(x, y); // ✅ Fonctionne (car swap ne nécessite que l’opérateur =)

// 	std::cout << "x = " << x << ", y = " << y << std::endl;

// 	// ❌ Ces deux lignes doivent échouer à la compilation
// 	// car NonComparable ne définit ni < ni <=
// 	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
// 	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

// 	return 0;
// }


