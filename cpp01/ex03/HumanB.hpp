/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:23:42 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/23 10:23:44 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB {
	public :
		HumanB(std::string const& name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon& weapon);

	private :
		std::string _name;
		Weapon* _weap;
};

#endif 