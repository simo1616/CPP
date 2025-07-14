/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:21:15 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 19:36:32 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
	std::cerr << DEBUG << std::endl;
}

void Harl::info( void ) {
	std::cerr << INFO << std::endl;
}

void Harl::warning( void ) {
	std::cerr << WARNING << std::endl;
}

void Harl::error( void ) {
	std::cerr << ERROR << std::endl;
}

const std::string Harl::levels[4] = {
	"DEBUG","INFO","WARNING","ERROR"
};

const Harl::funct Harl::actions[4] = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

void Harl::complain( std::string level ) {
	int i = 0;
	for(i = 0; i < 4; i++)
	{
		if(level == levels[i])
			break;
	}
	switch (i)
	{
		case DEB:
			(this->*actions[DEB])();
			// fall through
		case INF:
			(this->*actions[INF])();
			// fall through
		case WAR:
			(this->*actions[WAR])();
			// fall through
		case ERR:
			(this->*actions[ERR])();
			break;
		
		default:
			std::cout << UNKNOW << std::endl;
			return;
	}
}