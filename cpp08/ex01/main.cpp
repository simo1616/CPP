#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	Span sp(15000);

	std::vector<int> bigvec(15000);
	for (std::vector<int>::iterator it = bigvec.begin(); it != bigvec.end(); ++it) {
		*it = std::rand();
	}
	sp.addNumber(bigvec.begin(), bigvec.end());
	// sp.display();
	
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span:  " << sp.longestSpan() << std::endl;

	return 0;
}
// {
//     Span sp = Span(6);
//     sp.addNumber(2);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);


// 	//sp.display();
// 	try {
// 		std::cout << sp.shortestSpan() << std::endl;
// 	}
// 	catch (std::logic_error &e) {
// 		std::cerr << "Catched : " << e.what() << std::endl;
// 	}

// 	std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }