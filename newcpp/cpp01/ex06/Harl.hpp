/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:21:19 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 19:28:59 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define ORANGE		"\033[38;5;208m"
#define LI_ORANGE	"\033[38;5;214m"
#define GOLD		"\033[38;5;220m"
#define SALMON		"\033[38;5;209m"
#define DARK_ORANGE	"\033[38;5;166m"
#define CORAL		"\033[38;5;203m"
#define PEACH_PUFF	"\033[38;5;224m"
#define GREEN		"\033[0;92m"
#define YELLOW		"\033[0;93m"
#define BLUE		"\033[0;94m"
#define MAGENTA		"\033[0;95m"
#define CYAN		"\033[0;96m"
#define RESET		"\033[0m"

#define DEBUG   GREEN   	"[DEBUG]	\tChecking system state…"								RESET
#define INFO    YELLOW  	"[INFO]		Everything is running smoothly."					RESET
#define WARNING PEACH_PUFF 	"[WARNING]	That might cause problems soon."					RESET
#define ERROR   DARK_ORANGE "[ERROR]	\tCritical failure – aborting now!"					RESET

#define ERR_ARG	GOLD 		"[Error]	\tusage: ./harl <LEVEL>"								RESET
#define UNKNOW	GOLD 		"[UNKNOW]	Probably complaining about insignificant problems"	RESET

enum levnum {
	DEB,
	INF,
	WAR,
	ERR
};

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		typedef void (Harl::*funct)(void);
		static const std::string levels[4];
		static const funct actions[4];
	public:
		void complain( std::string level );
};

#endif