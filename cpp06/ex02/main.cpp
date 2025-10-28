#include "Base.hpp"

class D : public Base {};

int main() {
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		Base *ptr = generate();

		std::cout << "[Test " << i << "] via pointeur : ";
		identify(ptr);

		std::cout << "[Test " << i << "] via référence : ";
		identify(*ptr);

		delete ptr;
		std::cout << "-------------------------------\n";
	}

	std::cout << "Test NULL pointer\n";
	identify(NULL);

	std::cout << "Test Unknown class (D)\n";
	D d;
	identify(&d);
	identify(d);

	return 0;
}

