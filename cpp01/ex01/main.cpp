#include "Zombie.hpp"
#include <iostream>

void testHorde(int N, const std::string& name) {
    std::cout << "\n=== Test N = " << N << " ===\n";
    Zombie* h = zombieHorde(N, name);
    if (!h) {
        std::cout << "-> returned NULL\n";
    } else {
        for (int i = 0; i < N; ++i)
            h[i].announce();
        delete[] h;
    }
}

int main() {
    testHorde(0,    "Nobody");
    testHorde(-3,   "Ghost");
    testHorde(1,    "Solo");
    testHorde(5,    "Pack");
    testHorde(12,   "Horde");

    return 0;
}


// int main(void)
// {
// 	int N = 12;
// 	Zombie *z = zombieHorde(N, "Marc");
// 	if(z)
// 	{
// 		for(int i = 0; i < N; ++i) {
// 			z[i].announce();
// 		}
// 		delete [] z;
// 	}
// 	return(0);
// }
