#include <iostream>
#include "Serializer.hpp"

int main() {
	Data* d = new Data;
	d->x   = 10;
	d->str = "str";

	std::cout 	<< "data x = " << d->x
				<< " | data str = " << d->str << std::endl;

	uintptr_t raw = Serializer::serialize(d);
	Data* back    = Serializer::deserialize(raw);

	std::cout 	<< "apres conversion" << std::endl;
	std::cout 	<< "data back x = " << back->x
				<< " | data back str = " << back->str << std::endl;

	delete d;
	return 0;
}
