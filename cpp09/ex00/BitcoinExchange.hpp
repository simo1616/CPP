#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdexcept>

class BitcoinExchange {
	public :
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& other);
		BitcoinExchange& operator=(BitcoinExchange const& other);
		void display_map(); // a implementer aprés
		~BitcoinExchange();

	private :
		std::map<int, double> _map;
};


#endif