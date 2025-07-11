# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstring>

class Zombie {
	public:
		Zombie();
		~Zombie();
		void setName(std::string Name);
		void announce() const;

	private:
		std::string	_name;
};

Zombie* zombieHorde(int N, std::string Name);


# endif