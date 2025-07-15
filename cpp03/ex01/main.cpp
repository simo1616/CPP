/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:12:39 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 12:58:52 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== ScavTrap Construction with Arg & Destruction ===\n";
    {
        ScavTrap t1("Junky");
    }

    std::cout << "\n=== ScavTrap Default Construction & Destruction ===\n";
    {
        ScavTrap t2;
    }

    std::cout << "\n=== ScavTrap Copy Construction & Destruction ===\n";
    {
        ScavTrap src("Guardian");
        ScavTrap dst(src);
    }

    std::cout << "\n=== Operator= Test ===\n";
    ScavTrap A("AlphaScav");
    ScavTrap B("BetaScav");
    A = B;
    A.attack("X");

    std::cout << "\n=== ClapTrap Basic Behavior ===\n";
    {
        ClapTrap solo("SoloTrap");
        solo.attack("Tgt");
        solo.takeDamage(5);
        solo.beRepaired(3);
        for (int i = 0; i < 10; ++i)
            solo.attack("Tgt");
        solo.attack("Tgt");
    }

    std::cout << "\n=== ClapTrap Energy Exhaustion ===\n";
    {
        ClapTrap ct("Charlie");
        for (int i = 0; i < 10; ++i)
            ct.attack("Dummy");
        ct.attack("Dummy");
    }

    std::cout << "\n=== Interaction ClapTrap vs ScavTrap ===\n";
    {
        ClapTrap clp("Clappy");
        ScavTrap scv("Scavy");
        clp.attack("Scavy");
        scv.takeDamage(0);
        scv.attack("Clappy");
        clp.takeDamage(20);
        clp.takeDamage(1);
    }

    std::cout << "\n=== Exact Lethal Damage on ClapTrap ===\n";
    {
        ClapTrap exact("Exact");
        exact.takeDamage(10);
        exact.takeDamage(1);
        exact.beRepaired(1);
    }

    std::cout << "\n=== guardGate Idempotence ===\n";
    {
        ScavTrap gate("GateKeeper");
        gate.guardGate();
        gate.guardGate();
    }

    std::cout << "\n=== ScavTrap Energy Exhaustion & Repair ===\n";
    {
        ScavTrap echo("EchoScav");
        for (int i = 0; i < 50; ++i)
            echo.attack("Dummy");
        echo.attack("Dummy");
        echo.beRepaired(10);
    }

    std::cout << "\n=== Final Destruction Chain ===\n";
    return 0;
}

