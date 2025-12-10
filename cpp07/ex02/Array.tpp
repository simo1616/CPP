

template <typename T>
Array<T>::Array():_array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0) {
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	T* new_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++) {
		new_array[i] = other._array[i];
	}
	delete[] _array;
	_array = new_array;
	_size = other._size;
	return *this;
}


template <typename T>
unsigned int Array<T>::size() const {return(_size);}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if(index >= _size)
		throw std::out_of_range("Index is out of range");
	return(_array[index]);
}

template <typename T>
const T&  Array<T>::operator[](unsigned int index) const {
	if(index >= _size)
		throw std::out_of_range("Index is out of range");
	return(_array[index]);
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
}
