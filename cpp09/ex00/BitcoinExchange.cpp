#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::string filename = "data.csv";
	std::string line;
	
	std::ifstream input(filename.c_str());
	if(!input.is_open()) {
		throw std::runtime_error(ERR_DATA_OPEN);
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
		throw std::runtime_error(ERR_DATA_READ);
	}
	if(_map.empty())
		throw std::runtime_error(ERR_DATA_EMPTY);	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
:_map(other._map) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
	if(this != &other)
		this->_map = other._map;
	return *this;
}

void BitcoinExchange::run(std::string filename) {
	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << ERR_FILE_OPEN << std::endl;
		return;
	}
	std::string line;
	while (std::getline(input, line)) {
		try {
			processLine(line);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

}

void BitcoinExchange::processLine(std::string const& line) {
	if(line.empty() || line == "date | value")
		return;
	std::size_t pos = line.find('|');
	if (pos == std::string::npos 
		|| line.length() < 13 
		|| pos != 11 || line[pos - 1] != ' ' 
		|| line[pos + 1] != ' ')
		throw BadInputException(ERR_BAD_INPUT + line);

	std::string date = line.substr(0, pos - 1);
	if(date[4] != '-' || date[7] != '-' )
		throw BadInputException(ERR_BAD_INPUT + line);
		
	std::string strYear = date.substr(0, 4);
	std::string strMonth = date.substr(5, 2);
	std::string strDay = date.substr(8, 2);

	int day;
	int month;
	int year;

	if(!strCheckDay(strDay, day))
		throw BadInputException(ERR_BAD_INPUT + date);
	if(!strCheckMonth(strMonth, month))
		throw BadInputException(ERR_BAD_INPUT + date);
	if(!strCheckYear(strYear, year, day, month))
		throw BadInputException(ERR_BAD_INPUT + date);

	std::string value = line.substr(pos + 1);
	
	double quantity;
	char *end;
	quantity = std::strtod(value.c_str(), &end);
	if(value.c_str() == end)
		throw BadInputException(ERR_BAD_INPUT + line);

	while(end && std::isspace(*end)) {end++;}
	if(*end != '\0')
		throw BadInputException(ERR_BAD_INPUT + date);
	if(quantity < 0)
		throw BadInputException(ERR_NEGATIVE);
	if(quantity > 1000)
		throw BadInputException(ERR_TOO_LARGE);

	std::map<std::string, double>::iterator it = _map.lower_bound(date);
	
	if (it == _map.begin() && it->first != date)
		throw BadInputException(ERR_DATE_EARLY + date);

	if (it == _map.end() || it->first != date)	it--;

	std::cout	<< date << " => "
				<< quantity << " = "
				<< it->second * quantity
				<< std::endl;
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

bool BitcoinExchange::strCheckMonth(std::string const& m, int& out) {
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
