#include "Array.hpp"

class X_ET_Y {
	public:
		X_ET_Y() : _x(0) {}
		X_ET_Y(int x, std::string str) : _x(x), _str(str) {}

		int getX() const { return _x; }
		const std::string& getStr() const { return _str; }

	private:
		int _x;
		std::string _str;
};

std::ostream& operator<<(std::ostream& os, const X_ET_Y& obj) {
	os << "X_ET_Y(x=" << obj.getX() << ", str='" << obj.getStr() << "')";
	return os;
}

int main () {
	unsigned int size = 5;
	Array<X_ET_Y> tablo(size);

	for(unsigned int i = 0; i < tablo.size(); i++){
		tablo[i] = X_ET_Y(i, "test");
	}

	const Array<X_ET_Y> tatab = tablo;

	for(unsigned int i = 0; i < tatab.size(); i++){
		std::cout << "tatab[" << i << "] = " << tatab[i] << std::endl;
	}

	std::cout << "\n--- Test d'affectation (Deep Copy) ---" << std::endl;
	Array<X_ET_Y> copyAssign;
	copyAssign = tablo; // Test explicite de l'opérateur =
	
	tablo[0] = X_ET_Y(999, "MODIFIED");
	std::cout << "Original modifié [0] : " << tablo[0] << std::endl;
	std::cout << "Copie (doit rester intacte) [0] : " << copyAssign[0] << std::endl;

	std::cout << "\n--- Test d'exception (Out of Range) ---" << std::endl;
	try {
		std::cout << "tentative d'accès à l'index invalide..." << std::endl;
		std::cout << tablo[500] << std::endl; // Doit lancer une exception
	} catch (const std::exception& e) {
		std::cerr << "exception catched : " << e.what() << std::endl;
	}

	std::cout << "\n--- Test tableau vide ---" << std::endl;
	Array<int> emptyArray;
	std::cout << "Taille tableau vide : " << emptyArray.size() << std::endl;
}