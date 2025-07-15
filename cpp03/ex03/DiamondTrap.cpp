/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:09:01 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 16:03:27 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(),
ScavTrap(), 
FragTrap() {
	hitPoints    = 100;
    energyPoints = 50;
    attackDamage = 30;
	std::cout 	<< FG_INFO
				<< "Default constructor *DiamondTrap* " << Name << " called"
				<< RESET << std::endl;
}
	
DiamondTrap::DiamondTrap(std::string name) 
: ClapTrap(name + "_clap_name"), 
ScavTrap(), 
FragTrap() , 
Name(name) {
    energyPoints = 100;
	std::cout 	<< FG_INFO
				<< "ARG constructor *DiamondTrap* " << Name << " called"
				<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other) 
: ClapTrap(other),
ScavTrap(other), 
FragTrap(other),
Name(other.Name)  {
	std::cout 	<< FG_INFO
				<< "Copy constructor *DiamondTrap* " << Name << " called"
				<< RESET << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout 	<< FG_INFO
				<< "Destructor *DiamondTrap* " << Name << " called"
				<< RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other){
	if(this != &other)
	{
		Name 			= other.Name;
		hitPoints 		= other.hitPoints;
		energyPoints 	= other.energyPoints;
		attackDamage 	= other.attackDamage;
	}
	return *this;
}
	
void DiamondTrap::whoAmI() {
		std::cout 	<< FG_WARN
          			<< "*DiamondTrap* My name is " << DiamondTrap::Name  << " :D\n"
					<< "The name of my mother is: " << ClapTrap::Name
					<< " :D" << RESET << std::endl;
}

	
