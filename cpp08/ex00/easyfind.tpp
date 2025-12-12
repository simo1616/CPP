


template <typename T>
void easyfind(T &container, int n) {
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), n);
	if(it == container.end()) 
		throw std::runtime_error("Element not found");

	int pos = std::distance(container.begin(), it);

	std::cout << "Element " << *it << " found in position: " << pos << '\n';
}