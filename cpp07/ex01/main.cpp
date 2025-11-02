#include <iostream>
#include <string>
#include "iter.hpp"



template<typename T>
void printElem(T const &input) {
	std::cout << input << " _ ";
}

template<typename T>
void increment(T &input) {
	input++;
}

template <typename T>
void addExclamation(T &input) {
	input = input + "!";
}

int main () {
	int tab[] = {0,1,2,3,4};

	iter(tab, 5, printElem<int>);
	std::cout << std::endl;
	iter(tab, 5, increment<int>);
	std::cout << std::endl;
	iter(tab, 5, printElem<int>);
	std::cout << std::endl;

	std::string name[] = {"HEllo","world"};
	iter(name, 2, printElem<std::string>);
	std::cout << std::endl;
	iter(name, 2, addExclamation<std::string>);
	iter(name, 2, printElem<std::string>);
	std::cout << std::endl;

	const double d_tab[] = {0.2,1.211,31.3564,99.658};
	iter(d_tab, 4, printElem<double>);
	std::cout << std::endl;

	char letters[] = {'a', 'b', 'c', 'd'};
	iter(letters, 4, printElem<char>);
	std::cout << std::endl;

	std::cout << "\n=== Test  ne compile pas) ===" << std::endl;
	// iter(tab, 5, [](int const &x){ std::cout << "[" << x << "] "; }); // ⚠️ C++11
	std::cout << std::endl;

	int empty[1] = {42};
	iter(empty, 0, printElem<int>);
	std::cout << "\npas d'affichage\n";

}