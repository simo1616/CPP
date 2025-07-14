/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 08:15:20 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 08:58:26 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :name(name), weapon(NULL) {
}

void HumanB::setWeapon(Weapon &w) {
	weapon = &w;
}

void HumanB::attack() {
	if (weapon) {
		std::cout 	<< name << " attacks with their "
					<< weapon->getType()
					<< std::endl;
	} else {
		std::cout 	<< name << " has no weapon to attack with!" 
					<< std::endl;
	}
}
