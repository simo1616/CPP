/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:06:26 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 13:30:18 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;
	std::cout 	<< FG_INFO
				<< "Default constructor *FragTrap* " << Name << " called"
				<< RESET << std::endl;
}
	
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hitPoints    = 100;
    energyPoints = 100;
    attackDamage = 30;
	std::cout 	<< FG_INFO
				<< "ARG constructor *FragTrap* " << Name << " called"
				<< RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other) {
	std::cout 	<< FG_INFO
				<< "Copy constructor *FragTrap* " << Name << " called"
				<< RESET << std::endl;
}

FragTrap::~FragTrap(){
	std::cout 	<< FG_INFO
				<< "Destructor *FragTrap* " << Name << " called"
				<< RESET << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& other){
	if(this != &other)
	{
		Name 			= other.Name;
		hitPoints 		= other.hitPoints;
		energyPoints 	= other.energyPoints;
		attackDamage 	= other.attackDamage;
	}
	return *this;
}
	
void FragTrap::attack(const std::string& target){
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout 	<< FG_SUCCESS
					<< "*FragTrap* " << Name
					<< " attacks " << target
					<< ", causing " << attackDamage
					<< " points of damage! It now has " << energyPoints
					<< " energy points remaining."
					<< RESET << std::endl;
	}

	else if (energyPoints == 0)
		std::cout 	<< FG_WARN
					<< "*FragTrap* " << Name
					<< " has no energy left to attack!"
					<< RESET << std::endl;

	else
		std::cout 	<< FG_ERROR
					<< "*FragTrap* " << Name
					<< " cannot attack because it has no hit points remaining!"
					<< RESET << std::endl;
}

void FragTrap::highFivesGuys() {
		std::cout << FG_SUCCESS
					<< "FragTrap " << Name
					<< " requests a positive high five! ✋"
					<< RESET << std::endl;
}

	