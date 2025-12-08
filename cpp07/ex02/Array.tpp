

template <typename T>
Array<T>::Array() :_array(NULL), _size(0) { 
	std::cout << "Defaut constructeur.\n";
}


template <typename T>
Array<T>::Array(unsigned int n):_array(new T[n]), _size(n) { 
	std::cout << "ARG(n) constructeur.\n";
}

template <typename T>
Array<T>::Array(Array const &other):_size(other._size) {
	if(!_size)
		_array = NULL;
	else {
		try {
			_array = new T[_size];
		}
		catch(const std::bad_alloc &e) {
			std::cerr << "Error! Allocation of _array :" << e.what() << std::endl;
			delete[] _array;
			throw;
		}
		for(unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
T& Array<T>::operator=(Array const &other) {
	if(this == &other) return *this;
	delete[] _array;
	_size = other._size;
	_array = new T[_size];
	for(unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if(index >= _size)
		throw std::out_of_range("too big");
	return(_array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if(index >= _size)
		throw std::out_of_range("too big");
	return(_array[index]);
}


template <typename T>
unsigned int Array<T>::size() const {
	return(_size);
}

template <typename T>
Array<T>::~Array() { 
	std::cout << "Defaut destructeur.\n"; 
	delete[] _array;
}