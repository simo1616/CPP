

template <typename T>
Array<T>::Array():_array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0) {
	*this = other; // Utilise l'opérateur d'assignation pour éviter la duplication de code
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	// 1. Vérifier l'auto-assignation (ex: a = a;)
	if (this == &other)
		return *this;

	// 2. Allouer une nouvelle mémoire AVANT de supprimer l'ancienne.
	// Si 'new' échoue, l'objet original reste intact.
	T* new_array = new T[other._size];

	// 3. Copier les données dans la nouvelle mémoire
	for (unsigned int i = 0; i < other._size; i++) {
		new_array[i] = other._array[i];
	}

	// 4. Libérer l'ancienne mémoire maintenant que tout s'est bien passé
	delete[] _array;

	// 5. Mettre à jour les membres de l'objet courant
	_array = new_array;
	_size = other._size;

	// 6. Retourner une référence à l'objet courant
	return *this;
}


template <typename T>
unsigned int Array<T>::size() const {return(_size);}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if(index >= _size)
		throw std::out_of_range("INdex is out of range");
	return(_array[index]);
}

template <typename T>
const T&  Array<T>::operator[](unsigned int index) const {
	if(index >= _size)
		throw std::out_of_range("INdex is out of range");
	return(_array[index]);
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
}
