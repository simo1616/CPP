

template <typename T>
Array<T>::Array() :bloc(NULL), size_b(0) { 
	std::cout << "Defaut constructeur.\n";
}


template <typename T>
Array<T>::Array(unsigned int n):bloc(new T[n]), size_b(n) { 
	std::cout << "ARG(n) constructeur.\n";
}

template <typename T>
Array<T>::Array(Array const &other):size_b(other.size_b) {
	if(!size_b)
		bloc = NULL;
	else {
		try {
			bloc = new T[size_b];
		}
		catch(const std::bad_alloc &e) {
			std::cerr << "Error! Allocation of bloc :" << e.what() << std::endl;
		}
		for(unsigned int i = 0; i < size_b; i++)
			bloc[i] = other.bloc[i];
	}
}


template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if(index >= size_b)
		throw std::out_of_range("too big");
	return(bloc[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if(index >= size_b)
		throw std::out_of_range("too big");
	return(bloc[index]);
}


template <typename T>
unsigned int Array<T>::size() const {
	return(size_b);
}

template <typename T>
Array<T>::~Array() { 
	std::cout << "Defaut destructeur.\n"; 
}