#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <exception>


template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other); // Constructeur par copie
		Array& operator=(const Array& other); // Opérateur d'assignation
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;
		~Array();

	private:
		T* _array;
		unsigned int _size;
};

#include "Array.tpp"

#endif