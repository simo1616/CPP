#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl		{
	public:
		void complain(std::string level);
		
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		typedef void (Harl::*HarlFunct)(void);
		static const char*   levels[4];
    	static const HarlFunct actions[4];
};

#endif