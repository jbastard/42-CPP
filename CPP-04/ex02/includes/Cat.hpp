#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>

class Cat : public AAnimal {

private:
	Brain* _brain;

public:

	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat &operator=(const Cat &src);

	void makeSound() const;

	void setIdea(int i, const std::string& s);
	const std::string& getIdea(int i) const;
};

std::ostream &operator<<(std::ostream &out, const Cat &src);