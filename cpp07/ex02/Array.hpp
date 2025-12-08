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
		T& operator=(Array const &other);
		unsigned int size() const;
		~Array();
	private:
		T*           _array;
		unsigned int _size;
};

#include "Array.tpp"

#endif