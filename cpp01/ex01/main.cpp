/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:21:42 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/11 19:52:24 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main ()
{
	int N = 5;
	std::string name = "Foo";
	Zombie *Z = zombieHorde(N, name);
	for(int i = 0; i < N; i++)
	{
		Z[i].announce();
	}
	delete[](Z);
	return(0);
}
