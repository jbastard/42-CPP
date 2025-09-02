#include "easyFind.hpp"

// template <typename T>
// void easyFind(const T& array, int n)
// {
// 	for (int i = 0; i < (int)(sizeof(array)/sizeof(array[0])); i++)
// 	{
// 		if (array[i] == n)
// 		{
// 			std::cout << "Occurence " << n << " has been found at index: " << i << std::endl;
// 			return ;
// 		}
// 	}
// 	throw easyFind::OccurenceNotFoundException();
// }

template <typename T>
typename T::iterator easyFind(T& array, int n)
{
	typename T::iterator it = std::find(array.begin(), array.end(), n);

	if (*it)
		std::cout << "Occurence " << n << " has been found at index " << *it << std::endl;
	return it;
}
