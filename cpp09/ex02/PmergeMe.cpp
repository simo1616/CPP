#include "PmergeMe.hpp"

PmergeMe::PmergeMe() :_timeVec(0), _timeDec(0){}

//	$> ./PmergeMe 3 5 9 7 4
//	Before: 3 5 9 7 4
//	After: 3 4 5 7 9
//	Time to process a range of 5 elements with std::[..] : 0.00031 us
//	Time to process a range of 5 elements with std::[..] : 0.00014 us
PmergeMe::PmergeMe(int ac, char **av) :_timeVec(0), _timeDec(0){
	std::set<unsigned int> set;
	for(int i = 1; i < ac; i++) {
		char *end;
		errno = 0;

		long input = strtol(av[i], &end, 10);
		unsigned int n = static_cast<unsigned int>(input);
		if	(*end != '\0' || end == av[i] 
			|| input < 0 || errno == ERANGE
			|| input > UINT_MAX
			|| !set.insert(n).second ) {
			std::string str = av[i];
			throw std::runtime_error("Error: invalid input = \"" + str + "\"");
		}
		_vec.push_back(n);
		_dec.push_back(n);
	}
}

PmergeMe::PmergeMe(PmergeMe const &other) 
:_vec(other._vec), _dec(other._dec){}

PmergeMe& PmergeMe::operator=(PmergeMe const &other) {
	if(this != &other) {
		_vec = other._vec;
		_dec = other._dec;
		_timeVec = other._timeVec; 
		_timeDec = other._timeDec;
	}
	return *this;
}

void PmergeMe::displayVec(std::string af_bef) {
	std::cout << af_bef;
	std::vector<unsigned int>::iterator it;
	for(it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	PmergeMe::timeToProcessVec();
	PmergeMe::timeToProcessDec();
}

void PmergeMe::timeToProcessVec() const{
	std::cout 	<< "Time to process a range of " << _vec.size()
				<< " elements with std::vector : "
				<< _timeVec
				<< " us"
				<< std::endl;
}

void PmergeMe::timeToProcessDec() const {
	std::cout 	<< "Time to process a range of " << _dec.size()
				<< " elements with std::decque : "
				<< _timeDec
				<< " us"
				<< std::endl;
}

void PmergeMe::sortVec() {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	// TODO: Appeler l'algorithme de tri ici
	//usleep(0);

	gettimeofday(&end, NULL);
	_timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

PmergeMe::~PmergeMe() {}