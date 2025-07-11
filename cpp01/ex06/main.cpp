#include "Harl.hpp"

// enum level {
// 	debug,
// 	info,
// 	warning,
// 	error,
// 	unknow
// };

int main(int ac, char **av) {
    Harl harl;
    if (ac != 2) {
        std::cerr << CLR_RED << USAGE_MSG << CLR_RESET << std::endl;
        return 1;
    }
    harl.complain(av[1]);
    return 0;
}
