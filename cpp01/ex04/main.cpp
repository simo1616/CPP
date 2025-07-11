#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>


std::string ft_replace(std::string line, const std::string s1, const std::string s2)
{
	std::size_t pos;
	pos = 0;
	pos = line.find(s1);
	
	while(pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
		pos = line.find(s1, pos);
	}
	return (line);
}

int main (int ac, char **av)
{
	if(ac != 4) {
		std::cerr 	<< "Error:\tArguments insuffisant" << std::endl
					<< "Usage:\t./replace <file_name> <s1> <s2>" << std::endl;
		return(1);
	}

	const std::string 	filename = av[1];
	const std::string 	s1 = av[2];
	const std::string 	s2 = av[3];
	std::ifstream		in;
	std::ofstream		out;
	std::string 		line;

	if(s1.empty())
	{
		std::perror("Error:\ts1 is empty");
		return(1);
	}
	in.open(filename.c_str());
	if(in)
	{
		out.open((filename + ".replace").c_str());
		if(out) 
		{
			while(std::getline(in, line))
			{

				line = ft_replace(line, s1, s2);
				out << line;
				if (in.peek() != EOF)
					out << std::endl;
			}
			out.close();
		}
		else
		{
			std::perror("Filename.replace Error");
			in.close();
			return (EXIT_FAILURE);
		}
		in.close();
	}
	else
	{
		std::perror("Error:\tFilename error.\nFilename.replace not created or truncated.");
		std::cerr << "" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
