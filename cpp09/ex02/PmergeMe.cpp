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

		long vec = strtol(av[i], &end, 10);
		unsigned int n = static_cast<unsigned int>(vec);
		if	(*end != '\0' || end == av[i] 
			|| vec < 0 || errno == ERANGE
			|| vec > INT_MAX
			|| !set.insert(n).second ) {
			std::string str = av[i];
			throw std::runtime_error("Error: invalid vec = \"" + str + "\"");
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
	Vector::iterator it;
	for(it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
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
				<< " elements with std::deque : "
				<< _timeDec
				<< " us"
				<< std::endl;
}

static std::vector<size_t> generateJacobsthalIndices(size_t n) {
	std::vector<size_t> indices;
	if (n < 2) return indices;
	size_t prev_jacob = 1;
	size_t curr_jacob = 3;
	while (prev_jacob < n) {
		size_t limit = prev_jacob;
		size_t curr = curr_jacob;
		while (curr > limit) {
			if (curr - 1 < n)
				indices.push_back(curr - 1);
			curr--;
		}
		size_t next = curr_jacob + 2 * prev_jacob;
		prev_jacob = curr_jacob;
		curr_jacob = next;
	}
	return indices;
}

Vector PmergeMe::mergeInsertSort_vec(Vector &vec) {
	if(vec.size() < 2)
		return vec;

	PairVector vec_paire;
	bool is_odd = vec.size() % 2 != 0;
	unsigned int reste = 0;
	if(is_odd) reste = vec.back();

	size_t limit = is_odd ? (vec.size() - 1) : vec.size();
	for(size_t i = 0; i < limit; i += 2) {
		if(vec[i] > vec[i + 1])
			vec_paire.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			vec_paire.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	Vector vec_win;
	for(PairVector::iterator itp = vec_paire.begin(); itp != vec_paire.end(); ++itp) {
		vec_win.push_back(itp->first);
	}

	Vector res = mergeInsertSort_vec(vec_win);
	
	// On garde une copie des winners triés pour retrouver l'ordre d'insertion
	Vector sorted_winners = res;

	// Insertion du partenaire du plus petit winner (res[0])
	for(PairVector::iterator itp = vec_paire.begin(); itp != vec_paire.end(); ++itp) {
		if(itp->first == sorted_winners[0]) {
			res.insert(res.begin(), itp->second);
			vec_paire.erase(itp); // On retire la paire car elle a été traitée
			break;
		}
	}

	std::vector<size_t> jacob_idc = generateJacobsthalIndices(sorted_winners.size());

	for(size_t i = 0; i < jacob_idc.size(); ++i) {
		size_t idx = jacob_idc[i];
		if (idx >= sorted_winners.size()) continue;

		unsigned int val = sorted_winners[idx];
		for(PairVector::iterator itp = vec_paire.begin(); itp != vec_paire.end(); ++itp) {
			if(itp->first == val) {
				// Optimisation Ford-Johnson: on cherche le winner dans res
				// et on borne la recherche du loser uniquement AVANT le winner.
				Vector::iterator it_winner = std::lower_bound(res.begin(), res.end(), val);
				Vector::iterator it_insert = std::lower_bound(res.begin(), it_winner, itp->second);
				res.insert(it_insert, itp->second);
				vec_paire.erase(itp); // On retire la paire car elle a été traitée
				break;
			}
		}
	}

	// Sécurité: insérer les paires restantes si la suite de Jacobsthal a raté des indices
	while (!vec_paire.empty()) {
		PairVector::iterator itp = vec_paire.begin();
		Vector::iterator it_winner = std::lower_bound(res.begin(), res.end(), itp->first);
		Vector::iterator it_insert = std::lower_bound(res.begin(), it_winner, itp->second);
		res.insert(it_insert, itp->second);
		vec_paire.erase(itp);
	}

	if(is_odd) {
		Vector::iterator pos = std::lower_bound(res.begin(), res.end(), reste);
		res.insert(pos, reste);
	}

	return res;
}

Deque PmergeMe::mergeInsertSort_dec(Deque &dec) {
	if(dec.size() < 2)
		return dec;

	PairDeque dec_paire;
	bool is_odd = dec.size() % 2 != 0;
	unsigned int reste = 0;
	if(is_odd) reste = dec.back();

	size_t limit = is_odd ? (dec.size() - 1) : dec.size();
	for(size_t i = 0; i < limit; i += 2) {
		if(dec[i] > dec[i + 1])
			dec_paire.push_back(std::make_pair(dec[i], dec[i + 1]));
		else
			dec_paire.push_back(std::make_pair(dec[i + 1], dec[i]));
	}

	Deque dec_win;
	for(PairDeque::iterator itp = dec_paire.begin(); itp != dec_paire.end(); ++itp) {
		dec_win.push_back(itp->first);
	}

	Deque res = mergeInsertSort_dec(dec_win);
	
	Deque sorted_winners = res;

	for(PairDeque::iterator itp = dec_paire.begin(); itp != dec_paire.end(); ++itp) {
		if(itp->first == sorted_winners[0]) {
			res.insert(res.begin(), itp->second);
			dec_paire.erase(itp);
			break;
		}
	}

	std::vector<size_t> jacob_idc = generateJacobsthalIndices(sorted_winners.size());

	for(size_t i = 0; i < jacob_idc.size(); ++i) {
		size_t idx = jacob_idc[i];
		if (idx >= sorted_winners.size()) continue;

		unsigned int val = sorted_winners[idx];
		for(PairDeque::iterator itp = dec_paire.begin(); itp != dec_paire.end(); ++itp) {
			if(itp->first == val) {
				// Optimisation Ford-Johnson: borne la recherche avant le winner
				Deque::iterator it_winner = std::lower_bound(res.begin(), res.end(), val);
				Deque::iterator it_insert = std::lower_bound(res.begin(), it_winner, itp->second);
				res.insert(it_insert, itp->second);
				dec_paire.erase(itp);
				break;
			}
		}
	}

	// Sécurité pour deque
	while (!dec_paire.empty()) {
		PairDeque::iterator itp = dec_paire.begin();
		Deque::iterator it_winner = std::lower_bound(res.begin(), res.end(), itp->first);
		Deque::iterator it_insert = std::lower_bound(res.begin(), it_winner, itp->second);
		res.insert(it_insert, itp->second);
		dec_paire.erase(itp);
	}

	if(is_odd) {
		Deque::iterator pos = std::lower_bound(res.begin(), res.end(), reste);
		res.insert(pos, reste);
	}

	return res;
}


void PmergeMe::sortVec() {
	struct timeval start, end;
	gettimeofday(&start, NULL);

	_vec = mergeInsertSort_vec(_vec);

	gettimeofday(&end, NULL);
	_timeVec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDec() {
	struct timeval start, end;
	gettimeofday(&start, NULL);

	_dec = mergeInsertSort_dec(_dec);

	gettimeofday(&end, NULL);
	_timeDec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

PmergeMe::~PmergeMe() {}