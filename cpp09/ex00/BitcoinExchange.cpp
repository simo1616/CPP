#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
:_map(other._map) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
	if(this != &other)
		this->_map = other._map;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}
