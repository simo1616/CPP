#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string input;
	while(true)
	{
		std::cout << "Inser commande : (ADD, SEARCH, or EXIT)\n";
		std::getline(std::cin, input);

		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			return(0);
		else
			std::cout << "INKNOW COMMANDE :(" << std::endl;
	}
	return 0;
}