#include "../includes/easyFind.hpp"

const char* OccurenceNotFoundException::what() const throw()
{
	return "This occurence was not to be found in the container";
}

