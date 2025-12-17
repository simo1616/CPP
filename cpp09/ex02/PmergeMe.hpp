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








class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &other);
		PmergeMe& operator=(PmergeMe const &other);
		void displayVec(std::string af_bef);
		void timeToProcessVec() const;
		void timeToProcessDec() const;

		void sortVec();
		//void sortDec();
		~PmergeMe();

	private:
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _dec;
		double	_timeVec;
		double	_timeDec;
};


#endif