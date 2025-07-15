/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:04:02 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:21 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
#define DIAMONTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public :
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& other);
		DiamondTrap& operator=(DiamondTrap const& other);
		using ClapTrap::takeDamage;
		using ClapTrap::beRepaired;
		using ScavTrap::attack;
		using ScavTrap::guardGate;
		using FragTrap::highFivesGuys;
		void whoAmI();
		~DiamondTrap();
	private:
		std::string Name;
};

#endif