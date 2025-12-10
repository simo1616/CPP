#include "Base.hpp"

Base::~Base() {}

Base * generate(void) {
	int r = rand() % 3;
	if(r == 0)
		return new A;
	else if(r == 1)
		return new B;
	else 
		return new C;
}
void identify(Base* p) {
	if(!p) {
		std::cout << "class is NULL\n";
		return;
	}
	if(dynamic_cast<A*>(p)) {
		std::cout << "class identified: A\n";
	}
	else if(dynamic_cast<B*>(p)) {
		std::cout << "class identified: B\n";
	}
	else if(dynamic_cast<C*>(p)) {
		std::cout << "class identified: C\n";
	}
	else {
		std::cout << "class identified: Unknown\n";
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "class identified: A\n";
		return;
	}
	catch (const std::exception& e) {(void)e;}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "class identified: B\n";
		return;
	}
	catch (const std::exception& e) {(void)e;}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "class identified: C\n";
	}
	catch (const std::exception& e) {
		(void)e;
		std::cout << "class identified: Unknown\n";
	}
}