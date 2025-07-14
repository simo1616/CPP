/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:02:01 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 15:28:14 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

#define ORANGE  "\033[38;5;166m"
#define RESET   "\033[0m"

void	ft_replace				(std::string& line,
								const std::string& s1,
								const std::string& s2);

int		simply_copy_file		(const std::string& filename,
								const std::string& out_filename);

int		replace_in_file			(const std::string& filename,
								const std::string& s1,
								const std::string& s2);

int		usage_error();
int		empty_s1_error();

#endif