#include "Array.hpp"
#include <iostream> // N'oublie pas d'inclure iostream

class X_ET_Y {
	public:
		// Constructeur par défaut corrigé
		X_ET_Y() : _x(0) {}
		// Constructeur avec paramètres
		X_ET_Y(int x, std::string str) : _x(x), _str(str) {}

		// Pour pouvoir afficher l'objet, on donne accès à ses membres
		int getX() const { return _x; }
		const std::string& getStr() const { return _str; }

	private:
		int _x;
		std::string _str;
};

// On apprend à std::cout comment afficher un objet X_ET_Y
std::ostream& operator<<(std::ostream& os, const X_ET_Y& obj) {
	os << "X_ET_Y(x=" << obj.getX() << ", str='" << obj.getStr() << "')";
	return os;
}

int main () {
	// On crée UN SEUL objet Array qui contient 5 objets X_ET_Y
	unsigned int size = 5;
	Array<X_ET_Y> tablo(size);

	// On remplit notre Array avec des objets X_ET_Y
	for(unsigned int i = 0; i < tablo.size(); i++){
		tablo[i] = X_ET_Y(i, "test");
	}

	const Array<X_ET_Y> tatab = tablo;

	// On affiche le contenu de notre Array
	for(unsigned int i = 0; i < tatab.size(); i++){
		std::cout << "tatab[" << i << "] = " << tatab[i] << std::endl;
	}
}