/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:12:39 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/15 11:00:28 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap A("Foo");
	ClapTrap B("Bob");

	std::cout << "\n-- Phase d’échange de coups --\n\n";
	A.attack("Bob");
	B.takeDamage(3);
	B.attack("Foo");
	A.takeDamage(3);

	std::cout << "\n-- Phase de réparation --\n\n";
	A.beRepaired(2);
	B.beRepaired(2);

	std::cout << "\n-- Épuisement de l’énergie de Foo --\n\n";
	for (int i = 0; i < 10; ++i)
		A.attack("Bob");
	A.attack("Bob");

	std::cout << "\n-- Foo essaie de se réparer sans énergie --\n\n";
	A.beRepaired(5);

	std::cout << "\n-- Mise hors service de Bob --\n\n";
	B.takeDamage(20);
	B.attack("Foo");
	B.beRepaired(5);

	return 0;
}



// int main()
// {
//     // Création d’un ClapTrap unique
//     ClapTrap A("Simo");

//     // Quelques actions de base
//     A.attack("Bob");         // 1ère attaque, énergie passe de 10 → 9
//     A.takeDamage(3);         // subit 3 points de dégâts, PV passent de 10 → 7
//     A.beRepaired(5);         // se répare de 5 PV, PV passent de 7 → 12

//     // Épuisement de l’énergie par attaques successives
//     for (int i = 0; i < 9; ++i) {
//         A.attack("Enemy");   // tirage de 9 points d’énergie → plus d’énergie
//     }
//     A.attack("Enemy");       // tentative d’attaque sans énergie

//     // Tentative de réparation quand l’énergie est nulle
//     A.beRepaired(3);

//     // Mise hors service par dégâts
//     A.takeDamage(15);        // subit 15 points, PV passent à 0 (désormais détruit)

//     // Actions après destruction : ne doivent rien faire
//     A.attack("Nobody");
//     A.beRepaired(5);

//     return 0;
// }
