/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:48:27 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 12:18:26 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 20;
	std::cout 	<< FG_INFO
				<< "Default constructor *ScavTrap* " << Name << " called"
				<< RESET << std::endl;
}
	
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 20;
	std::cout 	<< FG_INFO
				<< "ARG constructor *ScavTrap* " << Name << " called"
				<< RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other) {
	std::cout 	<< FG_INFO
				<< "Copy constructor *ScavTrap* " << Name << " called"
				<< RESET << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout 	<< FG_INFO
				<< "Destructor *ScavTrap* " << Name << " called"
				<< RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& other){
	if(this != &other)
	{
		Name 			= other.Name;
		hitPoints 		= other.hitPoints;
		energyPoints 	= other.energyPoints;
		attackDamage 	= other.attackDamage;
	}
	return *this;
}
	
void ScavTrap::attack(const std::string& target){
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout 	<< FG_SUCCESS
					<< "*ScavTrap* " << Name
					<< " attacks " << target
					<< ", causing " << attackDamage
					<< " points of damage! It now has " << energyPoints
					<< " energy points remaining."
					<< RESET << std::endl;
	}

	else if (energyPoints == 0)
		std::cout 	<< FG_WARN
					<< "*ScavTrap* " << Name
					<< " has no energy left to attack!"
					<< RESET << std::endl;

	else
		std::cout 	<< FG_ERROR
					<< "*ScavTrap* " << Name
					<< " cannot attack because it has no hit points remaining!"
					<< RESET << std::endl;
}
	
void ScavTrap::guardGate() {
		std::cout 	<< FG_WARN
          			<< "*ScavTrap* " << Name
          			<< " has entered Gate keeper mode!"
          			<< RESET << std::endl;
}

	