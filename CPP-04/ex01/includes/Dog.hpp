#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

class Dog : public Animal {

private:
	Brain* _brain;

public:

	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog &operator=(const Dog &src);

	void makeSound() const;

	void setIdea(int i, const std::string& s);
	const std::string& getIdea(int i) const;
};

std::ostream &operator<<(std::ostream &out, const Dog &src);