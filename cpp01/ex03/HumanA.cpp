/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:25:29 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/23 10:25:31 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const& name, Weapon& Weapon) 
	:_name(name), _weapon(Weapon) {}

HumanA::~HumanA(){}

void HumanA::attack() const {
	std::cout 
			<< _name << " attacks with their " 
			<<  _weapon.getType() << std::endl;
}
