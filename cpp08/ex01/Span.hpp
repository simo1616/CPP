#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <iterator>


class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		void addNumber(int value);
		template <typename Iter>
		void addNumber(Iter begin, Iter end) {
			if(std::distance(begin, end) > static_cast<int> (_n - _vec.size())) {
				throw std::runtime_error ("not enough space");
			}
			_vec.insert(_vec.end(), begin, end);
		}
		int shortestSpan();
		int longestSpan();
		void display();
		~Span();
	private:
		unsigned int _n;
		std::vector<int> _vec;
};

#endif