#include <iostream>
#include "Serializer.hpp"

int main() {
	Data d;
	d.x = 10;
	d.str = "str";

	Data* p = &d;

	std::cout << "p=" << p << " | x=" << p->x << " | str=" << p->str << "\n";
	uintptr_t raw = Serializer::serialize(p);
	std::cout << "raw(dec)=" << raw << " | raw(hex)=0x" << std::hex << raw << std::dec << "\n";

	Data* q = Serializer::deserialize(raw);
	std::cout << "q=" << q << " | x=" << q->x << " | str=" << q->str << "\n";
	std::cout << "same ptr? " << (p == q ? "YES" : "NO") << "\n";

	return (p == q) ? 0 : 1;
}
