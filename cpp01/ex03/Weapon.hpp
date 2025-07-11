/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:25:16 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/23 10:25:18 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string> 


class Weapon {
	public :
		Weapon(std::string const & t);
		~Weapon();
		std::string const & getType() const;
		void setType(std::string const & newType);


	private :
		std::string type;
};




#endif 