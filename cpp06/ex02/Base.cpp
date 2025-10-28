#include "Base.hpp"

Base::~Base() {}

Base * generate(void) {
	int r = rand() % 3;
	if(!r)
		return(new A);
	else if(r == 1) 
		return(new B);
	else 
		return(new C);
}
void identify(Base* p) {
	if(!p) {
		std::cout << "class is NULL\n";
		return;
	}
	if(dynamic_cast<A*>(p)) {
		std::cout << "class identified : A\n";
		return;
	}
	else if(dynamic_cast<B*>(p)) {
		std::cout << "class identified : B\n";
		return;
	}
	else if(dynamic_cast<C*>(p)) {
		std::cout << "class identified : C\n";
		return;
	}
	else {
		std::cout << "class identified : Unknown\n";
		return;
	}
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "class identified : A\n";
		return;
	}
	catch (const std::exception& e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "class identified : B\n";
		return;
	}
	catch (const std::exception& e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "class identified : C\n";
		return;
	}
	catch (const std::exception& e) {}

	std::cout << "class identified : Unknown\n";

}