/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 07:22:46 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 07:28:14 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t) :type(t) {}

std::string&	Weapon::getType() {
	return(this->type);
}


void			Weapon::setType(std::string type) {
	this->type = type;
}