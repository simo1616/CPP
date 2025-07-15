/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 07:07:09 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 12:05:06 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrap.cpp
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: Name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout	<< FG_INFO
				<< "Default constructor ClapTrap " << Name << " called"
				<< RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: Name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout	<< FG_INFO
				<< "ARG constructor ClapTrap " << Name << " called"
				<< RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other)
: Name(other.Name)
, hitPoints(other.hitPoints)
, energyPoints(other.energyPoints)
, attackDamage(other.attackDamage)
{
	std::cout 	<< FG_INFO
				<< "Copy constructor ClapTrap " << Name << " called"
				<< RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other) {
	if(this != &other)
	{
		Name 			= other.Name;
		hitPoints 		= other.hitPoints;
		energyPoints 	= other.energyPoints;
		attackDamage 	= other.attackDamage;
	}
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout 	<< FG_INFO
				<< "Destructor ClapTrap " << Name << " called"
				<< RESET << std::endl;
}

// attack
void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout 	<< FG_SUCCESS
					<< "ClapTrap " << Name
					<< " attacks " << target
					<< ", causing " << attackDamage
					<< " points of damage! It now has " << energyPoints
					<< " energy points remaining."
					<< RESET << std::endl;
	}

	else if (energyPoints == 0)
		std::cout 	<< FG_WARN
					<< "ClapTrap " << Name
					<< " has no energy left to attack!"
					<< RESET << std::endl;

	else
		std::cout 	<< FG_ERROR
					<< "ClapTrap " << Name
					<< " cannot attack because it has no hit points remaining!"
					<< RESET << std::endl;
}

// takeDamage
void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0)
		std::cout 	<< FG_ERROR
					<< "ClapTrap " << Name
					<< " is already destroyed and can’t take more damage!"
					<< RESET << std::endl;
	else if (amount < hitPoints) {
		hitPoints -= amount;
		std::cout 	<< FG_DAMAGE
					<< "ClapTrap " << Name
					<< " takes " << amount
					<< " points of damage! It now has " << hitPoints
					<< " hit points remaining."
					<< RESET << std::endl;
	}
	else {
		hitPoints = 0;
		std::cout 	<< FG_FATAL
					<< "ClapTrap " << Name
					<< " takes " << amount
					<< " points of damage and has been destroyed!"
					<< RESET << std::endl;
	}
}

// beRepaired
void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints == 0) 
		std::cout 	<< FG_ERROR
					<< "ClapTrap " << Name
					<< " cannot repair itself because it has been destroyed!"
					<< RESET << std::endl;
	else if (energyPoints == 0)
		std::cout 	<< FG_FATAL
					<< "ClapTrap " << Name
					<< " has no energy left to repair itself!"
					<< RESET << std::endl;
	else {
		energyPoints--;
		hitPoints += amount;
		std::cout 	<< FG_SUCCESS
					<< "ClapTrap " << Name
					<< " repairs itself, regaining " << amount
					<< " hit points! It now has " << hitPoints
					<< " hit points."
					<< RESET << std::endl;
	}
}
