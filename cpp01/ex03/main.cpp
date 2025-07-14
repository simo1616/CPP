/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:21:42 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 09:03:32 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int main()
{
	std::cout << "=== Test original ===\n";
	{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	std::cout << "\n=== Test HumanB sans arme ===\n";
	{
		Weapon knife("sharp knife");
		HumanB ana("Ana");
		ana.attack();
		ana.setWeapon(knife);
		ana.attack();
	}

	std::cout << "\n=== Test réassignation d’arme à HumanB ===\n";
	{
		Weapon sword("long sword");
		Weapon axe("battle axe");
		HumanB lee("Lee");
		lee.setWeapon(sword);
		lee.attack();

		lee.setWeapon(axe);
		lee.attack();
	}

	std::cout << "\n=== Test partage de la même arme entre deux humains ===\n";
	{
		Weapon shared("dual-wield dagger");
		HumanA al("Al", shared);
		HumanB eve("Eve");
		eve.setWeapon(shared);
		al.attack();
		eve.attack();

		shared.setType("enchanted dagger");
		al.attack();
		eve.attack();
	}

	return 0;
}
