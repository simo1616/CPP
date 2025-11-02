#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> a;
    Array<int> b(a);
    std::cout << "a.size() = " << a.size() << ", b.size() = " << b.size() << std::endl;

    Array<int> c(5);
    for (unsigned int i = 0; i < c.size(); i++)
        c[i] = i + 1;

    Array<int> d(c);
    std::cout << "Avant modification:" << std::endl;
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << "c[" << i << "]=" << c[i] << " d[" << i << "]=" << d[i] << std::endl;

    c[0] = 99;
    d[1] = 77;

    std::cout << "Apres modification:" << std::endl;
    for (unsigned int i = 0; i < c.size(); i++) {
        std::cout << "c[" << i << "]=" << c[i] << " d[" << i << "]=" << d[i] << std::endl;
	}

	
	Array<int> dd(5);
	for (unsigned int i = 0; i < dd.size(); i++)
		dd[i] = i + 1;
	std::cout << "Avant affectation:" << std::endl;
	for (unsigned int i = 0; i < dd.size(); i++)
		std::cout << "dd" << i << "]=" << dd[i] << " d[" << i << "]=" << dd[i] << std::endl;
	Array<int> e;
	e = dd;
	
	std::cout << "Apres affectation:" << std::endl;
	for (unsigned int i = 0; i < e.size(); i++)
		std::cout << "e[" << i << "]=" << e[i] << " dd[" << i << "]=" << dd[i] << std::endl;

	



    return 0;
}























// int main() {
// 	std::cout << "=== Constructeur par défaut ===" << std::endl;
// 	Array<int> a; // tableau vide
// 	std::cout << "Taille de a : " << a.size() << std::endl;

// 	Array<int> b(100);
// 	std::cout << "Taille de b : " << b.size() << std::endl;
// 	try {
// 		for (unsigned int i = 0; i < b.size() + 20; i++)
// 			b[i] = i * 10;
// 	}
// 	catch (const std::out_of_range &e) {
// 		std::cout << "e.what = "<< e.what() << std::endl;
// 	}
// 	try {
// 		for (unsigned int i = 0; i < b.size() + 20; i++)
// 			std::cout << b[i] << " ";
// 	}
// 	catch (const std::out_of_range &e) {
// 		std::cout << "e.what = "<< e.what() << std::endl;
// 	}
// 	try {
// 			std::cout << b[100] << "\n";
// 	}
// 	catch (const std::out_of_range &e) {
// 		std::cout << "e.what = "<< e.what() << std::endl;
// 	}
	
// 	const Array<int> c(100);
// 	std::cout << "Taille de c : " << c.size() << std::endl;
// 	try {
// 			std::cout << c[100] << "\n";
// 	}
// 	catch (const std::out_of_range &e) {
// 		std::cout << "e.what = "<< e.what() << std::endl;
// 	}

// 	Array<int> d(b);
// 	std::cout << "Taille de 'd' : " << d.size() << std::endl;
	

// 	return 0;
// }
