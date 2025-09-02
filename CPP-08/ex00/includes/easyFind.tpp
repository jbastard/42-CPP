#include "easyFind.hpp"

template <typename T>
typename T::iterator easyFind(T& array, int n)
{
	typename T::iterator it = std::find(array.begin(), array.end(), n);

	if (*it)
		std::cout << "Occurence " << n << " has been found at index " << *it << std::endl;
	return it;
}
