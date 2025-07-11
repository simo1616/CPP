#include "Harl.hpp"


void Harl::debug(void) const {
    std::cout << HARL_DEBUG << std::endl;
}
void Harl::info(void)  const {
    std::cout << HARL_INFO << std::endl;
}
void Harl::warning(void) const {
    std::cout << HARL_WARNING << std::endl;
}
void Harl::error(void) const{
    std::cout << HARL_ERROR << std::endl;
}

void Harl::complain(const std::string& level) {
	static const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	static const HarlFunct actions[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	int i = 0;
	for(; i < 4; i++) {
		if(levels[i] == level) 
			break;
	}
	switch(i)
	{
		case(0):
			(this->*actions[0])();
			/* fall through */
		case(1):
			(this->*actions[1])();
			/* fall through */
		case(2):
			(this->*actions[2])();
			/* fall through */
		case(3):
			(this->*actions[3])();
			break;
		default:
			std::cout << HARL_UNKNOWN << std::endl;
			return;
	}
}