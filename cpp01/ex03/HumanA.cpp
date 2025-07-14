/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 07:35:46 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 08:10:33 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) :name(name), _weapon(w) {
	
}

void HumanA::attack() {
	std::cout 	<< name << " attacks with their "
				<< _weapon.getType() << std::endl;
}