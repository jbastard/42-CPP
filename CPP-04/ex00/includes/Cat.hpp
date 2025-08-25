#pragma once
#include "Animal.hpp"

#include <iostream>

class Cat : public Animal {

private:

public:

	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat &operator=(const Cat &src);

	void makeSound() const;
};

std::ostream &operator<<(std::ostream &out, const Cat &src);