#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>



template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		
		unsigned int size() const;
		~Array();
	private:
		T *bloc;
		unsigned int size_b;
};

#include "Array.tpp"

#endif