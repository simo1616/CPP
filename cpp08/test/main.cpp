#include <iostream>
#include <vector>
#include <list>

// TODO 1: Completez cette fonction template.
// Elle doit pouvoir prendre n'importe quel conteneur (vector, list...) et l'afficher.
// Rappel: Pour declarer l'iterateur, vous aurez besoin de 'typename T::iterator'.
template <typename T>
void display(T & container) {
	// ... votre code ici ...
	// Créez un itérateur 'it' du type T::iterator (n'oubliez pas typename devant)
	// Faites une boucle for de begin() à end()
	// Affichez *it suivi d'un espace
}

int main () {
	// Setup
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	std::cout << "--- Exercice Template ---" << std::endl;

	std::cout << "Vector : ";
	display(vec); // Doit afficher 1 2 3
	std::cout << std::endl;

	std::cout << "List   : ";
	display(lst); // Doit afficher 10 20 30
	std::cout << std::endl;

	return 0;
}