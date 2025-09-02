#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

	class OccurenceNotFoundException : public std::exception{
		public:
			const char* what() const throw();
	};

#include "easyFind.tpp"
