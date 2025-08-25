#pragma once

#include "Colors.hpp"
#include <iostream>

class WrongAnimal {

protected:
	std::string _type;

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();

	WrongAnimal			&operator=(const WrongAnimal &src);

	const std::string&	getType() const;

	void				makeSound() const;
};

std::ostream &operator<<(std::ostream &out, const WrongAnimal &src);