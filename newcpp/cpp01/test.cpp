/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:21:42 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 13:09:41 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string line = "simoo helloo";
	std::string s1 = "oo";
	std::string s2 = "AOW";

	std::cout << "\n\t\t\tINITIALISATION :" << std::endl;

	std::cout << "\t\t\tline = " << line << std::endl;
	std::cout << "\t\t\ts1 = " << s1 << std::endl;
	std::cout << "\t\t\ts2 = " << s2 << std::endl;




	int pos = 0;
	int index = 0;
	pos = line.find(s1, index);
	std::cout << "Avant la boucle \nline.find(s1) = " << pos << std::endl;

	while(pos != std::string::npos)
	{
		


		std::cout << "\nDans la boucle" << std::endl;
		index += pos + 1;
		std::cout << "index += pos = " << index << std::endl;

		// //remplacemnt
		std::cout 	<< "on erase de " << pos 
					<< " jusqu'a :" << s1.length() + pos
					<< std::endl;

		line.erase(pos, s1.length());
		line.insert(pos, s2);

		


		pos = line.find(s1, index);
		std::cout << "line.find(s1) = " << pos << std::endl;
	}

	std::cout << "\n\t\t\tRESULTAT :" << std::endl;
	std::cout << "\t\t\tline = " << line << std::endl;
	std::cout << "\t\t\ts1 = " << s1 << std::endl;
	std::cout << "\t\t\ts2 = " << s2 << std::endl;
	


	
	
	// index = 4;
	// pos = line.find(s1, index);
	// std::cout << "line.find(s1) = " << pos << std::endl;
	// std::cout << "index = " << index << std::endl;
	// index = 11;
	// pos = line.find(s1, index);
	// std::cout << "line.find(s1) = " << pos << std::endl;
	// std::cout << "index = " << index << std::endl;

}
