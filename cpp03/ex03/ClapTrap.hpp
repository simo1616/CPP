/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:13:54 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 11:41:17 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

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

#define FG_INFO      "\033[38;5;117m"
#define FG_SUCCESS   "\033[38;5;82m"
#define FG_WARN      "\033[38;5;220m"
#define FG_ERROR     "\033[38;5;130m"
#define FG_DAMAGE    "\033[38;5;214m"
#define FG_FATAL     "\033[38;5;166m"
#define RESET		"\033[0m"

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& other);
		ClapTrap& operator=(ClapTrap const& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		~ClapTrap();
	protected:
		std::string 	Name;
		unsigned int 	hitPoints;
		unsigned int 	energyPoints;
		unsigned int 	attackDamage;
};

#endif