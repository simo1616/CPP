/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:01:43 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 15:43:34 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void    ft_replace(std::string& line, const std::string& s1, const std::string& s2)
{
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

int    simply_copy_file(const std::string& filename, const std::string& out_filename)
{
	std::ifstream in(filename.c_str());
	if (!in.is_open())
	{
		std::cerr << ORANGE "[Error]\n->\tCan't open " << filename << RESET << std::endl;
		return 1;
	}

	std::ofstream out(out_filename.c_str());
	if (!out.is_open())
	{
		std::cerr << ORANGE "[Error]\n->\tCan't create/open " << out_filename << RESET << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(in, line))
	{
		out << line;
		if (!in.eof())
			out << std::endl;
	}

	return 0;
}

int    replace_in_file(const std::string& filename,
                       const std::string& s1,
                       const std::string& s2)
{
    if (s1 == s2)
    {
        std::string out_filename = filename + ".replace";
        return simply_copy_file(filename, out_filename);
    }

    std::ifstream in(filename.c_str());
    if (!in.is_open())
    {
        std::cerr << ORANGE "[Error]\n->\tCan't open " << filename << RESET << std::endl;
        return 1;
    }

    std::string out_filename = filename + ".replace";
    std::ofstream out(out_filename.c_str());
    if (!out.is_open())
    {
        std::cerr << ORANGE "[Error]\n->\tCan't create/open " << out_filename << RESET << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(in, line))
    {
        ft_replace(line, s1, s2);
        out << line;
        if (!in.eof())
            out << std::endl;
    }
    return 0;
}

int usage_error()
{
	std::cerr << ORANGE "[Error]\n->\tUsage ./sed <filename> <s1> <s2>" RESET << std::endl;
	return 1;
}

int empty_s1_error()
{
	std::cerr << ORANGE "[Error]\n->\t<s1> cannot be empty" RESET << std::endl;
	return 1;
}

