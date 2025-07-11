#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define CLR_RESET   	"\033[0m"
#define CLR_RED     	"\033[31m"
#define CLR_GREEN   	"\033[32m"
#define CLR_YELLOW  	"\033[33m"
#define CLR_BLUE    	"\033[34m"
#define CLR_MAGENTA 	"\033[35m"
#define CLR_CYAN    	"\033[36m"

#define HARL_DEBUG   	CLR_CYAN	"[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define HARL_INFO    	CLR_GREEN	"[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define HARL_WARNING 	CLR_YELLOW	"[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#define HARL_ERROR   	CLR_RED		"[ERROR]\nThis is unacceptable! I want to speak to the manager now."
#define HARL_UNKNOWN 	CLR_MAGENTA	"[ Probably complaining about insignificant problems ]\n" \
                					"Although there are several ways to deal with Harl, " \
                					"one of the most effective is to SWITCH it off."
#define USAGE_MSG  					"Usage: ./harlFilter <LEVEL>\n" \
                    				"LEVEL must be one of DEBUG, INFO, WARNING or ERROR"


class Harl		{
	public:
		void complain(const std::string& level);
		
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
		typedef void (Harl::*HarlFunct)(void) const;

};

#endif