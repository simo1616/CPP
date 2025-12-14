#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::string filename = "data.csv";
	std::string line;
	
	std::ifstream input(filename.c_str());
	if(!input.is_open()) {
		throw std::runtime_error("Error: could not open data.csv");
	}
	if(std::getline(input, line)) {
		while(std::getline(input, line)) {
			if(line.empty())
				continue;
			
			std::size_t pos = line.find(',');
			if(pos != 10)
				continue;

			std::string date = line.substr(0, pos);
			if (date[4] != '-' || date[7] != '-')
				continue;

			std::string value = line.substr(pos + 1);
			char* end;
			double price = std::strtod(value.c_str(), &end);
			
			while (*end && std::isspace(*end)) end++;
			if (*end == '\0' && end != value.c_str())
				_map[date] = price;
		}
	}
	if (input.bad()) {
		throw std::runtime_error("Error: I/O error while reading data.csv");
	}
	if(_map.empty())
		throw std::runtime_error("Error: data.csv is empty or invalid");	
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
:_map(other._map) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
	if(this != &other)
		this->_map = other._map;
	return *this;
}

void BitcoinExchange::display_map() const{

	std::map<std::string, double>::const_iterator it;
	std::cout 	<< "\n\n------- data in map -------\n" << std::endl;
	for (it = _map.begin(); it != _map.end(); ++it) {
		std::cout 	<< "Date: " << it->first 
					<<  " | Price: " << it->second << std::endl;
	}
}

void BitcoinExchange::run(std::string filename) {
	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(input, line)) {
		if(line.empty() || line == "date | value")
			continue;
		std::size_t pos = line.find('|');
		if (pos != 11)
			continue;

		std::string date = line.substr(0, pos - 1);
		if(date[4] != '-' || date[7] != '-' )
			continue;
			
		std::string strYear = date.substr(0, 4);
		std::string strMounth = date.substr(5, 2);
		std::string strDay = date.substr(8, 2);


		int day;
		int mount;
		int year;

		if(!strCheckDay(strDay, day)) continue;
		if(!strCheckMounth(strMounth, mount)) continue;
		if(!strCheckYear(strYear, year, day, mount)) continue;





		std::string value = line.substr(pos + 1);
		//std::cout << "line = " << line << std::endl;
		
		double quantity;
		char *end;
		quantity = std::strtod(value.c_str(), &end);
		while(end && std::isspace(*end)) {end++;}
		if(*end != '\0' || end == value.c_str())
			continue;
		if(quantity < 0 || quantity > 1000)
			continue;
		
		std::cout	<< date << " => "
					<< quantity << " = "
					<< "calcule"
					<< std::endl;

	}
}

bool BitcoinExchange::CheckBisex(int annee) {
	
	if (!(annee % 4)) {
		if(!(annee % 100)) {
			if(!(annee % 400)) {
			
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

bool BitcoinExchange::strCheckYear(std::string const& annee, int& out, int const d, int const m)
{
    char* end;
    errno = 0;

    long val = std::strtol(annee.c_str(), &end, 10);

    if (errno != 0 || *end != '\0' || val < 2009 || val > 2100)
        return false;

    out = static_cast<int>(val);
	if(m == 2) {
		if(!CheckBisex(out) && d > 28) return false;
		else if (CheckBisex(out) && d > 29) return false;
	}
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    return true;
}

bool BitcoinExchange::strCheckMounth(std::string const& m, int& out) {
	char *end;
	errno = 0;

	long val = std::strtol(m.c_str(), &end, 10);
	if(errno != 0 || *end != '\0' || val < 1 || val > 12)
		return false;
	out = static_cast<int>(val);
	return true;
}

bool BitcoinExchange::strCheckDay(std::string const& day, int& out) {
	char *end;
	errno = 0;

	long val = std::strtol(day.c_str(), &end, 10);
	if(errno != 0 || *end != '\0' || val < 1 || val > 31)
		return false;
	out = static_cast<int>(val);
	return true;
}


BitcoinExchange::~BitcoinExchange() {}
