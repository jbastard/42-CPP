#pragma once
#include "Colors.hpp"

#include <iostream>

class Animal {

protected:
	std::string _type;

public:

	Animal();
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal			&operator=(const Animal &src);

	const			std::string& getType() const;

	virtual void	makeSound() const ;
};

std::ostream &operator<<(std::ostream &out, const Animal &src);