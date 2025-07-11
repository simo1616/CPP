/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:23:46 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/23 10:23:48 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const& name) 
	:_name(name), _weap(NULL) {}

HumanB::~HumanB(){}

void HumanB::attack() const {
	if(!_weap)
			std::cout << _name << " has no weapon to attack" << std::endl;
	else {
			std::cout 
				<< _name << " attacks with their " 
				<<  _weap->getType() << std::endl;
	}
} 

void HumanB::setWeapon(Weapon& weapon) {
	_weap = &weapon;
}
