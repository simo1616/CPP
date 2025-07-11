# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstring>

class Zombie {
	public:
		Zombie(std::string Name);
		~Zombie();
		//void setName(std::string Name);
		void announce() const;

	private:
		std::string	_name;
};

Zombie* newZombie(std::string Name);
void	randomChump(std::string Name);


# endif