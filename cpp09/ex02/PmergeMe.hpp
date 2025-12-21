#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <algorithm>
#include <set>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>
#include <iomanip>





typedef std::vector< std::pair<unsigned int, unsigned int> > PairVector;
typedef std::vector<unsigned int> Vector;
typedef std::deque<std::pair<unsigned int, unsigned int> > PairDeque;
typedef std::deque<unsigned int> Deque;


 


class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &other);
		Vector mergeInsertSort_vec(Vector &input);
		Deque mergeInsertSort_dec(Deque &input);
		PmergeMe& operator=(PmergeMe const &other);
		void displayVec(std::string af_bef);
		void timeToProcessVec() const;
		void timeToProcessDec() const;

		void sortVec();
		void sortDec();
		~PmergeMe();

	private:
		Vector _vec;
		Deque _dec;
		double	_timeVec;
		double	_timeDec;
};


#endif