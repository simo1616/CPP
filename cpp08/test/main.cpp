#include <iostream>
#include <vector>
#include <list>
#include <stack>

// TODO 1: Completez cette fonction template.
// Elle doit pouvoir prendre n'importe quel conteneur (vector, list...) et l'afficher.
// Rappel: Pour declarer l'iterateur, vous aurez besoin de 'typename T::iterator'.
template <typename T>
void display(T & container) {
	// ... votre code ici ...
	// Créez un itérateur 'it' du type T::iterator (n'oubliez pas typename devant)
	typename T::iterator it;
	// Faites une boucle for de begin() à end()
	// Affichez *it suivi d'un espace
	for(it = container.begin(); it != container.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

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

	std::cout << "--- Exercice std::stack (Pile) ---" << std::endl;

	// TODO 1: Declarez une pile d'entiers (std::stack<int>) nommee 'myStack'.
	// Ajoutez les valeurs 10, 20, 30 avec la methode push().
	// ... votre code ici ...
	std::stack<int> myStack;
	myStack.push(10);
	myStack.push(20);
	myStack.push(30);

	// TODO 2: Essayez d'utiliser votre fonction display(myStack).
	// Decommentez la ligne suivante pour tester.
	//display(myStack); 
	// QUESTION : Pourquoi cela ne compile-t-il pas ? (Re-commentez la ligne apres avoir vu l'erreur).

	// TODO 3: Affichez et videz la pile manuellement.
	// Astuce : Tant que la pile n'est pas vide (!empty()), affichez le sommet (top()) puis retirez-le (pop()).
	std::cout << "Depilage : ";
	// ... votre code ici ...
	while(!myStack.empty()) {
		std::cout << " " << myStack.top();
		myStack.pop();
	}
	std::cout << std::endl;

	return 0;
}