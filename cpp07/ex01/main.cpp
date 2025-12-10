#include "iter.hpp"

void add_then(int &n) {
	n = n + 10;
}

void add_ooo(std::string &word) {
	word = word + "ooo";
}

void print(int const & n) {
    std::cout << n << std::endl;
}

int main () {
	{
		int array[3] = {1,2,3};

		std::cout 		<< "BEFOR ::iter"
						<< std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout 	<< "array[" << i << "] = "
						<< array[i] << std::endl;
		}

		::iter(array, 3, add_then);

		std::cout 		<< "AFTER ::iter"
						<< std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout 	<< "array[" << i << "] = "
						<< array[i] << std::endl;
		}
	}
	{
		std::string tablo[3] = {"simo", "sofa", "salim"};
		std::cout 		<< "BEFOR ::iter"
						<< std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout 	<< "tablo[" << i << "] = "
						<< tablo[i] << std::endl;
		}

		::iter(tablo, 3, add_ooo);
		std::cout 		<< "AFTER ::iter"
						<< std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout 	<< "tablo[" << i << "] = "
						<< tablo[i] << std::endl;
		}
	}

	{
		int const array[3] = {1,2,3};

		std::cout 		<< "BEFOR ::iter"
						<< std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout 	<< "array[" << i << "] = "
						<< array[i] << std::endl;
		}

		::iter(array, 3, print);

		std::cout 		<< "AFTER ::iter"
						<< std::endl;
		for(int i = 0; i < 3; i++) {
			std::cout 	<< "array[" << i << "] = "
						<< array[i] << std::endl;
		}
	}
}