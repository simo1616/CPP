#include "Span.hpp"

Span::Span() :_n(0) {}

Span::Span(unsigned int n) :_n(n) {}

Span::Span(const Span &other):_n(other._n), _vec(other._vec) {}

Span& Span::operator=(const Span &other) {
	if(this != &other) {
		this->_n = other._n;
		this->_vec = other._vec;
	}
	return(*this);
}

void Span::addNumber(int value) {
	if(_vec.size() >= _n)
		throw std::runtime_error("Size maximum");
	_vec.push_back(value);
}

void Span::display() {
	std::vector<int>::iterator it;

	for(it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout	<< " " << *it << std::endl; 
	}
	// std::vector<int>::iterator n_min = std::min_element(_vec.begin(), _vec.end());
	// std::cout << "le nombre min = " << *n_min << std::endl;
	// std::vector<int>::iterator n_max = std::max_element(_vec.begin(), _vec.end());
	// std::cout << "le nombre max = " << *n_max << std::endl;

	// std::cout << "l'ecart entre les 2 nombres max et min = " << *n_max - *n_min << std::endl;

}

int Span::shortestSpan() const {
	if(_vec.size() < 2)
		throw std::logic_error ("Error! = Size < 2");
	
	std::vector<int> tmp = _vec;

	std::sort(tmp.begin(),tmp.end());
	

	std::vector<int>::iterator it;
	
	int ecart = *(tmp.end() - 1) - *(tmp.begin());
	for(it = tmp.begin() ; it != tmp.end(); ++it) {
		if((it + 1) != tmp.end()) {
			if(ecart > *(it + 1) - *it)
				ecart = *(it + 1) - *it;
		}
	}
	return ecart;
}


int Span::longestSpan() const {
	if(_vec.size() < 2)
		throw std::logic_error ("Error! = Size < 2");
	std::vector<int>::const_iterator min = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator max = std::max_element(_vec.begin(), _vec.end());
	return (*max - *min);
}

Span::~Span() {}
