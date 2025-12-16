#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <cctype>


class BitcoinExchange {
	public :
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& other);
		BitcoinExchange& operator=(BitcoinExchange const& other);
		void display_map() const;
		void run(std::string filename);
		bool CheckBisex(int annee);
		bool strCheckYear(std::string const& annee, int& out, int const d, int const m);
		bool strCheckMonth(std::string const& m, int& out);
		bool strCheckDay(std::string const& day, int& out);
		~BitcoinExchange();

	private :
		std::map<std::string, double> _map;
};


#endif