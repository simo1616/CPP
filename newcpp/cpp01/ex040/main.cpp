/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:01:27 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 15:09:45 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return usage_error();

	if (av[2][0] == '\0')
		return empty_s1_error();

	return replace_in_file(av[1], av[2], av[3]);
}

