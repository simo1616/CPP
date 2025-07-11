/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:24:54 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/23 10:25:07 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const & t) :type(t) {}

Weapon::~Weapon() {}

std::string const &  Weapon::getType() const {
	return(this->type);
}

void Weapon::setType(std::string const & newType) {
	type = newType;
} 