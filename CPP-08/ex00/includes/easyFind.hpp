#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>

	class OccurrenceNotFoundException : public std::exception{
		public:
			const char* what() const throw();
	};

#include "easyFind.tpp"