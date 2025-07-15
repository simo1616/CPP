/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:12:39 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 13:40:13 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Construction/Destruction ===\n";

    std::cout << "\n--- ClapTrap Construction with Arg ---\n";
    {
        ClapTrap ct1("CT1");
    }

    std::cout << "\n--- ClapTrap Default Construction ---\n";
    {
        ClapTrap ct2;
    }

    std::cout << "\n--- ScavTrap Construction with Arg ---\n";
    {
        ScavTrap st1("ST1");
    }

    std::cout << "\n--- ScavTrap Default Construction ---\n";
    {
        ScavTrap st2;
    }

    std::cout << "\n--- FragTrap Construction with Arg ---\n";
    {
        FragTrap ft1("FT1");
    }

    std::cout << "\n--- FragTrap Default Construction ---\n";
    {
        FragTrap ft2;
    }


    std::cout << "\n=== Copy & Assignment ===\n";

    std::cout << "\n--- ClapTrap Copy & Assignment ---\n";
    {
        ClapTrap a("CopyCT");
        ClapTrap b(a);
        ClapTrap c;
        c = a;
    }

    std::cout << "\n--- ScavTrap Copy & Assignment ---\n";
    {
        ScavTrap a("CopyST");
        ScavTrap b(a);
        ScavTrap c;
        c = a;
    }

    std::cout << "\n--- FragTrap Copy & Assignment ---\n";
    {
        FragTrap a("CopyFT");
        FragTrap b(a);
        FragTrap c;
        c = a;
    }


    std::cout << "\n=== Attack Overrides ===\n";

    std::cout << "\n--- ClapTrap Attack ---\n";
    {
        ClapTrap base("Base");
        base.attack("X");
    }

    std::cout << "\n--- ScavTrap Attack ---\n";
    {
        ScavTrap s("V1");
        s.attack("X");
    }

    std::cout << "\n--- FragTrap Attack ---\n";
    {
        FragTrap f("V2");
        f.attack("X");
    }


    std::cout << "\n=== Special Abilities ===\n";

    std::cout << "\n--- ScavTrap guardGate ---\n";
    {
        ScavTrap g("Gate");
        g.guardGate();
        g.guardGate();
    }

    std::cout << "\n--- FragTrap highFivesGuys ---\n";
    {
        FragTrap h("High");
        h.highFivesGuys();
        h.highFivesGuys();
    }


    std::cout << "\n=== Inherited Behaviors ===\n";

    std::cout << "\n--- ClapTrap takeDamage/beRepaired ---\n";
    {
        ClapTrap c("CTest");
        c.takeDamage(5);
        c.beRepaired(3);
    }

    std::cout << "\n--- ScavTrap takeDamage/beRepaired ---\n";
    {
        ScavTrap s("STest");
        s.takeDamage(5);
        s.beRepaired(3);
    }

    std::cout << "\n--- FragTrap takeDamage/beRepaired ---\n";
    {
        FragTrap f("FTest");
        f.takeDamage(5);
        f.beRepaired(3);
    }


    std::cout << "\n=== Energy Exhaustion ===\n";

    std::cout << "\n--- ScavTrap Energy Exhaustion ---\n";
    {
        ScavTrap s("SEcho");
        for (int i = 0; i < 50; ++i) s.attack("Dummy");
        s.attack("Dummy");
    }

    std::cout << "\n--- FragTrap Energy Exhaustion ---\n";
    {
        FragTrap f("FEcho");
        for (int i = 0; i < 100; ++i) f.attack("Dummy");
        f.attack("Dummy");
    }


    std::cout << "\n=== Lethal Damage ===\n";

    std::cout << "\n--- ClapTrap Lethal Damage ---\n";
    {
        ClapTrap c("CLethal");
        c.takeDamage(10);
        c.takeDamage(1);
    }

    std::cout << "\n--- ScavTrap Lethal Damage ---\n";
    {
        ScavTrap s("SLethal");
        s.takeDamage(100);
        s.takeDamage(1);
    }

    std::cout << "\n--- FragTrap Lethal Damage ---\n";
    {
        FragTrap f("FLethal");
        f.takeDamage(200);
        f.takeDamage(1);
    }


    std::cout << "\n=== Interaction ===\n";
    {
        ClapTrap c("C");
        ScavTrap s("S");
        FragTrap f("F");
        c.attack("S");
        s.takeDamage(0);
        s.attack("F");
        f.takeDamage(20);
        f.attack("C");
        c.takeDamage(30);
    }


    std::cout << "\n=== Final Destruction Chain ===\n";
    return 0;
}
