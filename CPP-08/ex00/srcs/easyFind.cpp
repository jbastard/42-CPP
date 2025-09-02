#include "../includes/easyFind.hpp"

const char* OccurrenceNotFoundException::what() const throw()
{
	return "Occurrence not found in container";
}
