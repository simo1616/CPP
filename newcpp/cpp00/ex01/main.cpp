/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:01:56 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/20 10:20:19 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string input;
	while(std::cout << "Enter command (ADD, SEARCH, or EXIT)\n"
       && std::getline(std::cin, input))
	{
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
        {
            std::cout << "Good Bye! :)" << std::endl;
			return(0);
        }
		// else
		// 	std::cout << "UNKNOW COMMANDE :(" << std::endl;
	}
	return 0;
}