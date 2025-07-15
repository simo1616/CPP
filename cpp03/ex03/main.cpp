/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:12:39 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 15:44:59 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== DiamondTrap Construction/Destruction ===\n\n";
    {
        DiamondTrap dt1("Alpha");
    }
    {
        DiamondTrap dt2;
    }

    std::cout << "\n=== DiamondTrap Copy & Assignment ===\n\n";
    {
        DiamondTrap original("CopyMe");
        DiamondTrap copyConstructed(original);
        DiamondTrap assigned;
        assigned = original;
    }

    std::cout << "\n=== DiamondTrap Identity Test ===\n\n";
    DiamondTrap gem("Gemini");
    std::cout << "-- whoAmI() --\n";
    gem.whoAmI();

    std::cout << "\n=== Combat Attributes Test ===\n\n";
    std::cout << "-- Hit Points (should stay 100) --\n";
    gem.takeDamage(0);

    std::cout << "\n-- Energy & Attack Damage --\n";
    gem.attack("TargetBot");

    std::cout << "\n=== Energy Exhaustion ===\n\n";
    for (int i = 0; i < 50; ++i)
        gem.attack("Dummy");
    gem.attack("Dummy");

    std::cout << "\n=== Repair & Damage Limits ===\n\n";
    std::cout << "-- Damage then Repair --\n";
    gem.takeDamage(20);
    gem.beRepaired(10);

    std::cout << "\n-- Lethal Damage then Actions --\n";
    gem.takeDamage(200);
    gem.attack("Nobody");
    gem.beRepaired(5);

    std::cout << "\n=== Final Destruction Chain ===\n";
    return 0;
}

