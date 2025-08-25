#pragma once
#include "Animal.hpp"

#include <iostream>

class Dog : public Animal {

private:

public:

	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog &operator=(const Dog &src);

	void makeSound() const;
};

std::ostream &operator<<(std::ostream &out, const Dog &src);