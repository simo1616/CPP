#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

#define ERR_FILE_OPEN	"Error: could not open file."
#define ERR_DATA_OPEN	"Error: could not open data.csv"
#define ERR_DATA_READ	"Error: while reading data.csv"
#define ERR_DATA_EMPTY	"Error: data.csv is empty or invalid"
#define ERR_BAD_INPUT	"Error: bad input => "
#define ERR_NEGATIVE 	"Error: not a positive number."
#define ERR_TOO_LARGE 	"Error: too large a number."
#define ERR_DATE_EARLY	"Error: Date too early => "


class BitcoinExchange {
	public :
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& other);
		BitcoinExchange& operator=(BitcoinExchange const& other);
		void run(std::string filename);
		bool CheckBisex(int annee);
		bool strCheckYear(std::string const& annee, int& out, int const d, int const m);
		bool strCheckMonth(std::string const& m, int& out);
		bool strCheckDay(std::string const& day, int& out);
		
		class BadInputException : public std::exception {
			public:
				BadInputException(std::string msg) :_msg(msg) {}
				virtual const char* what() const throw() {return _msg.c_str();}
				virtual ~BadInputException() throw() {}
			private:
				std::string _msg;
		};
		~BitcoinExchange();

	private :
		std::map<std::string, double> _map;
		void processLine(std::string const& line);
};


#endif